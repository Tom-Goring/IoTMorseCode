//
// Created by tom on 19/02/19.
//

#include "MicroBit.h"

MicroBit uBit;

int main() {

    uBit.init();

    uBit.display.scroll("Hello World!");
}
