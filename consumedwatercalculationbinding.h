#ifndef CONSUMEDWATERCALCULATIONBINDING_H
#define CONSUMEDWATERCALCULATIONBINDING_H

#include <QObject>
#include <QSharedPointer>

#include "extendedmeterreadingchange.h"
#include "extendedmeterreading.h"

/**
 * @brief Calculates volume of consumed water and writes it to a given object.
 */
class ConsumedWaterCalculationBinding : public QObject
{
    Q_OBJECT
public:
    explicit ConsumedWaterCalculationBinding(
            const QSharedPointer<ExtendedMeterReadingChange>& change,
            const QSharedPointer<ExtendedMeterReading>& consumed,
            QObject *parent = 0
    );

    ~ConsumedWaterCalculationBinding();

    QSharedPointer<ExtendedMeterReadingChange> getChange() const;

    QSharedPointer<ExtendedMeterReading> getConsumed() const;

signals:

public slots:

private slots:
    void transmit();

private:

    const QSharedPointer<ExtendedMeterReadingChange> change;
    const QSharedPointer<ExtendedMeterReading> consumed;
};

#endif // CONSUMEDWATERCALCULATIONBINDING_H
