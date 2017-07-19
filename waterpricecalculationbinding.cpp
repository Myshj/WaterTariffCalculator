#include "waterpricecalculationbinding.h"
#include <QtDebug>

WaterPriceCalculationBinding::WaterPriceCalculationBinding(
        const QSharedPointer<ExtendedMeterReading> consumed,
        const QSharedPointer<TariffsForWater> tariffs,
        const QSharedPointer<DoubleNumber> price,
        QObject *parent
) : NumericBinding (price, parent),
    consumed(consumed),
    tariffs(tariffs),
    price(price)
{
    connect(consumed.data()->getLessThen40().data(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);
    connect(consumed.data()->getFrom40To44().data(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);
    connect(consumed.data()->getFrom45To49().data(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);
    connect(consumed.data()->getGreaterThen50().data(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);

    connect(tariffs.data()->getCold().data(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);
    connect(tariffs.data()->getHeated().data(), &DoubleNumber::valueChanged, this, &WaterPriceCalculationBinding::transmit);
}

void WaterPriceCalculationBinding::transmit()
{
    qDebug() << "Water price transmitted!";
    const double coldWaterTariff = tariffs.data()->getCold().data()->getValue();
    const double heatedWaterTariff = tariffs.data()->getHeated().data()->getValue();

    const double consumedLessThen40 = consumed.data()->getLessThen40().data()->getValue();
    const double consumedFrom40To44 = consumed.data()->getFrom40To44().data()->getValue();
    const double consumedFrom45To49 = consumed.data()->getFrom45To49().data()->getValue();
    const double consumedGreaterThen50 = consumed.data()->getGreaterThen50().data()->getValue();

    const double priceToPay = consumedLessThen40 * coldWaterTariff +
            consumedFrom40To44 * heatedWaterTariff * 0.7 +
            consumedFrom45To49 * heatedWaterTariff * 0.9 +
            consumedGreaterThen50 * heatedWaterTariff;

    price.data()->setValue(priceToPay);
    qDebug() << "Price to pay: " << priceToPay;
}
