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
            QObject *parent = 0
    );

    ExtendedMeterReading *getConsumed() const;

    TariffsForWater *getTariffs() const;

    DoubleNumber *getPrice() const;

signals:

public slots:

    void transmit();

private:

    ExtendedMeterReading* consumed;
    TariffsForWater* tariffs;
    DoubleNumber* price;
};

#endif // WATERPRICECALCULATIONBINDING_H
