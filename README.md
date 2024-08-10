# cbb-project
Creating a prototype for a microcontroller to be attached to an assembly line. that will receive data from the employees working on the line and will collect production statistics from the assembly line itself. This was first done with an Arduino UNO, then was changed to an ESP32 (NodeMCE-32s). This change was made for the wifi ability of the esp32. The reason the wifi capability was necessary in this project was because of real-time data transfers. The esp32 is able to send data directly from the line to a sql server that is used to display the data. 
