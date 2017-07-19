#include "consumedwatercalculationbinding.h"
#include <QtDebug>

ConsumedWaterCalculationBinding::ConsumedWaterCalculationBinding(
        const QSharedPointer<ExtendedMeterReadingChange>& change,
        const QSharedPointer<ExtendedMeterReading>& consumed,
        QObject *parent
) : Binding (parent),
    change(change),
    consumed(consumed),
    lessThen40Binding(
        new SubtractionBinding(
            change.data()->getNewData().data()->getLessThen40(),
            change.data()->getOldData().data()->getLessThen40(),
            consumed.data()->getLessThen40()
        )
    ),
    from40To44Binding(
        new SubtractionBinding(
            change.data()->getNewData().data()->getFrom40To44(),
            change.data()->getOldData().data()->getFrom40To44(),
            consumed.data()->getFrom40To44()
        )
    ),
    from45To49Binding(
        new SubtractionBinding(
            change.data()->getNewData().data()->getFrom45To49(),
            change.data()->getOldData().data()->getFrom45To49(),
            consumed.data()->getFrom45To49()
        )
    ),
    greaterThen50Binding(
        new SubtractionBinding(
            change.data()->getNewData().data()->getGreaterThen50(),
            change.data()->getOldData().data()->getGreaterThen50(),
            consumed.data()->getGreaterThen50()
        )
    )
{
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
}
