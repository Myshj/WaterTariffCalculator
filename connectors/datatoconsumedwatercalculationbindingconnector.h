#ifndef DATATOCONSUMEDWATERCALCULATIONBINDINGCONNECTOR_H
#define DATATOCONSUMEDWATERCALCULATIONBINDINGCONNECTOR_H

#include "extendedmeterreadingchange.h"
#include "extendedmeterreading.h"
#include "consumedwatercalculationbinding.h"

#include "extendedmeterreadingchangeconnector.h"
#include "extendedmeterreadingconnector.h"


class DataToConsumedWaterCalculationBindingConnector
{
public:

    static void connect(
            ExtendedMeterReadingChange* change,
            ExtendedMeterReading* consumed,
            ConsumedWaterCalculationBinding* binding
    )
    {
        ExtendedMeterReadingChangeConnector::connect(
                    change,
                    binding->getChange()
        );

        ExtendedMeterReadingConnector::connect(
                    binding->getConsumed(),
                    consumed
        );
    }

private:
    virtual ~DataToConsumedWaterCalculationBindingConnector() = 0;
};

#endif // DATATOCONSUMEDWATERCALCULATIONBINDINGCONNECTOR_H
