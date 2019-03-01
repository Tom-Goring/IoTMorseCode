#include <string>

char morseToChar(std::string morseString) {

    if (morseString == ".") {
        return 'E';
    } else if (morseString == "-") {
        return 'T';
    } else if (morseString == "..") {
        return 'I';
    } else if (morseString == ".-") {
        return 'A';
    } else if (morseString == "-.") {
        return 'N';
    } else if (morseString == "--") {
        return 'M';
    } else if (morseString == "...") {
        return 'S';
    } else if (morseString == "..-") {
        return 'U';
    } else if (morseString == ".-.") {
        return 'R';
    } else if (morseString == ".--") {
        return 'W';
    } else if (morseString == "-..") {
        return 'D';
    } else if (morseString == "-.-") {
        return 'K';
    } else if (morseString == "--.") {
        return 'G';
    } else if (morseString == "---") {
        return 'O';
    } else if (morseString == "....") {
        return 'H';
    } else if (morseString == "...-") {
        return 'V';
    } else if (morseString == "..-.") {
        return 'F';
    } else if (morseString == ".-..") {
        return 'L';
    } else if (morseString == ".--.") {
        return 'P';
    } else if (morseString == ".---") {
        return 'J';
    } else if (morseString == "-...") {
        return 'B';
    } else if (morseString == "-..-") {
        return 'X';
    } else if (morseString == "-.-.") {
        return 'C';
    } else if (morseString == "-.--") {
        return 'Y';
    } else if (morseString == "--..") {
        return 'Z';
    } else if (morseString == "--.-") {
        return 'Q';
    } else if (morseString == ".....") {
        return '5';
    } else if (morseString == "....-") {
        return '4';
    } else if (morseString == "...--") {
        return '3';
    } else if (morseString == "..---") {
        return '2';
    } else if (morseString == ".-.-.") {
        return '+';
    } else if (morseString == ".----") {
        return '1';
    } else if (morseString == "-....") {
        return '6';
    } else if (morseString == "-...-") {
        return '=';
    } else if (morseString == "-..-.") {
        return '/';
    } else if (morseString == "--...") {
        return '7';
    } else if (morseString == "---..") {
        return '8';
    } else if (morseString == "----.") {
        return '9';
    } else if (morseString == "-----") {
        return '0';
    } else {
        return '!';
    }
}

