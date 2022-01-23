**Physical/Virtual Hardware Needed:**

1. 8051 Board.
2. 16*2 LCD display.
3. 6 Switches.

**Software/Compiler Dependencies:**

Kiel 4.0/5.0 to compile and generate the 8051 hex code.
**Step 1:**

Load the folder into the kiel IDE and compile the code. Refer https://www.keil.com/c51/ to download and setup up the environment.

**Step 2:**

Once the hex code is generated, load the 8051 board/simulator and make all the connections with respect to pin number assigned in the header file.

That's it, Now restart the board if it's physical one. The code will start executing.

**Direction of Use:**

Switch-0 : press to move cursor position.
Switch-1 : press to show the next character.
Switch-2 : press to show the previous character.
Switch-3 : press to have space as a character.
Switch-4 : press to reset the character/number.
Switch-5 : press to move the setting to input delay. Here Switch-3 and Switch-4 doesn't work. Press once again the Switch-5 after delay input, now the string that is given as input will start to execute with required delay in between.
