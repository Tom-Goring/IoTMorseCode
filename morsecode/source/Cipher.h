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

    Morse charToMorse(char letter);
    Morse encrypt(char letter);
    char decrypt(Morse);
    char morseToChar(Morse);
    string getKey(char);

    char key[3] = {'T', 'O', 'M'};
};


#endif //IOT_CHALLENGE_TWO_CIPHER_H
