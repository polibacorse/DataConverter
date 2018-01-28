#include "mosquittotransceiversingleton.h"

static MosquittoTransceiver *instance{nullptr};

MosquittoTransceiver *MosquittoTransceiverSingleton::get()
{
    return instance;
}

void MosquittoTransceiverSingleton::set(MosquittoTransceiver *newInstance)
{
    instance = newInstance;
}
