//
// Created by tom on 19/02/19.
//

#include "Cipher.h"
#include "MicroBit.h"

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

MicroBit uBit;

Cipher::Cipher() {}

Cipher::~Cipher() {}

Morse Cipher::encrypt(char letter) {

    uBit.serial.printf("Before encrypt: %c\n", letter);

    switch (letter) {

        case 'A': return charToMorse('X');
        case 'B': return charToMorse('Y');
        case 'C': return charToMorse('Z');
        case '0': return charToMorse('7');
        case '1': return charToMorse('8');
        case '2': return charToMorse('9');
        default : return charToMorse(letter - 3);
    }
}

char Cipher::decrypt(Morse morse) {

    char letter = morseToChar(morse);

    uBit.serial.printf("Before decrypt: %c\n", letter);

    switch (letter) {

        case 'X': return 'A';
        case 'Y': return 'B';
        case 'Z': return 'C';
        case '7': return '0';
        case '8': return '1';
        case '9': return '2';
        default : return letter + 3;
    }
}

char Cipher::morseToChar(Morse morse) {

    string* morseString = new string(morse->begin(), morse->end());
    char letter = morse_to_char[*morseString];

    if (letter == '\0') {

        return '!';
    }

    delete morseString;
    return letter;
}

Morse Cipher::charToMorse(char letter) {

    uBit.serial.printf("charToMorse");

    string morseString = getKey(letter);

    Morse morse;

    for (auto i = 0; i < morseString.length(); ++i) {

        morse->push_back(morseString[i]);
    }

    return morse;
}

string Cipher::getKey(char letter) {

    for (auto elem : morse_to_char) {

        if (elem.second == letter)
            return elem.first;
    }

    return NULL;
}