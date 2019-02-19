//
// Created by tom on 19/02/19.
//

#ifndef IOT_CHALLENGE_TWO_ENCODE_H
#define IOT_CHALLENGE_TWO_ENCODE_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class Morse {

public:
    vector<char>* morse;
    vector<char>* operator->();
    Morse();
    ~Morse();
};


#endif //IOT_CHALLENGE_TWO_ENCODE_H