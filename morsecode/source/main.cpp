#include "MicroBit.h"
#include <map>
#include "defs.h"

#define SENDER true
#define RECEIVER false

MicroBit ubit;
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitPin pin(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1, PIN_CAPABILITY_DIGITAL);

uint64_t start_time;
uint64_t signal_duration = 0;

std::string morse;

bool mode = RECEIVER;
bool signal_received = false;
bool endOfLetter;

void switchMode(MicroBitEvent);
void receiverProtocol();
void detectEndOfLetterPin();
void senderProtocol();
void detectEndOfLetterButton();

int main() {

    ubit.init();
    ubit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, switchMode);

    for (;;) {

        ubit.serial.printf("mode: %d\n", mode);

        if (mode == RECEIVER) {

            receiverProtocol();
        }
        else {

            senderProtocol();
        }


        ubit.sleep(100);
    }
}

void switchMode(MicroBitEvent) {

    morse.clear();
    mode = !mode;
    ubit.display.print(mode);
    ubit.sleep(500);
    ubit.display.clear();
}

void receiverProtocol() {

    ubit.serial.printf("executing receiver protocol\n");

    start_time = 0;
    signal_duration = 0;

    start_time = system_timer_current_time();

    create_fiber(detectEndOfLetterPin);

    while (pin.getDigitalValue()) {

        signal_received = true;
    }

    signal_duration = system_timer_current_time() - start_time;

    if (signal_received) {

        if (signal_duration > 0 && signal_duration < 200) {

            ubit.display.print(".");
            morse.append(".");
            ubit.sleep(30);
        }
        else if (signal_duration > 200 && signal_duration < 500) {

            ubit.display.print("-");
            morse.append("-");
            ubit.sleep(30);
        }
        else if (endOfLetter) {

            ubit.sleep(100);

            if (morse.size() != 0) {

                ubit.serial.printf("%c\n", morseToChar(morse));
                ubit.display.print(morseToChar(morse));
                ubit.sleep(500);
            }

            morse.clear();
            endOfLetter = false;
        }
    }

    ubit.display.clear();
    ubit.sleep(50);
}

void detectEndOfLetterPin() {

    endOfLetter = false;
    uint64_t start_time;
    uint64_t signal_non_duration;

    start_time = system_timer_current_time();

    while (!pin.getDigitalValue() && !endOfLetter) {

        signal_non_duration = system_timer_current_time() - start_time;

        if (signal_non_duration > 1500) {

            endOfLetter = true;
        }

        ubit.sleep(10);
    }
}

void senderProtocol() {

    if (buttonA.isPressed()) {

        pin.setDigitalValue(1);
    }
    else {

        pin.setDigitalValue(0);
    }

    /*ubit.serial.printf("executing sender protocol\n");

    start_time = 0;
    signal_duration = 0;
    signal_received = false;

    start_time = system_timer_current_time();

    create_fiber(detectEndOfLetterButton);

    ubit.serial.printf("before button check\n");

    while (buttonA.isPressed()) {

        signal_received = true;
    }

    signal_duration = system_timer_current_time() - start_time;

    if (signal_received) {

        ubit.serial.printf("signal received\n");

        if (signal_duration > 0 && signal_duration < 200) {

            ubit.display.print(".");
            morse.append(".");
            ubit.sleep(30);
        }
        else if (signal_duration > 200 && signal_duration < 500) {

            ubit.display.print("-");
            morse.append("-");
            ubit.sleep(30);
        }
        else if (endOfLetter) {

            ubit.sleep(100);

            if (morse.size() != 0) {

                ubit.serial.printf("%c\n", morseToChar(morse));
                ubit.display.print(morseToChar(morse));
                ubit.sleep(500);
            }
        }

        morse.clear();
        endOfLetter = false;
    }

    ubit.display.clear();
    ubit.sleep(50);*/
}

/*void detectEndOfLetterButton() {

    endOfLetter = false;
    uint64_t start_time;
    uint64_t signal_non_duration;

    start_time = system_timer_current_time();

    while (!buttonA.isPressed() && !endOfLetter) {

        signal_non_duration = system_timer_current_time() - start_time;

        if (signal_non_duration > 1500) {

            endOfLetter = true;
        }

        ubit.sleep(10);
    }
}*/
