//
// Created by tom on 19/02/19.
//

#include <vector>
#include "MicroBit.h"
#include "defs.h"


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

    std::vector<char> *morse_character = new vector<char>;

    while (true) {

        uBit.display.print(">");

        t_reading = system_timer_current_time();

        while (buttonA.isPressed()) {

            pressed = true;
        }

        t_delta = system_timer_current_time() - t_reading;

        if (pressed) {

            if (t_delta > 50 && t_delta < 350) {

                uBit.serial.printf(".");
                uBit.display.print(".");
                morse_character->push_back('.');
            }
            else if (t_delta > 350 && t_delta < 600) {

                uBit.serial.printf("-");
                uBit.display.print("-");
                morse_character->push_back('-');
            }
            else if (t_delta > 600 && t_delta < 1000) {

                uBit.serial.send("");
            }
            else if (t_delta > 1000) {

                // encrypt letter
                // send letter
                // clear letter

                uBit.serial.printf("\n");

                for (int i = 0; i < morse_character->size(); ++i) {

                    uBit.serial.printf("%c", morse_character->at(i));
                    uBit.display.print(morse_character->at(i));
                    uBit.sleep(250);
                    uBit.display.clear();
                    uBit.sleep(100);
                }

                uBit.serial.printf("\n");
                morse_character->clear();
            }
        }

        pressed = false;
        uBit.sleep(100);
    }
}


void executeReceiverProtocol() {

    std::vector<char> *morse_character = new vector<char>;
    bool high = false;

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

                morse_character->push_back('.');
            }
            else if (t_delta > 350 && t_delta < 600) {

                morse_character->push_back('-');
            }
            else if (t_delta > 1000) {

                // decode and display char
            }
        }
    }
}
