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
#include "PSORouting.h"

// #define CONST_MAX_BUFFER 4098
#define CONST_MAX_BUFFER 262144

using namespace std;

typedef vector<string> strings_t;
typedef vector <nodeCInfo> nodes_t;
typedef vector <routeCInfo> routes_t;
typedef int name_t;

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
    topology_info_t computeTopology(controllerInfo controllerNode, nodes_t independentNodes, nodes_t relayNodes);
};

string getStdoutFromCommand(string cmd);
string getStdFromController(controllerInfo controllerNode, string name);
string getStdFromInfo(controllerInfo controllerNode, nodes_t independentNodes, nodes_t relayNodes);
string getStdFromNode(nodes_t nodes, string name);
topology_info_t getTopologyFromStd(controllerInfo controllerNode, nodes_t relayNodes, string message);
strings_t split (const string &s, char delim, int c_first = 0, int c_others = 0);

#endif // COMMAND_H
