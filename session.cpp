#include "session.h"

Session::Session(
        const QSharedPointer<ExtendedMeterReadingInputSession>& input,
        const QSharedPointer<ExtendedMeterReading>& consumed,
        const QSharedPointer<DoubleNumber>& price,
        const QSharedPointer<DoubleNumber>& correctedHeatedVolume,
        QObject *parent
) : QObject(parent),
    input(input),
    consumed(consumed),
    price(price),
    correctedHeatedVolume(correctedHeatedVolume),
    consumedBinding(new ConsumedWaterCalculationBinding(input.data()->getChange(), consumed)),
    priceBinding(new WaterPriceCalculationBinding(consumed, input.data()->getTariffs(), price)),
    correctedHeatedVolumeBinding(new DivisionBinding(price, input.data()->getTariffs().data()->getHeated(), correctedHeatedVolume))
{

}

QSharedPointer<ExtendedMeterReadingInputSession> Session::getInput() const
{
    return input;
}

QSharedPointer<ExtendedMeterReading> Session::getConsumed() const
{
    return consumed;
}

QSharedPointer<ConsumedWaterCalculationBinding> Session::getConsumedBinding() const
{
    return consumedBinding;
}

QSharedPointer<WaterPriceCalculationBinding> Session::getPriceBinding() const
{
    return priceBinding;
}

QSharedPointer<DoubleNumber> Session::getPrice() const
{
    return price;
}

QSharedPointer<DoubleNumber> Session::getCorrectedHeatedVolume() const
{
    return correctedHeatedVolume;
}
