#ifndef EXTENDEDMETERREADINGCHANGECONNECTOR_H
#define EXTENDEDMETERREADINGCHANGECONNECTOR_H

#include "extendedmeterreadingchange.h"
#include "connectors/extendedmeterreadingconnector.h"


/**
 * @brief The ExtendedMeterReadingChangeConnector class establishes connection between two ExtendedMeterReadingChange objects.
 */
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
