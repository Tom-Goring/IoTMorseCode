# IoTMorseCode
Assignment 2 of IoT - getting two MicroBits to communicate with morse.

## Getting Started

You will need the full dir of MicroBit headers + mbed.h and associated in order
to build. These can be obtained in multiple ways (mostly by googling how).

In order to compile and load onto a MicroBit, you should just be able to run 
"make" on a linux terminal from the pacman dir (the one with the MakeFile). 

You WILL need to edit the MICROBIT_PATH & MICROBIT_PATH1 variables in the MakeFile to whatever dir
path your MicroBits reside on, or change it to just one variable if you want to flash them on at
 a time. For me this variable is:

    /media/tom/MICROBIT

however this can vary depending on environment.

If this does not for some reason work, the source file "main.cpp" can be copied
into a new or pre-existing project and compiled using yotta with the following:

1. Ensure header files exist.
2. CD to dir that would contain MakeFile.
2. Set target using "yt target bbc-microbit-classic-gcc".
3. Build with "yt build".

The source file should in theory work when just copy pasted into the src dir
of a different MicroBit project.

You will need two MicroBits in order to make this code function. They should both be connected to power, have
one crocodile clip between P1, and one crocodile clip between their ground pins. An image of this can be seen here:



## Protocol

Upon initialisation, both MicroBits will be assigned to receiving mode. Pressing the B button will switch one into
sending mode. A 1 will display upon entering sending mode, and a 0 will display upon entering receiving mode.
If both are in the same mode, nothing will happen.

When one is in sending mode, and the other is in receiving mode, messages can be passed from one to the other.
The two can switch at any time.

The sending MicroBit must have `Button A`  held down for the duration of a dit or dash continuously until all dits
and dashes have been entered, at which point the button should be released. After a second, the other MicroBit
will receive the character corresponding to the entered message.

The letter will be sent as a caesar ciphered letter, 3 shifted to the left, but will be decoded before it is displayed.