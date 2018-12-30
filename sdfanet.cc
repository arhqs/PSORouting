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

#include "PSOvariables.h"
#include "sdfanet.h"

using namespace std;

Sdfanet::Sdfanet(){}

void Sdfanet::connectMain(){
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = atoi("8000");
    server = gethostbyname("localhost");

    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sockfd < 0)
        error("ERROR opening socket");

    // printf("conectado");

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

//     printf("conectado2");

}

void Sdfanet::error(const char *msg)
{
    perror(msg);
    exit(0);
}


void Sdfanet::send(const char *msg){
    int n;
    // cout << endl;
    // cout << "MSG from sdfanet to python: " << msg << endl;
    // cout << endl;

    n = write(this->sockfd,msg,strlen(msg));
    if (n < 0)
         error("ERROR writing to socket");
}

void Sdfanet::receive(char *msg){
    int n = 0;


    while(n == 0){
        bzero(msg,CONST_MAX_BUFFER);
        n = read(this->sockfd,msg,CONST_MAX_BUFFER-1);
        // cout << endl;
        // cout << "READING FROM SOCKET: " << msg << endl;
        // cout << endl;

    }
    if (n < 0)
         error("ERROR reading from socket");

}

topology_info_t Sdfanet::computeTopology(controllerInfo controllerNode, nodes_t nodes) {

    // cout << "COMPUTETOPOLOGY 1" << endl;

    stringstream ss;
    char buffer[CONST_MAX_BUFFER];
    indexes_t iNodes;
    indexes_t rNodes;

    // cout << "COMPUTETOPOLOGY 2" << endl;

    // coleta indexes para relay e independent nodes
    iNodes = getIndexesFromNode(nodes, true);
    rNodes = getIndexesFromNode(nodes, false);

    // cout << "COMPUTETOPOLOGY 3" << endl;

    // computa mensagem já com os indexes separados
    string message = getStdFromInfo(controllerNode, nodes, iNodes, rNodes);

    this->send(message.c_str());

    this->receive(buffer);

    // printf("buffer: >%s<\n", buffer);

    // computa mensagem recebida
    topology_info_t topology = getTopologyFromStd(controllerNode, nodes, rNodes, buffer);

    return topology;
}

indexes_t getIndexesFromNode(nodes_t nodes, bool independent){
    indexes_t indexes;
	for (int i = 0; i < nodes.size(); ++i){
        if (independent){
            if (nodes[i].independent > 0){
                indexes.push_back(i);
            }
        }
        else{
            if (nodes[i].independent < 0){
                indexes.push_back(i);
            }
        }
	}
    cout << endl;
	return indexes;
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

string getStdFromInfo(controllerInfo controllerNode, nodes_t nodes, indexes_t iNodes, indexes_t rNodes) {

    stringstream ss;

    ss << "{" << getStdFromController(controllerNode, "C") << "," << getStdFromNode(nodes, rNodes, "RU") << "," << getStdFromNode(nodes, iNodes, "MU") << "}";

    return ss.str();
}

string getStdFromNode(nodes_t nodes, indexes_t indexes, string name){
    stringstream ss;
    stringstream positions;
    stringstream names;

    unsigned n = unsigned(indexes.size());

    // cout << "NODES.SIZE(): " << nodes.size() << endl;
    // cout << "NAME: " << name << endl;

    for (unsigned i=0; i<n; i++){
        if (i>0){
            positions << ",";
            names << ",";
        }
        positions << "[";
        positions << nodes.at(indexes.at(i)).selfLocation.x;
        positions << ",";
        positions << nodes.at(indexes.at(i)).selfLocation.y;
        positions << "]";
        names << "\"";
        names << to_string(nodes.at(indexes.at(i)).id);
        names << "\"";
    }

    ss << "\"posNodes" << name << "\":[" << positions.str() << "],\"namesNodes" << name << "\":[" << names.str() << "]";

    return ss.str();
}


string getStdFromController(controllerInfo controllerNode, string name) {
    stringstream ss;
    stringstream sposition;
    stringstream sname;

    sposition << controllerNode.controllerLocation.x;
    sposition << ",";
    sposition << controllerNode.controllerLocation.y;

    sname << "\"";
    sname << to_string(controllerNode.controllerId);
    sname << "\"";

    ss << "\"posNode" << name << "\":[" << sposition.str() << "],\"nameNode" << name << "\":" << sname.str();
    return ss.str();
}

topology_info_t getTopologyFromStd(controllerInfo controllerNode, nodes_t nodes, indexes_t rNodes, string message){

    // printf("getTopologyFromStd init\n");

    char delim1 = ']';
    char delim2 = ',';

    size_t posCon = message.find("posNodeC");
    size_t posPos = message.find("posNodesRU");
    size_t posRou = message.find("routes");

    string strCon = message.substr(posCon+12);
    string strPos = message.substr(posPos+14);
    string strRou = message.substr(posRou+10);
//    cout << strCon << endl;

    size_t strConEnd = strCon.find("]");
    size_t posPosEnd = strPos.find("]]");
    size_t strRouEnd = strRou.find("]]");

    strCon = strCon.substr(0, strConEnd+1);
    strPos = strPos.substr(0, posPosEnd+1);
    strRou = strRou.substr(0, strRouEnd+1);
//    cout << strCon << endl;

    strings_t stringsPos = split(strPos, delim1, 1, 3);
    strings_t stringsRou = split(strRou, delim1, 2, 4);

    strings_t stringsConIn = split(strCon, delim2, 0, 1);
//    cout << stringsConIn.at(0) << endl;
    controllerNode.controllerLocation.x = stod(stringsConIn.at(0));
//    cout << stringsConIn.at(1) << endl;
    controllerNode.controllerLocation.y = stod(stringsConIn.at(1));

    // printf("getTopologyFromStd 1\n");
    
    cout << "RELAYNODES.SIZE(): " << rNodes.size() << endl;

    nodes_t result_nodes;
    topology_info_t topology;

    for (int i = 0; i < rNodes.size(); ++i) {

        //cout << stringsPos.at(i) << endl;

        strings_t stringsPosIn = split(stringsPos[i], delim2, 0, 1);


        nodeCInfo result_node;
        PSOLocationInfo location;

        location.x = stod(stringsPosIn.at(0));
        location.y = stod(stringsPosIn.at(1));

        result_node.id = nodes[rNodes[i]].id;
        result_node.selfLocation = location;

        result_nodes.push_back(result_node);

        topology.relayNodes.push_back(result_node);
        // cout << "stringsPosIn: " << stringsPosIn.at(0) << "," <<  stringsPosIn.at(1) << endl;
        
    }
    // printf("getTopologyFromStd 1\n");

    routes_t routes;
    string::size_type sz;

    for (int i = 0; i < stringsRou.size(); ++i) {
        strings_t stringsRouIn = split(stringsRou.at(i), delim2, 0, 2);
        routeCInfo route;
        route.nodeId = stoi(stringsRouIn.at(0), &sz);
        route.nextHop = stoi(stringsRouIn.at(1), &sz);
        route.destination = stoi(stringsRouIn.at(2), &sz);
        routes.push_back(route);
        topology.routes.push_back(route);
    }

    // topology.relayNodes = result_nodes;
    // topology.routes = routes;


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
