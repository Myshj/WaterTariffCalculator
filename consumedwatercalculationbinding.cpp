#include "consumedwatercalculationbinding.h"
#include <QtDebug>

#include "connectors/doublenumberstotwonumbersbindingconnector.h"

ConsumedWaterCalculationBinding::ConsumedWaterCalculationBinding(
        QObject *parent
) : Binding (parent),
    change(new ExtendedMeterReadingChange(this)),
    consumed(new ExtendedMeterReading(this)),
    lessThen40Binding(new SubtractionBinding(this)),
    from40To44Binding(new SubtractionBinding(this)),
    from45To49Binding(new SubtractionBinding(this)),
    greaterThen50Binding(new SubtractionBinding(this))
{
    DoubleNumbersToTwoNumbersBindingConnector::connect(
                this->change->getNewData()->getLessThen40(),
                this->change->getOldData()->getLessThen40(),
                this->consumed->getLessThen40(),
                this->lessThen40Binding
    );

    DoubleNumbersToTwoNumbersBindingConnector::connect(
                this->change->getNewData()->getFrom40To44(),
                this->change->getOldData()->getFrom40To44(),
                this->consumed->getFrom40To44(),
                this->from40To44Binding
    );

    DoubleNumbersToTwoNumbersBindingConnector::connect(
                this->change->getNewData()->getFrom45To49(),
                this->change->getOldData()->getFrom45To49(),
                this->consumed->getFrom45To49(),
                this->from45To49Binding
    );

    DoubleNumbersToTwoNumbersBindingConnector::connect(
                this->change->getNewData()->getGreaterThen50(),
                this->change->getOldData()->getGreaterThen50(),
                this->consumed->getGreaterThen50(),
                this->greaterThen50Binding
    );
}

ExtendedMeterReadingChange* ConsumedWaterCalculationBinding::getChange() const
{
    return change;
}

ExtendedMeterReading* ConsumedWaterCalculationBinding::getConsumed() const
{
    return consumed;
}

void ConsumedWaterCalculationBinding::transmit()
{
}
