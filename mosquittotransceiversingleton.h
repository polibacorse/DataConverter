#ifndef MOSQUITTOTRANSCEIVERSINGLETON_H
#define MOSQUITTOTRANSCEIVERSINGLETON_H

#include "mosquittotransceiver.h"

class MosquittoTransceiverSingleton
{
public:
    static MosquittoTransceiver *get();
    static void set(MosquittoTransceiver *);
};

#endif // MOSQUITTOTRANSCEIVERSINGLETON_H
