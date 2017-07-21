#include "session.h"

#include "connectors/datatoconsumedwatercalculationbindingconnector.h"
#include "connectors/datatowaterpricecalculationbindingconnector.h"
#include "connectors/doublenumberstotwonumbersbindingconnector.h"

Session::Session(
        QObject *parent
) : QObject(parent),
    input(new ExtendedMeterReadingInputSession(this)),
    consumed(new ExtendedMeterReading(this)),
    price(new DoubleNumber(0.0, this)),
    correctedHeatedVolume(new DoubleNumber(0.0, this)),
    consumedBinding(new ConsumedWaterCalculationBinding(this)),
    priceBinding(new WaterPriceCalculationBinding(this)),
    correctedHeatedVolumeBinding(new DivisionBinding(this))
{
    DataToConsumedWaterCalculationBindingConnector::connect(
                input->getChange(),
                consumed,
                consumedBinding
    );

    DataToWaterPriceCalculationBindingConnector::connect(
                consumed,
                input->getTariffs(),
                price,
                priceBinding
    );

    DoubleNumbersToTwoNumbersBindingConnector::connect(
                price,
                input->getTariffs()->getHeated(),
                correctedHeatedVolume,
                correctedHeatedVolumeBinding
    );
}

ExtendedMeterReadingInputSession* Session::getInput() const
{
    return input;
}

ExtendedMeterReading* Session::getConsumed() const
{
    return consumed;
}

DoubleNumber* Session::getPrice() const
{
    return price;
}

DoubleNumber* Session::getCorrectedHeatedVolume() const
{
    return correctedHeatedVolume;
}
