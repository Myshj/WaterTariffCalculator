#ifndef WATERPRICECALCULATIONBINDING_H
#define WATERPRICECALCULATIONBINDING_H

#include <QObject>
#include <QSharedPointer>

#include "extendedmeterreading.h"
#include "doublenumber.h"
#include "tariffsforwater.h"

#include "bindings/numeric/numericbinding.h"

/**
 * @brief Calculates overall price of consumed water based on given tariffs and transmits it to a given object.
 */
class WaterPriceCalculationBinding : public NumericBinding
{
    Q_OBJECT
public:
    explicit WaterPriceCalculationBinding(
            const QSharedPointer<ExtendedMeterReading> consumed,
            const QSharedPointer<TariffsForWater> tariffs,
            const QSharedPointer<DoubleNumber> price,
            QObject *parent = 0
    );

signals:

public slots:

    void transmit();

private:

    const QSharedPointer<ExtendedMeterReading> consumed;
    const QSharedPointer<TariffsForWater> tariffs;
    const QSharedPointer<DoubleNumber> price;
};

#endif // WATERPRICECALCULATIONBINDING_H
