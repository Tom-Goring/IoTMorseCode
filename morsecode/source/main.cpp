//
// Created by tom on 19/02/19.
//

#include <MicroBit.h>
#include "defs.h"
#include "Cipher.h"

extern MicroBit uBit;

MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);

MicroBitPin P1(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1, PIN_CAPABILITY_DIGITAL);

uint64_t t_reading, t_delta;
bool pressed = false;

char role = '\0';

int main() {

    uBit.init();
    waitForRoleSelection();
    executeRoleDuties();
}

void waitForRoleSelection() {

    while (role == '\0') {

        uBit.display.print("@");

        if (buttonA.isPressed())
            setRole(SENDER);

        if (buttonB.isPressed())
            setRole(RECEIVER);

        uBit.sleep(50);
    }
}

void setRole(char roleToSet) {

    role = roleToSet;
}

void executeRoleDuties() {

    while (true) {

        if (role == SENDER) {

            executeSenderProtocol();
        }
        else {

            executeReceiverProtocol();
        }
    }
}

void executeSenderProtocol() {

    Morse morse;

    uBit.sleep(200);

    while (true) {

        uBit.display.print(">");

        t_reading = system_timer_current_time();

        while (buttonA.isPressed()) {

            pressed = true;
        }

        t_delta = system_timer_current_time() - t_reading;

        if (pressed) {

            if (t_delta > 50 && t_delta < 350) {

                uBit.display.print(".");
                uBit.sleep(250);
                morse->push_back('.');
            }
            else if (t_delta > 350 && t_delta < 600) {

                uBit.display.print("-");
                uBit.sleep(250);
                morse->push_back('-');
            }
            else if (t_delta > 600 && t_delta < 1000) {

                uBit.serial.send("");
            }
            else if (t_delta > 1000) {

                char letter = Cipher::morseToChar(morse);

                uBit.serial.printf("%c\n", letter);

                morse = Cipher::encrypt(letter);

                uBit.serial.printf("%c\n", Cipher::morseToChar(morse));

                for (int i = 0; i < morse->size(); ++i) {

                    uBit.serial.printf("%c", morse->at(i));
                }

                morse->clear();
            }
        }

        pressed = false;
        uBit.sleep(100);
    }
}

void executeReceiverProtocol() {

    Morse morse;
    bool high = false;

    uBit.sleep(200);

    while (true) {

        uBit.display.print("<");

        t_reading = system_timer_current_time();

        while (P1.getDigitalValue()) {

            high = true;
            t_delta = system_timer_current_time() - t_reading;

            if (t_delta > 50 && t_delta < 350) {

                uBit.display.print(".");
            }
        }

        if (high) {

            if (t_delta > 50 && t_delta < 350) {

                morse->push_back('.');
            }
            else if (t_delta > 350 && t_delta < 600) {

                morse->push_back('-');
            }
            else if (t_delta > 1000) {

               char letter = uBit.serial.read();
               morse = Cipher::encrypt(letter);
               letter = Cipher::decrypt(morse);
               uBit.display.print(letter);
               uBit.sleep(1000);
            }
        }
    }
}

void sendLetter(char letter, uint32_t pause_duration) {

    P1.setDigitalValue(true);
    uBit.sleep(pause_duration);
    P1.setDigitalValue(false);
}
