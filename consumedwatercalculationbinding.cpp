#include "consumedwatercalculationbinding.h"
#include <QtDebug>

ConsumedWaterCalculationBinding::ConsumedWaterCalculationBinding(
        const QSharedPointer<ExtendedMeterReadingChange>& change,
        const QSharedPointer<ExtendedMeterReading>& consumed,
        QObject *parent
) : QObject(parent),
    change(change),
    consumed(consumed)
{
    connect(change.data()->getOldData().data()->getLessThen40().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    connect(change.data()->getOldData().data()->getFrom40To44().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    connect(change.data()->getOldData().data()->getFrom45To49().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    connect(change.data()->getOldData().data()->getGreaterThen50().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);

    connect(change.data()->getNewData().data()->getLessThen40().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    connect(change.data()->getNewData().data()->getFrom40To44().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    connect(change.data()->getNewData().data()->getFrom45To49().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    connect(change.data()->getNewData().data()->getGreaterThen50().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
}

ConsumedWaterCalculationBinding::~ConsumedWaterCalculationBinding()
{
    disconnect(change.data()->getOldData().data()->getLessThen40().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    disconnect(change.data()->getOldData().data()->getFrom40To44().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    disconnect(change.data()->getOldData().data()->getFrom45To49().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    disconnect(change.data()->getOldData().data()->getGreaterThen50().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);

    disconnect(change.data()->getNewData().data()->getLessThen40().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    disconnect(change.data()->getNewData().data()->getFrom40To44().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    disconnect(change.data()->getNewData().data()->getFrom45To49().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
    disconnect(change.data()->getNewData().data()->getGreaterThen50().data(), &DoubleNumber::valueChanged, this, &ConsumedWaterCalculationBinding::transmit);
}

QSharedPointer<ExtendedMeterReadingChange> ConsumedWaterCalculationBinding::getChange() const
{
    return change;
}

QSharedPointer<ExtendedMeterReading> ConsumedWaterCalculationBinding::getConsumed() const
{
    return consumed;
}

void ConsumedWaterCalculationBinding::transmit()
{
    qDebug() << "Consumed water transmitted!";
    auto oldData = change.data()->getOldData().data();
    auto newData = change.data()->getNewData().data();

    auto consumedLessThen40 = newData->getLessThen40().data()->getValue() - oldData->getLessThen40().data()->getValue();
    auto consumedFrom40To44 = newData->getFrom40To44().data()->getValue() - oldData->getFrom40To44().data()->getValue();
    auto consumedFrom45To49 = newData->getFrom45To49().data()->getValue() - oldData->getFrom45To49().data()->getValue();
    auto consumedGreaterThen50 = newData->getGreaterThen50().data()->getValue() - oldData->getGreaterThen50().data()->getValue();

    consumed.data()->getLessThen40().data()->setValue(consumedLessThen40);
    consumed.data()->getFrom40To44().data()->setValue(consumedFrom40To44);
    consumed.data()->getFrom45To49().data()->setValue(consumedFrom45To49);
    consumed.data()->getGreaterThen50().data()->setValue(consumedGreaterThen50);
}
