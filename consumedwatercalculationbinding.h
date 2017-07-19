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
            const QSharedPointer<ExtendedMeterReadingChange>& change,
            const QSharedPointer<ExtendedMeterReading>& consumed,
            QObject *parent = 0
    );

    QSharedPointer<ExtendedMeterReadingChange> getChange() const;

    QSharedPointer<ExtendedMeterReading> getConsumed() const;

signals:

public slots:

private slots:


private:

    const QSharedPointer<ExtendedMeterReadingChange> change;
    const QSharedPointer<ExtendedMeterReading> consumed;

    const QSharedPointer<SubtractionBinding> lessThen40Binding;
    const QSharedPointer<SubtractionBinding> from40To44Binding;
    const QSharedPointer<SubtractionBinding> from45To49Binding;
    const QSharedPointer<SubtractionBinding> greaterThen50Binding;

    // Binding interface
protected slots:
    void transmit() override;
};

#endif // CONSUMEDWATERCALCULATIONBINDING_H
