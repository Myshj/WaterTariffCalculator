#include "extendedmeterreadingconnector.h"

void ExtendedMeterReadingConnector::connect(ExtendedMeterReading *from, ExtendedMeterReading *to)
{
    DoubleNumberToNumberConnector::connect(
                from->getLessThen40(),
                to->getLessThen40()
                );

    DoubleNumberToNumberConnector::connect(
                from->getFrom40To44(),
                to->getFrom40To44()
                );

    DoubleNumberToNumberConnector::connect(
                from->getFrom45To49(),
                to->getFrom45To49()
                );

    DoubleNumberToNumberConnector::connect(
                from->getGreaterThen50(),
                to->getGreaterThen50()
                );
}
