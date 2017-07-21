#ifndef CONSUMEDWATERCALCULATIONBINDING_H
#define CONSUMEDWATERCALCULATIONBINDING_H

#include <QObject>
#include <QSharedPointer>

#include "extendedmeterreadingchange.h"
#include "extendedmeterreading.h"

#include "bindings/binding.h"
#include "bindings/numeric/subtractionbinding.h"

/**
 * @brief Calculates volume of consumed water and transmits it to a given object.
 */
class ConsumedWaterCalculationBinding : public Binding
{
public:
    explicit ConsumedWaterCalculationBinding(
            QObject *parent = 0
    );

    ExtendedMeterReadingChange* getChange() const;

    ExtendedMeterReading* getConsumed() const;

signals:

public slots:

private slots:


private:

    ExtendedMeterReadingChange* change;
    ExtendedMeterReading* consumed;

    SubtractionBinding* lessThen40Binding;
    SubtractionBinding* from40To44Binding;
    SubtractionBinding* from45To49Binding;
    SubtractionBinding* greaterThen50Binding;

    // Binding interface
protected slots:
    void transmit() override;
};

#endif // CONSUMEDWATERCALCULATIONBINDING_H
