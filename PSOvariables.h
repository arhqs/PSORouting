
#ifndef _PSO_VARIABLES_H_
#define _PSO_VARIABLES_H_



#include "PSORoutingFrame_m.h"


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
    double distController;

    int id;
    int trajectory;
    PSOLocationInfo selfLocation;
    bool selected;
    bool independent;
};

struct controllerInfo{
    PSOLocationInfo controllerLocation;
    int controllerId;
};


#endif
