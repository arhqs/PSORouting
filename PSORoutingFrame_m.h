//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/routing/PSO/PSORoutingFrame.msg.
//

#ifndef _PSOROUTINGFRAME_M_H_
#define _PSOROUTINGFRAME_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
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
// }}

/**
 * Enum generated from <tt>src/node/communication/routing/PSO/PSORoutingFrame.msg:40</tt> by nedtool.
 * <pre>
 * enum PSORouting_FrameType
 * {
 * 
 *     PSO_MULTIMEDIA_PKT = 0100;
 *     PSO_ADV_MSG = 0101;
 *     PSO_SN_MSG = 0102;
 *     PSO_RN_MSG = 0103;
 *     PSO_ACK_MSG = 0104;
 * }
 * </pre>
 */
enum PSORouting_FrameType {
    PSO_MULTIMEDIA_PKT = 0100,
    PSO_ADV_MSG = 0101,
    PSO_SN_MSG = 0102,
    PSO_RN_MSG = 0103,
    PSO_ACK_MSG = 0104
};

/**
 * Struct generated from src/node/communication/routing/PSO/PSORoutingFrame.msg:48 by nedtool.
 */
struct PSOLocationInfo
{
    PSOLocationInfo();
    double x;
    double y;
};

void doPacking(cCommBuffer *b, PSOLocationInfo& a);
void doUnpacking(cCommBuffer *b, PSOLocationInfo& a);

/**
 * Struct generated from src/node/communication/routing/PSO/PSORoutingFrame.msg:53 by nedtool.
 */
struct PSORoute
{
    PSORoute();
    int selfId;
    int destination;
    int nextHop;
};

void doPacking(cCommBuffer *b, PSORoute& a);
void doUnpacking(cCommBuffer *b, PSORoute& a);

/**
 * Class generated from <tt>src/node/communication/routing/PSO/PSORoutingFrame.msg:59</tt> by nedtool.
 * <pre>
 * packet PSORoutingPacket extends RoutingPacket
 * {
 *     int PSORoutingPacketKind @enum(PSORouting_FrameType);
 *     PSOLocationInfo currentLocation;
 *     PSOLocationInfo eventLocation;
 *     PSOLocationInfo idealLocation;
 *     string nextHop;
 *     string nextHopRoute;
 *     int sourceRoute;
 * 
 * //	std::vector<PSORoute> routes;
 * 
 *     double RE;
 *     double speed;
 *     int traject;
 *     double data;
 *     bool replacement;
 *     double startVideo;
 * }
 * </pre>
 */
class PSORoutingPacket : public ::RoutingPacket
{
  protected:
    int PSORoutingPacketKind_var;
    PSOLocationInfo currentLocation_var;
    PSOLocationInfo eventLocation_var;
    PSOLocationInfo idealLocation_var;
    opp_string nextHop_var;
    opp_string nextHopRoute_var;
    int sourceRoute_var;
    double RE_var;
    double speed_var;
    int traject_var;
    double data_var;
    bool replacement_var;
    double startVideo_var;

  private:
    void copy(const PSORoutingPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PSORoutingPacket&);

  public:
    PSORoutingPacket(const char *name=NULL, int kind=0);
    PSORoutingPacket(const PSORoutingPacket& other);
    virtual ~PSORoutingPacket();
    PSORoutingPacket& operator=(const PSORoutingPacket& other);
    virtual PSORoutingPacket *dup() const {return new PSORoutingPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getPSORoutingPacketKind() const;
    virtual void setPSORoutingPacketKind(int PSORoutingPacketKind);
    virtual PSOLocationInfo& getCurrentLocation();
    virtual const PSOLocationInfo& getCurrentLocation() const {return const_cast<PSORoutingPacket*>(this)->getCurrentLocation();}
    virtual void setCurrentLocation(const PSOLocationInfo& currentLocation);
    virtual PSOLocationInfo& getEventLocation();
    virtual const PSOLocationInfo& getEventLocation() const {return const_cast<PSORoutingPacket*>(this)->getEventLocation();}
    virtual void setEventLocation(const PSOLocationInfo& eventLocation);
    virtual PSOLocationInfo& getIdealLocation();
    virtual const PSOLocationInfo& getIdealLocation() const {return const_cast<PSORoutingPacket*>(this)->getIdealLocation();}
    virtual void setIdealLocation(const PSOLocationInfo& idealLocation);
    virtual const char * getNextHop() const;
    virtual void setNextHop(const char * nextHop);
    virtual const char * getNextHopRoute() const;
    virtual void setNextHopRoute(const char * nextHopRoute);
    virtual int getSourceRoute() const;
    virtual void setSourceRoute(int sourceRoute);
    virtual double getRE() const;
    virtual void setRE(double RE);
    virtual double getSpeed() const;
    virtual void setSpeed(double speed);
    virtual int getTraject() const;
    virtual void setTraject(int traject);
    virtual double getData() const;
    virtual void setData(double data);
    virtual bool getReplacement() const;
    virtual void setReplacement(bool replacement);
    virtual double getStartVideo() const;
    virtual void setStartVideo(double startVideo);
};

inline void doPacking(cCommBuffer *b, PSORoutingPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PSORoutingPacket& obj) {obj.parsimUnpack(b);}


#endif // ifndef _PSOROUTINGFRAME_M_H_

