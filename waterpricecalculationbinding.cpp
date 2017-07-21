#include "waterpricecalculationbinding.h"
#include <QtDebug>

WaterPriceCalculationBinding::WaterPriceCalculationBinding(
        QObject *parent
) : NumericBinding (parent),
    consumed(new ExtendedMeterReading(this)),
    tariffs(new TariffsForWater(this)),
    price(new DoubleNumber(0.0, this))
{
    connect(consumed->getLessThen40(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);
    connect(consumed->getFrom40To44(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);
    connect(consumed->getFrom45To49(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);
    connect(consumed->getGreaterThen50(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);

    connect(tariffs->getCold(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);
    connect(tariffs->getHeated(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);
}

void WaterPriceCalculationBinding::transmit()
{
    qDebug() << "Water price transmitted!";
    const double coldWaterTariff = tariffs->getCold()->getValue();
    const double heatedWaterTariff = tariffs->getHeated()->getValue();

    const double consumedLessThen40 = consumed->getLessThen40()->getValue();
    const double consumedFrom40To44 = consumed->getFrom40To44()->getValue();
    const double consumedFrom45To49 = consumed->getFrom45To49()->getValue();
    const double consumedGreaterThen50 = consumed->getGreaterThen50()->getValue();

    const double priceToPay = consumedLessThen40 * coldWaterTariff +
            consumedFrom40To44 * heatedWaterTariff * 0.7 +
            consumedFrom45To49 * heatedWaterTariff * 0.9 +
            consumedGreaterThen50 * heatedWaterTariff;

    price->setValue(priceToPay);
    qDebug() << "Price to pay: " << priceToPay;
}

DoubleNumber *WaterPriceCalculationBinding::getPrice() const
{
    return price;
}

TariffsForWater *WaterPriceCalculationBinding::getTariffs() const
{
    return tariffs;
}

ExtendedMeterReading *WaterPriceCalculationBinding::getConsumed() const
{
    return consumed;
}
