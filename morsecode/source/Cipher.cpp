#include <string>
#include <map>

std::map<std::string, char> morseMap = {
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

char encryptChar(char charToEncrypt) {

    switch (charToEncrypt) {

        case 'A': return 'X';
        case 'B': return 'Y';
        case 'C': return 'Z';
        case '0': return '7';
        case '1': return '8';
        case '2': return '9';
        default: return charToEncrypt - 3;
    }
}

char decryptChar(char charToDecrypt) {

    switch (charToDecrypt) {

        case 'X': return 'A';
        case 'Y': return 'B';
        case 'Z': return 'C';
        case '7': return '0';
        case '8': return '1';
        case '9': return '2';
        default : return charToDecrypt + 3;
    }
}

std::string charToMorse(char charToConvert) {

    for (auto elem : morseMap) {

        if (elem.second == charToConvert) {

            return elem.first;
        }
    }

    return NULL;
}

char morseToChar(std::string morseToConvert) {

    return morseMap[morseToConvert];
}