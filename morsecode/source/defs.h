//
// Created by tom on 19/02/19.
//

#ifndef IOT_CHALLENGE_TWO_DEF_H
#define IOT_CHALLENGE_TWO_DEF_H

#include <map>
#include <utility>

using std::map;
using std::pair;

#define SENDER 's'
#define RECEIVER 'r'

void waitForRoleSelection();
void setRole(char role);
void executeRoleDuties();
void executeSenderProtocol();
void executeReceiverProtocol();

#endif //IOT_CHALLENGE_TWO_DEF_H
