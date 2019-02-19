//
// Created by tom on 19/02/19.
//

#include "Morse.h"

Morse::Morse() {

    morse = new vector<char>;
}

Morse::~Morse() {}


vector<char>* Morse::operator->() {

    return morse;
}

