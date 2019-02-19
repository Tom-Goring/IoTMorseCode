//
// Created by tom on 19/02/19.
//

#ifndef IOT_CHALLENGE_TWO_CIPHER_H
#define IOT_CHALLENGE_TWO_CIPHER_H

#include <vector>
#include <string>
#include "Morse.h"
#include "defs.h"

using std::vector;
using std::string;

class Cipher {

public:
    Cipher();
    ~Cipher();

    static Morse charToMorse(char letter);
    static Morse encrypt(char letter);
    static char decrypt(Morse);
    static char morseToChar(Morse);
    static string getKey(char);

    static char key[3];
};


#endif //IOT_CHALLENGE_TWO_CIPHER_H
