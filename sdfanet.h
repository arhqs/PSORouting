#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <iostream>
#include "PSOvariables.h"

// #define CONST_MAX_BUFFER 4098
#define CONST_MAX_BUFFER 8192

using namespace std;

typedef struct topologyInfo {
    controllerInfo controllerNode;
    nodes_t relayNodes;
    routes_t routes;
} topology_info_t;

class Sdfanet
{
private:
    int sockfd;
    void error(const char *msg);
    void send(const char *msg);
    void receive(char *msg);
public:
    Sdfanet();
    void connectMain();
    topology_info_t computeTopology(controllerInfo controllerNode, nodes_t nodes);
};

indexes_t getIndexesFromNode(nodes_t nodes, bool independent);
string getStdoutFromCommand(string cmd);
string getStdFromController(controllerInfo controllerNode, string name);
string getStdFromNode(nodes_t nodes, indexes_t indexes, string name);
string getStdFromInfo(controllerInfo controllerNode, nodes_t nodes, indexes_t iNodes, indexes_t rNodes);
topology_info_t getTopologyFromStd(controllerInfo controllerNode, nodes_t nodes, indexes_t rNodes, string message);
strings_t split (const string &s, char delim, int c_first = 0, int c_others = 0);

#endif // COMMAND_H
