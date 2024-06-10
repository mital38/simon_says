# simon_says
ENGR 103 Final Project Game


Simon Says (Sequence memory Game)
Game Description:
Based off: https://humanbenchmark.com/tests/sequence


When the game starts a sequence of random LEDs will light up for one second each depending on level. This is like a video sequence playing before taking user inputs. The player needs to memorize which LED plays in each order. The arduino then lights up one LED, this selected LED can move around the circle with left and right buttons. The player then repeats the sequence by moving to the LED that was lit up and then shaking the board to enter selected sequence. Sound will play if the selected sequence is wrong then the game is over and the game does not proceed, use the switch to restart the game, if it is right with the sequence then it starts the next level which will have the same sequence with one more LED.

If switch is deactivated, the game starts up. A sequence of random leds flashing purple, indicates the led you shall press, in the order in which youve seen. After the sequence is done, a white led flashes on the board, this is the led you can control around the board, and then selecting the correct led in which the purple was played in the correct sequence. Use the left and right button to control the board. You must enter each led one at a time in the sequence that you saw, shake the board to enter the led you have selected. If the led you selected was wrong, or was in the wrong sequence, the board will light up red following a deep sound, indicating that the game is over and you must restart. If the led sequence you entered was correct, the game shall light up green following a lighter sound, indicatong that you're continuing to the next level. The game is infinite but will end once you get it wrong. 


User inputs/outputs definition sheet:
| Input                          | Function                                                           | Output |
| ------------- | ------------------------------ | ------------------------------------------------------------------ |
| Left Button                |  Move selected LED to left                                   |  LED Lights up, index array changes                                                                                                  |
| Right Button               |  Move selected LED to right                                  |  LED lights up, index array changes                                                                                                  |
| Accelerometer              |  “Selects” user input sequence                               |  Compares user input to original. Temporary sound will play. |
| Switch                     |  Resets game                                                 | Exits loop if turned off, restarts game when turned on (interrupt)                                                                   |

Scoring system: serial print score starting from 0 and will gain 1 point every time a correct sequence is entered and the next level is reached. 
State Machine:
