#ifndef DATATOWATERPRICECALCULATIONBINDINGCONNECTOR_H
#define DATATOWATERPRICECALCULATIONBINDINGCONNECTOR_H


#include "waterpricecalculationbinding.h"

#include "extendedmeterreadingconnector.h"
#include "tariffsforwaterconnector.h"


class DataToWaterPriceCalculationBindingConnector
{
public:

    static void connect(
            ExtendedMeterReading* consumed,
            TariffsForWater* tariffs,
            DoubleNumber* price,
            WaterPriceCalculationBinding* binding
    )
    {
        ExtendedMeterReadingConnector::connect(
                    consumed,
                    binding->getConsumed()
        );

        TariffsForWaterConnector::connect(
                    tariffs,
                    binding->getTariffs()
        );

        DoubleNumberToNumberConnector::connect(
                    binding->getPrice(),
                    price
        );
    }

private:
    virtual ~DataToWaterPriceCalculationBindingConnector() = 0;
};

#endif // DATATOWATERPRICECALCULATIONBINDINGCONNECTOR_H
