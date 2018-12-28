//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/routing/PSO/PSORoutingFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PSORoutingFrame_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("PSORouting_FrameType");
    if (!e) enums.getInstance()->add(e = new cEnum("PSORouting_FrameType"));
    e->insert(PSO_MULTIMEDIA_PKT, "PSO_MULTIMEDIA_PKT");
    e->insert(PSO_ADV_MSG, "PSO_ADV_MSG");
    e->insert(PSO_SN_MSG, "PSO_SN_MSG");
    e->insert(PSO_RN_MSG, "PSO_RN_MSG");
    e->insert(PSO_ACK_MSG, "PSO_ACK_MSG");
);

PSOLocationInfo::PSOLocationInfo()
{
    x = 0;
    y = 0;
}

void doPacking(cCommBuffer *b, PSOLocationInfo& a)
{
    doPacking(b,a.x);
    doPacking(b,a.y);
}

void doUnpacking(cCommBuffer *b, PSOLocationInfo& a)
{
    doUnpacking(b,a.x);
    doUnpacking(b,a.y);
}

class PSOLocationInfoDescriptor : public cClassDescriptor
{
  public:
    PSOLocationInfoDescriptor();
    virtual ~PSOLocationInfoDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PSOLocationInfoDescriptor);

PSOLocationInfoDescriptor::PSOLocationInfoDescriptor() : cClassDescriptor("PSOLocationInfo", "")
{
}

PSOLocationInfoDescriptor::~PSOLocationInfoDescriptor()
{
}

bool PSOLocationInfoDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PSOLocationInfo *>(obj)!=NULL;
}

const char *PSOLocationInfoDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PSOLocationInfoDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PSOLocationInfoDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *PSOLocationInfoDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "x",
        "y",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int PSOLocationInfoDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='x' && strcmp(fieldName, "x")==0) return base+0;
    if (fieldName[0]=='y' && strcmp(fieldName, "y")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PSOLocationInfoDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *PSOLocationInfoDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PSOLocationInfoDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PSOLocationInfo *pp = (PSOLocationInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PSOLocationInfoDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PSOLocationInfo *pp = (PSOLocationInfo *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->x);
        case 1: return double2string(pp->y);
        default: return "";
    }
}

bool PSOLocationInfoDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PSOLocationInfo *pp = (PSOLocationInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->x = string2double(value); return true;
        case 1: pp->y = string2double(value); return true;
        default: return false;
    }
}

const char *PSOLocationInfoDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *PSOLocationInfoDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PSOLocationInfo *pp = (PSOLocationInfo *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

PSORoute::PSORoute()
{
    selfId = 0;
    destination = 0;
    nextHop = 0;
}

void doPacking(cCommBuffer *b, PSORoute& a)
{
    doPacking(b,a.selfId);
    doPacking(b,a.destination);
    doPacking(b,a.nextHop);
}

void doUnpacking(cCommBuffer *b, PSORoute& a)
{
    doUnpacking(b,a.selfId);
    doUnpacking(b,a.destination);
    doUnpacking(b,a.nextHop);
}

class PSORouteDescriptor : public cClassDescriptor
{
  public:
    PSORouteDescriptor();
    virtual ~PSORouteDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PSORouteDescriptor);

PSORouteDescriptor::PSORouteDescriptor() : cClassDescriptor("PSORoute", "")
{
}

PSORouteDescriptor::~PSORouteDescriptor()
{
}

bool PSORouteDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PSORoute *>(obj)!=NULL;
}

const char *PSORouteDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PSORouteDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int PSORouteDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *PSORouteDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "selfId",
        "destination",
        "nextHop",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int PSORouteDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "selfId")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHop")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PSORouteDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *PSORouteDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PSORouteDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PSORoute *pp = (PSORoute *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PSORouteDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PSORoute *pp = (PSORoute *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->selfId);
        case 1: return long2string(pp->destination);
        case 2: return long2string(pp->nextHop);
        default: return "";
    }
}

bool PSORouteDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PSORoute *pp = (PSORoute *)object; (void)pp;
    switch (field) {
        case 0: pp->selfId = string2long(value); return true;
        case 1: pp->destination = string2long(value); return true;
        case 2: pp->nextHop = string2long(value); return true;
        default: return false;
    }
}

const char *PSORouteDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *PSORouteDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PSORoute *pp = (PSORoute *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PSORoutingPacket);

PSORoutingPacket::PSORoutingPacket(const char *name, int kind) : ::RoutingPacket(name,kind)
{
    this->PSORoutingPacketKind_var = 0;
    this->nextHop_var = 0;
    this->nextHopRoute_var = 0;
    this->sourceRoute_var = 0;
    this->RE_var = 0;
    this->speed_var = 0;
    this->traject_var = 0;
    this->data_var = 0;
    this->replacement_var = 0;
    this->startVideo_var = 0;
}

PSORoutingPacket::PSORoutingPacket(const PSORoutingPacket& other) : ::RoutingPacket(other)
{
    copy(other);
}

PSORoutingPacket::~PSORoutingPacket()
{
}

PSORoutingPacket& PSORoutingPacket::operator=(const PSORoutingPacket& other)
{
    if (this==&other) return *this;
    ::RoutingPacket::operator=(other);
    copy(other);
    return *this;
}

void PSORoutingPacket::copy(const PSORoutingPacket& other)
{
    this->PSORoutingPacketKind_var = other.PSORoutingPacketKind_var;
    this->currentLocation_var = other.currentLocation_var;
    this->eventLocation_var = other.eventLocation_var;
    this->idealLocation_var = other.idealLocation_var;
    this->nextHop_var = other.nextHop_var;
    this->nextHopRoute_var = other.nextHopRoute_var;
    this->sourceRoute_var = other.sourceRoute_var;
    this->RE_var = other.RE_var;
    this->speed_var = other.speed_var;
    this->traject_var = other.traject_var;
    this->data_var = other.data_var;
    this->replacement_var = other.replacement_var;
    this->startVideo_var = other.startVideo_var;
}

void PSORoutingPacket::parsimPack(cCommBuffer *b)
{
    ::RoutingPacket::parsimPack(b);
    doPacking(b,this->PSORoutingPacketKind_var);
    doPacking(b,this->currentLocation_var);
    doPacking(b,this->eventLocation_var);
    doPacking(b,this->idealLocation_var);
    doPacking(b,this->nextHop_var);
    doPacking(b,this->nextHopRoute_var);
    doPacking(b,this->sourceRoute_var);
    doPacking(b,this->RE_var);
    doPacking(b,this->speed_var);
    doPacking(b,this->traject_var);
    doPacking(b,this->data_var);
    doPacking(b,this->replacement_var);
    doPacking(b,this->startVideo_var);
}

void PSORoutingPacket::parsimUnpack(cCommBuffer *b)
{
    ::RoutingPacket::parsimUnpack(b);
    doUnpacking(b,this->PSORoutingPacketKind_var);
    doUnpacking(b,this->currentLocation_var);
    doUnpacking(b,this->eventLocation_var);
    doUnpacking(b,this->idealLocation_var);
    doUnpacking(b,this->nextHop_var);
    doUnpacking(b,this->nextHopRoute_var);
    doUnpacking(b,this->sourceRoute_var);
    doUnpacking(b,this->RE_var);
    doUnpacking(b,this->speed_var);
    doUnpacking(b,this->traject_var);
    doUnpacking(b,this->data_var);
    doUnpacking(b,this->replacement_var);
    doUnpacking(b,this->startVideo_var);
}

int PSORoutingPacket::getPSORoutingPacketKind() const
{
    return PSORoutingPacketKind_var;
}

void PSORoutingPacket::setPSORoutingPacketKind(int PSORoutingPacketKind)
{
    this->PSORoutingPacketKind_var = PSORoutingPacketKind;
}

PSOLocationInfo& PSORoutingPacket::getCurrentLocation()
{
    return currentLocation_var;
}

void PSORoutingPacket::setCurrentLocation(const PSOLocationInfo& currentLocation)
{
    this->currentLocation_var = currentLocation;
}

PSOLocationInfo& PSORoutingPacket::getEventLocation()
{
    return eventLocation_var;
}

void PSORoutingPacket::setEventLocation(const PSOLocationInfo& eventLocation)
{
    this->eventLocation_var = eventLocation;
}

PSOLocationInfo& PSORoutingPacket::getIdealLocation()
{
    return idealLocation_var;
}

void PSORoutingPacket::setIdealLocation(const PSOLocationInfo& idealLocation)
{
    this->idealLocation_var = idealLocation;
}

const char * PSORoutingPacket::getNextHop() const
{
    return nextHop_var.c_str();
}

void PSORoutingPacket::setNextHop(const char * nextHop)
{
    this->nextHop_var = nextHop;
}

const char * PSORoutingPacket::getNextHopRoute() const
{
    return nextHopRoute_var.c_str();
}

void PSORoutingPacket::setNextHopRoute(const char * nextHopRoute)
{
    this->nextHopRoute_var = nextHopRoute;
}

int PSORoutingPacket::getSourceRoute() const
{
    return sourceRoute_var;
}

void PSORoutingPacket::setSourceRoute(int sourceRoute)
{
    this->sourceRoute_var = sourceRoute;
}

double PSORoutingPacket::getRE() const
{
    return RE_var;
}

void PSORoutingPacket::setRE(double RE)
{
    this->RE_var = RE;
}

double PSORoutingPacket::getSpeed() const
{
    return speed_var;
}

void PSORoutingPacket::setSpeed(double speed)
{
    this->speed_var = speed;
}

int PSORoutingPacket::getTraject() const
{
    return traject_var;
}

void PSORoutingPacket::setTraject(int traject)
{
    this->traject_var = traject;
}

double PSORoutingPacket::getData() const
{
    return data_var;
}

void PSORoutingPacket::setData(double data)
{
    this->data_var = data;
}

bool PSORoutingPacket::getReplacement() const
{
    return replacement_var;
}

void PSORoutingPacket::setReplacement(bool replacement)
{
    this->replacement_var = replacement;
}

double PSORoutingPacket::getStartVideo() const
{
    return startVideo_var;
}

void PSORoutingPacket::setStartVideo(double startVideo)
{
    this->startVideo_var = startVideo;
}

class PSORoutingPacketDescriptor : public cClassDescriptor
{
  public:
    PSORoutingPacketDescriptor();
    virtual ~PSORoutingPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PSORoutingPacketDescriptor);

PSORoutingPacketDescriptor::PSORoutingPacketDescriptor() : cClassDescriptor("PSORoutingPacket", "RoutingPacket")
{
}

PSORoutingPacketDescriptor::~PSORoutingPacketDescriptor()
{
}

bool PSORoutingPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PSORoutingPacket *>(obj)!=NULL;
}

const char *PSORoutingPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PSORoutingPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 13+basedesc->getFieldCount(object) : 13;
}

unsigned int PSORoutingPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<13) ? fieldTypeFlags[field] : 0;
}

const char *PSORoutingPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "PSORoutingPacketKind",
        "currentLocation",
        "eventLocation",
        "idealLocation",
        "nextHop",
        "nextHopRoute",
        "sourceRoute",
        "RE",
        "speed",
        "traject",
        "data",
        "replacement",
        "startVideo",
    };
    return (field>=0 && field<13) ? fieldNames[field] : NULL;
}

int PSORoutingPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='P' && strcmp(fieldName, "PSORoutingPacketKind")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentLocation")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "eventLocation")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "idealLocation")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHop")==0) return base+4;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHopRoute")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceRoute")==0) return base+6;
    if (fieldName[0]=='R' && strcmp(fieldName, "RE")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "speed")==0) return base+8;
    if (fieldName[0]=='t' && strcmp(fieldName, "traject")==0) return base+9;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+10;
    if (fieldName[0]=='r' && strcmp(fieldName, "replacement")==0) return base+11;
    if (fieldName[0]=='s' && strcmp(fieldName, "startVideo")==0) return base+12;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PSORoutingPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "PSOLocationInfo",
        "PSOLocationInfo",
        "PSOLocationInfo",
        "string",
        "string",
        "int",
        "double",
        "double",
        "int",
        "double",
        "bool",
        "double",
    };
    return (field>=0 && field<13) ? fieldTypeStrings[field] : NULL;
}

const char *PSORoutingPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PSORouting_FrameType";
            return NULL;
        default: return NULL;
    }
}

int PSORoutingPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PSORoutingPacket *pp = (PSORoutingPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PSORoutingPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PSORoutingPacket *pp = (PSORoutingPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPSORoutingPacketKind());
        case 1: {std::stringstream out; out << pp->getCurrentLocation(); return out.str();}
        case 2: {std::stringstream out; out << pp->getEventLocation(); return out.str();}
        case 3: {std::stringstream out; out << pp->getIdealLocation(); return out.str();}
        case 4: return oppstring2string(pp->getNextHop());
        case 5: return oppstring2string(pp->getNextHopRoute());
        case 6: return long2string(pp->getSourceRoute());
        case 7: return double2string(pp->getRE());
        case 8: return double2string(pp->getSpeed());
        case 9: return long2string(pp->getTraject());
        case 10: return double2string(pp->getData());
        case 11: return bool2string(pp->getReplacement());
        case 12: return double2string(pp->getStartVideo());
        default: return "";
    }
}

bool PSORoutingPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PSORoutingPacket *pp = (PSORoutingPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setPSORoutingPacketKind(string2long(value)); return true;
        case 4: pp->setNextHop((value)); return true;
        case 5: pp->setNextHopRoute((value)); return true;
        case 6: pp->setSourceRoute(string2long(value)); return true;
        case 7: pp->setRE(string2double(value)); return true;
        case 8: pp->setSpeed(string2double(value)); return true;
        case 9: pp->setTraject(string2long(value)); return true;
        case 10: pp->setData(string2double(value)); return true;
        case 11: pp->setReplacement(string2bool(value)); return true;
        case 12: pp->setStartVideo(string2double(value)); return true;
        default: return false;
    }
}

const char *PSORoutingPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1: return opp_typename(typeid(PSOLocationInfo));
        case 2: return opp_typename(typeid(PSOLocationInfo));
        case 3: return opp_typename(typeid(PSOLocationInfo));
        default: return NULL;
    };
}

void *PSORoutingPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PSORoutingPacket *pp = (PSORoutingPacket *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getCurrentLocation()); break;
        case 2: return (void *)(&pp->getEventLocation()); break;
        case 3: return (void *)(&pp->getIdealLocation()); break;
        default: return NULL;
    }
}


