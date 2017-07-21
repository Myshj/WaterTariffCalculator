#include "extendedmeterreadingchangeconnector.h"

void ExtendedMeterReadingChangeConnector::connect(ExtendedMeterReadingChange *from, ExtendedMeterReadingChange *to)
{
    ExtendedMeterReadingConnector::connect(
                from->getOldData(),
                to->getOldData()
                );

    ExtendedMeterReadingConnector::connect(
                from->getNewData(),
                to->getNewData()
                );
}
