//
// Created by tom on 19/02/19.
//

#include "Cipher.h"

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

Cipher::Cipher() {}

Cipher::~Cipher() {}

Morse Cipher::encrypt(char letter) {

    letter = letter ^ key[0] ^ key[1] ^ key[2];
    Morse morse = charToMorse(letter);
    return morse;
}

char Cipher::decrypt(Morse morse) {

    return morseToChar(morse) ^ key[0] ^ key[1] ^ key[2];
}

char Cipher::morseToChar(Morse morse) {

    string* morseString = new string(morse->begin(), morse->end());
    char letter = morse_to_char[*morseString];
    delete morseString;
    return letter;
}

Morse Cipher::charToMorse(const char letter) {

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