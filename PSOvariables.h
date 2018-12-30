#ifndef _PSO_VARIABLES_H_
#define _PSO_VARIABLES_H_

#include <vector>
#include <unistd.h>
#include <iostream>
#include "PSORoutingFrame_m.h"

using namespace std;

struct routeCInfo{
    int nodeId;
    int nextHop;
    int source;
    int destination;
    PSOLocationInfo idealLocation;
    PSOLocationInfo selfLocation;
    bool ack;
    bool replace;
    int lastReceivedPacket;
};

struct nodeCInfo{
    double RE;
    double speed;
    double avg;
    double time;
    double timeMove;
    int id;
    int trajectory;
    PSOLocationInfo selfLocation;
    bool selected;

    int independent;
    double distController;
};

struct controllerInfo{
    PSOLocationInfo controllerLocation;
    int controllerId;
};

typedef vector<string> strings_t;
typedef vector<nodeCInfo> nodes_t;
typedef vector<routeCInfo> routes_t;
typedef vector<int> indexes_t;
typedef int name_t;

#endif
