#ifndef EXTENDEDMETERREADINGCONNECTOR_H
#define EXTENDEDMETERREADINGCONNECTOR_H

#include "extendedmeterreading.h"
#include "connectors/doublenumbertonumberconnector.h"


class ExtendedMeterReadingConnector
{
public:

    static void connect(
            ExtendedMeterReading* from,
            ExtendedMeterReading* to
    );

private:
    virtual ~ExtendedMeterReadingConnector() = 0;
};

#endif // EXTENDEDMETERREADINGCONNECTOR_H
