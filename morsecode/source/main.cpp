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

    if (role == SENDER)
        uBit.display.print("SENDER");
    if (role == RECEIVER)
        uBit.display.print("RECEIVER");

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

        t_reading = system_timer_current_time();

        while (buttonA.isPressed()) {

            pressed = true;
        }

        t_delta = system_timer_current_time() - t_reading;

        if (pressed) {

            if (t_delta > 50 && t_delta < 350) {

                uBit.serial.printf(".");
                morse_character->push_back('.');
            }
            else if (t_delta > 350 && t_delta < 600) {

                uBit.serial.printf("-");
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


}
