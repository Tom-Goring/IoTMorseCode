//
// Created by tom on 19/02/19.
//

#ifndef IOT_CHALLENGE_TWO_DEF_H
#define IOT_CHALLENGE_TWO_DEF_H

#include "map"
#include "string"

#define SENDER 's'
#define RECEIVER 'r'

void waitForRoleSelection();
void setRole(char role);
void executeRoleDuties();
void executeSenderProtocol();
void executeReceiverProtocol();

MicroBit uBit;

MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_A);

uint64_t t_reading, t_delta;
bool pressed = false;

char role = '\0';

std::map<std::string, char> morse_to_char = {
        {".-", 'A'},
        {"-...", 'B'},
        {"-.-.", 'C'},
        {"-..", 'D'},
        {".", 'E'},
        {"..-.", 'F'},
        {"--.", 'G'},
        {"....", 'H'},
        {"..", 'I'},
        {".---", 'J'},
        {"-.-", 'K'},
        {".-..", 'L'},
        {"--", 'M'},
        {"-.", 'N'},
        {"---", 'O'},
        {".--.", 'P'},
        {"--.-", 'Q'},
        {".-.", 'R'},
        {"...", 'S'},
        {"-", 'T'},
        {"..-", 'U'},
        {"...-", 'V'},
        {".--", 'W'},
        {"-..-", 'X'},
        {"-.--", 'Y'},
        {"--..", 'Z'},
        {"-----", '0'},
        {".----", '1'},
        {"..---", '2'},
        {"...--", '3'},
        {"....-", '4'},
        {".....", '5'},
        {"-....", '6'},
        {"--...", '7'},
        {"---..", '8'},
        {"----.", '9'}
};

#endif //IOT_CHALLENGE_TWO_DEF_H


