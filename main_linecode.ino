//the error in displaying the first number is attempint to
//perform ascii math upon an alphabetic character

#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char len[4];
char code[4];
int i = 0;
int b = 0;
long duration;
int distance;

const byte ROW = 4, COL = 4;
char keypad[ROW][COL] = { //setting upthe layout for the key inputs
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pins_rows[ROW] = {6, 7, 8, 9}; //input pins position related to rows
byte pins_columns[COL] = {10, A0, A1, A2}; //input pins related to cols
Keypad kpd = Keypad(makeKeymap(keypad), pins_rows, pins_columns, ROW, COL);

void setup() {
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  i = 0;
  char wrong; //variable for restarting
  char part[20]; //variable for part
  int part_len = 0;//used to convert the string to an int
  char rck[4];
  int racks_left;


  ////////////////////////////////////////////////////
  ////////////////////PART NUMBER CODE/////////////////
  /////////////////////////////////////////////////////
  //pt 1
  do { //loop that restarts if there was an error in the first number
    i = 0;
    char part[20];
    lcd.setCursor(0, 0);
    lcd.print("enter length:");
    lcd.setCursor(0, 1);
    do { //getting input for the first number in the length
      len[i] = kpd.getKey();
    } //keep searching until it meets the appropriate field
    while (strlen(len) < 1 || len[i] == 'A' || len[i] == 'B' || len[i] == 'C' || len[i] == 'D' || len[i] == '*' || len[i] == '#');
    code[i] = len[i];
    lcd.print(code[i]); //print first number
    lcd.leftToRight();
    i++;
    do { //getting input for the second number in the length
      len[i] = kpd.getKey();
    }//keep searching until it meets the appropriate field
    while (strlen(len) < 2 || len[i] == 'A' || len[i] == 'B' || len[i] == 'C' || len[i] == 'D' || len[i] == '*');
    if (len[i] == '#') { //case: the part number is the length of a single digit(1-9)
      lcd.clear();
      lcd.print("length recieved");
      lcd.setCursor(0, 1);
      lcd.print(len[0]); //show the number the computer registered
      part_len = code[0] - '0';//converting the char to an int by doing ascii stuff i wont detail
    }
    else { //case:the part number is a double digit number (10-99)
      code[i] = len[i];
      lcd.print(code[i]); //printing the second number
      delay(2000);
      lcd.clear();
      lcd.print("length recieved:");
      lcd.setCursor(0, 1);
      lcd.print(code); //showing number computer registered
      part_len = (code[0] - '0') * 10; // again doing ascii math to get the int
      part_len = part_len + (code[1] - '0'); // see abv
    }
    delay(3000);
    lcd.clear();
    lcd.print("yes -press 1"); //if correct press 1
    lcd.setCursor(0, 1);
    lcd.print("no -press 2"); //if wrong press 2
    do {
      wrong = kpd.getKey(); // get input from previous prompt
    } //repeat until one of the options is entered
    while (wrong != '1' && wrong != '2');
    lcd.clear();
  } while (wrong == '2'); // if the number was 2 then restart the program

  //pt 2

  lcd.print("enter part#:");
  lcd.setCursor(0, 1);
  for (i = 0; i < part_len + 3; i++) { //this loop might be confusing, see bottom of code.
    do { //allows for input from keypad
      part[i] = kpd.getKey();
    } while (part[i] == NULL); //while there isnt input dont leave loop
    if (i > 2) { //when i gets to 3 from 0 start testing for the 4 character sequence
      if (part[i - 3] == '1' && part[i - 2] == '1' && part[i - 1] == '1' && part[i] == '1')
      { //the below is the same for all sequences so will only be explained once
        lcd.setCursor(i - 2, 1); //set cursor one behind
        lcd.print(" "); //"delete" the space
        lcd.setCursor(i - 1, 1); // set cursor 2 behind
        lcd.print(" "); //"delete" the space
        i = i - 3; //set 'i' back to its original position
        part[i] = 'E'; //replace with the letter
        lcd.setCursor(i, 1); //set the cursor back to 'i'
        lcd.print(part[i]); //print the replacement
      }
      else if (part[i - 3] == '2' && part[i - 2] == '2' && part[i - 1] == '2' && part[i] == '2')
      {
        lcd.setCursor(i - 2, 1);
        lcd.print(" ");
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        i = i - 3;
        part[i] = 'G';
        lcd.setCursor(i, 1);
        lcd.print(part[i]);
      }
      else if (part[i - 3] == '3' && part[i - 2] == '3' && part[i - 1] == '3' && part[i] == '3')
      {
        lcd.setCursor(i - 2, 1);
        lcd.print(" ");
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        i = i - 3;
        part[i] = 'H';
        lcd.setCursor(i, 1);
        lcd.print(part[i]);
      }
      else if (part[i - 3] == '4' && part[i - 2] == '4' && part[i - 1] == '4' && part[i] == '4')
      {
        lcd.setCursor(i - 2, 1);
        lcd.print(" ");
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        i = i - 3;
        part[i] = 'I';
        lcd.setCursor(i, 1);
        lcd.print(part[i]);
      }
      else if (part[i - 3] == '5' && part[i - 2] == '5' && part[i - 1] == '5' && part[i] == '5')
      {
        lcd.setCursor(i - 2, 1);
        lcd.print(" ");
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        i = i - 3;
        part[i] = 'L';
        lcd.setCursor(i, 1);
        lcd.print(part[i]);
      }
      else if (part[i - 3] == '6' && part[i - 2] == '6' && part[i - 1] == '6' && part[i] == '6')
      {
        lcd.setCursor(i - 2, 1);
        lcd.print(" ");
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        i = i - 3;
        part[i] = 'N';
        lcd.setCursor(i, 1);
        lcd.print(part[i]);
      }
      else if (part[i - 3] == '7' && part[i - 2] == '7' && part[i - 1] == '7' && part[i] == '7')
      {
        lcd.setCursor(i - 2, 1);
        lcd.print(" ");
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        i = i - 3;
        part[i] = 'S';
        lcd.setCursor(i, 1);
        lcd.print(part[i]);
      }
      else if (part[i - 3] == '8' && part[i - 2] == '8' && part[i - 1] == '8' && part[i] == '8')
      {
        lcd.setCursor(i - 2, 1);
        lcd.print(" ");
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        i = i - 3;
        part[i] = 'T';
        lcd.setCursor(i, 1);
        lcd.print(part[i]);
      }
      else if (part[i - 3] == '9' && part[i - 2] == '9' && part[i - 1] == '9' && part[i] == '9')
      {
        lcd.setCursor(i - 2, 1);
        lcd.print(" ");
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        i = i - 3;
        part[i] = 'U';
        lcd.setCursor(i, 1);
        lcd.print(part[i]);
      }
      else if (part[i - 3] == '0' && part[i - 2] == '0' && part[i - 1] == '0' && part[i] == '0')
      {
        lcd.setCursor(i - 2, 1);
        lcd.print(" ");
        lcd.setCursor(i - 1, 1);
        lcd.print(" ");
        i = i - 3;
        part[i] = 'V';
        lcd.setCursor(i, 1);
        lcd.print(part[i]);
      }
      else if (part[i] == '*')
      {
        part[i] = 'W'; //replace with a 'W'
        lcd.print(part[i]); //print
      }
      else if (part[i] == '#') {
        i = i + 3; //if a # is entered terminate the loop.
      }
      else
      {
        lcd.print(part[i]); //if its just a normal character
      }//end of nested 'if' statement
    }
    else if (part[i] == '#') {
      i = i + 3;
    }
    else {
      lcd.print(part[i]);//before the 3rd 'i' just printing
    }
    //lcd.leftToRight();
  }
  lcd.clear();
  delay(2000);

  //part 3
  //asking rack info

  i = 0;
  lcd.print("How many racks?");

  do {
    rck[i] = kpd.getKey();
  } while (rck[i] == '\0' || rck[i] == 'A' || rck[i] == 'B' || rck[i] == 'C' || rck[i] == 'D' || rck[i] == '*' || rck[i] == '#');

  lcd.setCursor(0, 1);
  lcd.print(rck[i]);
  i++;
  lcd.leftToRight();

  // Get second digit if needed
  if (i < 3) {
    do {
      rck[i] = kpd.getKey();
    } while (rck[i] == '\0' || rck[i] == 'A' || rck[i] == 'B' || rck[i] == 'C' || rck[i] == 'D' || rck[i] == '*');

    if (rck[i] == '#') { // if the rack input ends after one digit
      lcd.clear();
      lcd.print("Racks received:");
      lcd.setCursor(0, 1);
      lcd.print(rck[0]); // Show the number the computer registered
      racks_left = rck[0] - '0'; // Convert char to int
      Serial.println(racks_left);
    } else {
      lcd.print(rck[i]); // Printing the second number
      i++;
      // Get third digit if needed
      if (i < 3) {
        do {
          rck[i] = kpd.getKey();
        } while (rck[i] == '\0' || rck[i] == 'A' || rck[i] == 'B' || rck[i] == 'C' || rck[i] == 'D' || rck[i] == '*');

        if (rck[i] == '#') { // if it's confirmed 2 digits
          lcd.clear();
          lcd.print("Racks received:");
          lcd.setCursor(0, 1);
          lcd.print(rck); // Show the number the computer registered
          racks_left = (rck[0] - '0') * 10 + (rck[1] - '0'); // Convert char to int
          Serial.println(racks_left);
        } else { // If it's 3 digits
          lcd.print(rck[i]); // Printing the third number
          delay(2000);
          lcd.clear();
          lcd.print("Racks received:");
          lcd.setCursor(0, 1);
          lcd.print(rck); // Show the number the computer registered
          racks_left = (rck[0] - '0') * 100 + (rck[1] - '0') * 10 + (rck[2] - '0'); // Convert char to int
          Serial.println(racks_left);
        }
      }
    }
  }


  delay(2000);
  lcd.clear();
  lcd.print("Starting sensor");
  delay(2000);
  lcd.clear();
  lcd.print("product count:");
  lcd.setCursor(0, 1);
}

void loop() {

  ///////////////////////////////////////////////////////////
  ////////////////////MOTION SENSOR CODE/////////////////////
  ///////////////////////////////////////////////////////////

  //the motion sensor will ideally be placed inside the extruder and fixed near the saw.
  //The sensor will detect when the saw moves down, then will wait until the saw is back
  //in its original position before the delay ends, causing the PIR to search again.
  digitalWrite(A4, LOW);
  delayMicroseconds(2);

  digitalWrite(A4, HIGH);
  delayMicroseconds(10);
  digitalWrite(A4, LOW);

  duration = pulseIn(A5, HIGH);
  distance = duration * 0.034 / 2;
  delay(200);
  if (distance < 15) {
    lcd.setCursor(0, 1);
    b++;
    lcd.print(b);
    delay(15000);
  }
  //the below code wis from when the PIR motion sensor was in use
  //Not getting rid of it just yet in case a switch back is necessary
  //  int a = digitalRead(A5); //reading from sensor
  //  Serial.println(a);
  //  if (a==HIGH)
  //  {
  //    b++;
  //  lcd.setCursor(0, 1);
  //  lcd.print(b);
  //  delay(1000); //delay should be fixed to adjust for the time it takes the sawing to be complete
  //  }
}

//the 'for' loop runs for the length of the part +3 so that
//the opportunity to use the number sequence below is still
//provided, since it requires a sequence of 4 characters
//for 1 letter. Each iteration fills one space of variable
//'part'
