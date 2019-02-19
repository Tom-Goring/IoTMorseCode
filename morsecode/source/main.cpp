//
// Created by tom on 19/02/19.
//

#include "MicroBit.h"
#include "defs.h"


int main() {

    uBit.init();
    setupRole();

    while (true) {

        if (role == SENDER) {

            executeSenderProtocol();
        }
    }
}

void setupRole() {

    while (role == '\0') {

        uBit.display.print("SELECT");

        if (buttonA.isPressed())
            setRole(SENDER);

        if (buttonB.isPressed())
            setRole(RECIEVER);

        uBit.sleep(50);
    }
}

void setRole(char roleToSet) {

    role = roleToSet;
}

void executeSenderProtocol() {


}