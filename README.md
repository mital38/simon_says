# simon_says
ENGR 103 Final Project Game


Simon Says (Sequence memory Game)
Game Description:
Based off: https://humanbenchmark.com/tests/sequence


When the game starts a sequence of random LEDs will light up for one second each depending on level. This is like a video sequence playing before taking user inputs. The player needs to memorize which LED plays in each order. The arduino then lights up one LED, this selected LED can move around the circle with left and right buttons. The player then repeats the sequence by moving to the LED that was lit up and then shaking the board to enter selected sequence. Sound will play if the selected sequence is wrong then the game is over and the game does not proceed, use the switch to restart the game, if it is right with the sequence then it starts the next level which will have the same sequence with one more LED.


User inputs/outputs definition sheet:
Input
Function
Output
Left Button
Move selected LED to left
LED Lights up, index array changes
Right Button
Move selected LED to right
LED lights up, index array changes
Accelerometer
“Selects” user input sequence
Compares user input to original
Switch




Resets game
Exits loop if turned off, restarts game when turned on (interrupt)




Sound will play if sequence is wrong

 




Scoring system: serial print score starting from 0 and will gain 1 point every time a correct sequence is entered and the next level is reached. 
State Machine:
