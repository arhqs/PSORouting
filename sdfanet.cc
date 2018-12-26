#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "PSORouting.h"
#include "sdfanet.h"

using namespace std;

Sdfanet::Sdfanet(){
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = atoi("8000");
    server = gethostbyname("localhost");

    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sockfd < 0)
        error("ERROR opening socket");

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(this->sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
}

void Sdfanet::error(const char *msg)
{
    perror(msg);
    exit(0);
}


void Sdfanet::send(const char *msg){
    int n;
    n = write(this->sockfd,msg,strlen(msg));
    if (n < 0)
         error("ERROR writing to socket");
}

void Sdfanet::receive(char *msg){
    int n;
    bzero(msg,CONST_MAX_BUFFER);
    n = read(this->sockfd,msg,CONST_MAX_BUFFER-1);
    if (n < 0)
         error("ERROR reading from socket");
}

topology_info_t Sdfanet::computeTopology(controllerInfo controllerNode, nodes_t independentNodes, nodes_t relayNodes) {
    std::stringstream ss;

    char buffer[CONST_MAX_BUFFER];

    this->receive(buffer);

    string message = getStdFromInfo(controllerNode, relayNodes, independentNodes);

    printf("message: %s",message.c_str());

    this->send(message.c_str());

//    printf("message.size() %d",message.size());

    this->receive(buffer);

//    cout << buffer << endl;
    topology_info_t topology = getTopologyFromStd(controllerNode, relayNodes, buffer);

    this->send("ack");

    return topology;
}

string getStdoutFromCommand(string cmd) {
    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
    return data;
}

string getStdFromInfo(controllerInfo controllerNode, nodes_t independentNodes, nodes_t relayNodes) {

    std::stringstream ss;

    ss << "{" << getStdFromController(controllerNode, "C") << "," << getStdFromNode(relayNodes, "RU") << "," << getStdFromNode(independentNodes, "MU") << "}";

    return ss.str();
}

string getStdFromNode(nodes_t nodes, string name) {
    std::stringstream ss;
    std::stringstream positions;
    std::stringstream names;
    unsigned n = unsigned(nodes.size());
    for (unsigned i=0; i<n; i++){
        if (i>0){
            positions << ",";
            names << ",";
        }
        positions << "[";
        positions << nodes.at(i).selfLocation.x;
        positions << ",";
        positions << nodes.at(i).selfLocation.y;
        positions << "]";
        names << "\"";
        names << std::to_string(nodes.at(i).id);
        names << "\"";
    }
    ss << "\"posNodes" << name << "\":[" << positions.str() << "],\"namesNodes" << name << "\":[" << names.str() << "]";
    return ss.str();
}


string getStdFromController(controllerInfo controllerNode, string name) {
    std::stringstream ss;
    std::stringstream sposition;
    std::stringstream sname;

    sposition << controllerNode.controllerLocation.x;
    sposition << ",";
    sposition << controllerNode.controllerLocation.y;

    sname << "\"";
    sname << std::to_string(controllerNode.controllerId);
    sname << "\"";

    ss << "\"posNode" << name << "\":[" << sposition.str() << "],\"nameNode" << name << "\":" << sname.str();
    return ss.str();
}

topology_info_t getTopologyFromStd(controllerInfo controllerNode, nodes_t relayNodes, string message){

    char delim1 = ']';
    char delim2 = ',';

    std::size_t posCon = message.find("posNodeC");
    std::size_t posPos = message.find("posNodesRU");
    std::size_t posRou = message.find("routes");

    std::string strCon = message.substr(posCon+12);
    std::string strPos = message.substr(posPos+14);
    std::string strRou = message.substr(posRou+10);
    std::cout << strCon << std::endl;

    std::size_t strConEnd = strCon.find("]");
    std::size_t posPosEnd = strPos.find("]]");
    std::size_t strRouEnd = strRou.find("]]");

    strCon = strCon.substr(0, strConEnd+1);
    strPos = strPos.substr(0, posPosEnd+1);
    strRou = strRou.substr(0, strRouEnd+1);
    std::cout << strCon << std::endl;

    strings_t stringsPos = split(strPos, delim1, 1, 3);
    strings_t stringsRou = split(strRou, delim1, 2, 4);

    strings_t stringsConIn = split(strCon, delim2, 0, 1);
    std::cout << stringsConIn.at(0) << std::endl;
    controllerNode.controllerLocation.x = std::stod(stringsConIn.at(0));
    std::cout << stringsConIn.at(1) << std::endl;
    controllerNode.controllerLocation.y = std::stod(stringsConIn.at(1));

    for (int i = 0; i < relayNodes.size(); ++i) {
        strings_t stringsPosIn = split(stringsPos.at(i), delim2, 0, 1);
        relayNodes.at(i).selfLocation.x = std::stod(stringsPosIn.at(0));
        relayNodes.at(i).selfLocation.y = std::stod(stringsPosIn.at(1));
    }

    routes_t routes;
    std::string::size_type sz;

    for (int i = 0; i < stringsRou.size(); ++i) {
        strings_t stringsRouIn = split(stringsRou.at(i), delim2, 0, 2);
        routeCInfo route;
        route.nodeId = std::stoi(stringsRouIn.at(0), &sz);
        route.nextHop = std::stoi(stringsRouIn.at(1), &sz);
        route.destination = std::stoi(stringsRouIn.at(2), &sz);
        routes.push_back(route);
    }

    topology_info_t topology;

    topology.relayNodes = relayNodes;
    topology.routes = routes;

    return topology;
}

strings_t split (const string &s, char delim, int c_first, int c_others) {
    vector<string> result;
    stringstream ss (s);
    string item;
    bool first = true;
    while (getline (ss, item, delim)) {
        if (first){
            first = false;
            if (c_first > 0)
                item = item.substr(c_first);

        } else if (c_others > 0)
            item = item.substr(c_others);
        result.push_back (item);
    }
    return result;
}
