#ifndef EXTENDEDMETERREADINGCHANGECONNECTOR_H
#define EXTENDEDMETERREADINGCHANGECONNECTOR_H

#include "extendedmeterreadingchange.h"
#include "connectors/extendedmeterreadingconnector.h"


class ExtendedMeterReadingChangeConnector
{
public:

    static void connect(
            ExtendedMeterReadingChange* from,
            ExtendedMeterReadingChange* to
    );

private:
    virtual ~ExtendedMeterReadingChangeConnector() = 0;
};

#endif // EXTENDEDMETERREADINGCHANGECONNECTOR_H
