//******************************************************************************************************************
//*     Copyright (c) 2013. Federal University of Para (UFPA), Brazil and                                          *
//*                         University of Bern (UBern), Switzerland                                                *
//*     Developed by Research Group on Computer Network and Multimedia Communication (GERCOM) of UFPA              *
//*     in collaboration to Communication and Distributed Systems (CDS) research group of UBern.                   *
//*     All rights reserved                                                                                        *
//*                                                                                                                *
//*     Permission to use, copy, modify, and distribute this protocol and its documentation for any purpose,       *
//*     without fee, and without written agreement is hereby granted, provided that the above copyright notice,    *
//*     and the author appear in all copies of this protocol.                                                      *
//*                                                                                                                *
//*     Module: Software-Defined UAVNet architecture (SD-UAVNet)            *
//*                                                                                                                *
//*     Ref.: D. Rosario, Z. Zhao, T. Braun, E. Cerqueira, A. Santos, and Z. Li, “Assessment of a Robust           *
//*     Opportunistic Routing for Video Transmission in Dynamic Topologies” in Proceedings of the IFIP Wireless    *
//*     Days conference (WD'13). Valencia, Spain, November 13-15, 2013                                             *
//*                                                                                                                *
//*  	Version: 2.0                                                                                               *
//*  	Authors: Denis do Rosário <denis@ufpa.br>                                                                  *
//*                                                                                                                *
//*****************************************************************************************************************/

#ifndef _PSO_ROUTING_H_
#define _PSO_ROUTING_H_

#include <cmath>
#include <queue>
#include <vector>
#include <omnetpp.h>
#include <algorithm>
#include <pthread.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "WirelessChannel.h"
#include "Radio.h"
#include "VirtualMac.h"
#include "VirtualRouting.h"
#include "PSORoutingFrame_m.h"
#include "VirtualMobilityManager.h"

using namespace std;

enum PSORoutingTimers {
	PSO_CLEAN_BUFFER	= 1,
	PSO_STATISTICS	= 2,
	PSO_SEND_BEACON	= 3,
	PSO_DECISION	= 4,
	PSO_DECISIONRN	= 5,
	PSO_SENDINFO	= 6,
	PSO_CHECKACK	= 7,
	PSO_ROUTE_STATISTICS= 8,
	PSO_ALIVE		= 9,
	PSO_UPDATE_ROUTE	= 10,
};

enum PSORoutingStatistics {
	PSO_STATISTICS_RECEIVED_PACKET	= 2,
	PSO_STATISTICS_UNICAST_PACKET	= 3,
	PSO_STATISTICS_MOS			= 10,
	PSO_STATISTICS_ILOST		= 11,
	PSO_STATISTICS_PLOST		= 12,
	PSO_STATISTICS_BLOST		= 13,
	PSO_STATISTICS_FRAMES		= 14,
	PSO_STATISTICS_ROUTE		= 15,
};

struct pktList{
	int seqNumber;
	queue <cPacket *> bufferPkt;
};

struct replacementInfo{
	int nodeId;
	int nextHop;
	int source;
	int destination;
	int line;
	PSOLocationInfo location;
	bool ack;
	bool replace;
	int lastReceivedPacket;
};

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
};

struct eventInfo{
	PSOLocationInfo eventLocation;
	double time;
};

struct controllerInfo{
	PSOLocationInfo controllerLocation;
	int controllerId;
};

struct requestData{
	double time;
	double frames;
	int nodeId;
	int videoId;
	int nRecPkts;
	int hopSum;
};

class PSORouting : public VirtualRouting {
 protected:
	// The .ned file's parameters
	string destinationAddress;
	string controllerAddress;
	double beaconInterval;
	double timeToMoveMax;
	double minEnergy;

	//to LinGO protocol
	VirtualMobilityManager* mobilityModule;
	VirtualMobilityManager* sinkMobilityModule;
	VirtualMobilityManager* sinkMobilityModule1;
	VirtualMac *macModule;
	WirelessChannel *wirelessModule;
	ResourceManager *srceRerouceModuce;
	ResourceManager *energy;
	NodeLocation location;
	PSOLocationInfo currentLocation;
	PSOLocationInfo destinationLocation;
	PSOLocationInfo controllerLocation;
	PSOLocationInfo lastLocation;
	PSOLocationInfo movingLocation;
	PSOLocationInfo idealLastHopLocation;
	PSOLocationInfo idealLocation;
	vector <pktList> buffer;
	vector <routeCInfo> route;
	vector <nodeCInfo> nodes;
	vector <replacementInfo> replaceList;
	vector <eventInfo> eventList;
	vector <controllerInfo> controllerList;

	double tStart;
	double tMax;
	double sensedValue;

	//to collect statistics
	vector <requestData> videoStatistics;
	void statistics(int, int, int, int, double, int);
	int statisticNext;
	int statisticLast;
	int statisticFistPkt;
	int statisticLastPkt;
	int statisticQtdPkts;
	double statisticDuration;
	int statisticIdVideo;
	int statisticIdSource;
	bool print;
	double time;
	int idEvent;

	void nodeReplacement(int, int);
	void sendAdv();
	double getResidualEnergy();
	double getInitialEnergy();
	double getEnergyPerPkt();
	double getRadioRange();
	double getTxPower();
	double getSensitivity();
	void loadEventList();
	void loadControlerList();
	
	string getControllerId(PSOLocationInfo);
	int getControllerIndex(PSOLocationInfo);
	PSOLocationInfo getCurrentLocation ();
	double computeDistance(PSOLocationInfo, PSOLocationInfo);
	void SNbackboneMode(cPacket *, int);
	void RNreceivedPktBackbone(PSORoutingPacket *);
	void DNreceivedPkt(cPacket *);
	void dropAlgorithm(PSORoutingPacket *);
	bool searchBuffer(int);
	PSOLocationInfo computeIdealLocation();
	void startup();
	void selectSource();
	void selectRelay();
	virtual void finish();
	void fromApplicationLayer(cPacket *, const char *);
	void fromMacLayer(cPacket *, int, double, double);
	void timerFiredCallback(int);
	void multipleTimerFiredCallback(int, int);
	void processBufferedPacket(string);
	void setRadio_Sleep(double delay=0.0);
	void setRadio_Listen(double delay=0.0);
    void setRadio_TXPowerLevel(int, double);
};

bool PSO_sort_buffer(pktList a, pktList b);
bool PSO_sort_node(nodeCInfo a, nodeCInfo b);
bool PSO_sort_time(nodeCInfo a, nodeCInfo b);

#endif
