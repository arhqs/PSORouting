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
//*     Module: Software-Defined UAVNet architecture (SD-UAVNet)           *
//*                                                                                                                *
//*     Ref.: D. Rosario, Z. Zhao, T. Braun, E. Cerqueira, A. Santos, and Z. Li, “Assessment of a Robust           *
//*     Opportunistic Routing for Video Transmission in Dynamic Topologies” in Proceedings of the IFIP Wireless    *
//*     Days conference (WD'13). Valencia, Spain, November 13-15, 2013                                             *
//*                                                                                                                *
//*  	Version: 2.0                                                                                               *
//*  	Authors: Denis do Rosário <denis@ufpa.br>                                                                  *
//*                                                                                                                *
//*****************************************************************************************************************/

cplusplus {{
#include "RoutingPacket_m.h"
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
}}

class RoutingPacket;

enum PSORouting_FrameType{
	PSO_MULTIMEDIA_PKT	= 0100;
	PSO_ADV_MSG		= 0101;
	PSO_SN_MSG		= 0102;
	PSO_RN_MSG		= 0103;
	PSO_ACK_MSG		= 0104;
};

struct PSOLocationInfo{
	double x;
	double y;
}

struct PSORoute{
    int selfId;
    int destination;
    int nextHop;
}

packet PSORoutingPacket extends RoutingPacket{	
	int PSORoutingPacketKind enum (PSORouting_FrameType);
	PSOLocationInfo currentLocation;
	PSOLocationInfo eventLocation;
	PSOLocationInfo idealLocation;
	string nextHop;
	string nextHopRoute;
	int sourceRoute;
	
//	std::vector<PSORoute> routes;
	
	double RE;
	double speed;
	int traject;	
	double data;
	bool replacement;
	double startVideo;
};

