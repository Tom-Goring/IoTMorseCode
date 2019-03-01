#include "MicroBit.h"
#include "Cipher.h"

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
void sendMorse(std::string morseToSend);
int getCharacterPauseDuration(char letter);

int main() {

    ubit.init();
    ubit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, switchMode);

    for (;;) {

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

    start_time = 0;
    signal_duration = 0;

    start_time = system_timer_current_time();

    create_fiber(detectEndOfLetterPin);

    while (pin.getDigitalValue()) {

        signal_received = true;
    }

    signal_duration = system_timer_current_time() - start_time;

    if (signal_received) {

        if (signal_duration > 150 && signal_duration < 300) {

            ubit.display.print(".");
            morse.append(".");
        }
        else if (signal_duration > 300 && signal_duration < 600) {

            ubit.display.print("-");
            morse.append("-");
        }
    }

    if (endOfLetter) {

        ubit.sleep(100);

        if (morse.size() != 0) {

            ubit.serial.printf("%c\n", morseToChar(morse));
            ubit.display.print(morseToChar(morse));
            ubit.sleep(500);
        }

        morse.clear();
        endOfLetter = false;
    }

    ubit.display.clear();
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

    start_time = 0;
    signal_duration = 0;
    signal_received = false;

    start_time = system_timer_current_time();

    create_fiber(detectEndOfLetterButton);

    while (buttonA.isPressed()) {

        signal_received = true;
    }

    signal_duration = system_timer_current_time() - start_time;

    if (signal_received) {

        if (signal_duration > 150 && signal_duration < 300) {

            ubit.display.print(".");
            morse.append(".");
            ubit.sleep(100);
            ubit.display.clear();
        }
        else if (signal_duration > 300 && signal_duration < 600) {

            ubit.display.print("-");
            morse.append("-");
            ubit.sleep(100);
            ubit.display.clear();
        }
    }

    if (endOfLetter) {

        if (morse.size() != 0 && morseToChar(morse) != '!') {

            char morseAsChar = morseToChar(morse);
            char encryptedChar = encryptChar(morseAsChar);

            std::string encryptedMorse = charToMorse(encryptedChar);
            sendMorse(encryptedMorse);
        }

        morse.clear();
        endOfLetter = false;
    }

    ubit.sleep(50);
}

void detectEndOfLetterButton() {

    endOfLetter = false;
    uint64_t start_time;
    uint64_t signal_non_duration;

    start_time = system_timer_current_time();

    while (!buttonA.isPressed() && !endOfLetter) {

        signal_non_duration = system_timer_current_time() - start_time;

        if (signal_non_duration > 1000) {

            endOfLetter = true;
        }

        ubit.sleep(10);
    }
}

void sendMorse(std::string morseToSend) {

    for (char elem : morseToSend) {

        ubit.serial.printf("sending: %c\n", elem);

        pin.setDigitalValue(1);
        ubit.sleep(getCharacterPauseDuration(elem));
        pin.setDigitalValue(0);
        ubit.sleep(50);
    }

    pin.setDigitalValue(0);
}

int getCharacterPauseDuration(char letter) {

    if (letter == '.') {

        return 225;
    }
    else if (letter == '-') {

        return 450;
    }
}
