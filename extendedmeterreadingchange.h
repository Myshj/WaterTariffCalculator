#ifndef EXTENDEDMETERREADINGCHANGE_H
#define EXTENDEDMETERREADINGCHANGE_H

#include <QObject>
#include <QSharedPointer>

#include "extendedmeterreading.h"

/**
 * @brief Encapsulates old and new meter readings.
 */
class ExtendedMeterReadingChange : public QObject
{
    Q_OBJECT
public:
    explicit ExtendedMeterReadingChange(
            const QSharedPointer<ExtendedMeterReading>& oldData = QSharedPointer<ExtendedMeterReading>(new ExtendedMeterReading()),
            const QSharedPointer<ExtendedMeterReading>& newData = QSharedPointer<ExtendedMeterReading>(new ExtendedMeterReading()),
            QObject *parent = 0
    );

    QSharedPointer<ExtendedMeterReading> getOldData() const;

    QSharedPointer<ExtendedMeterReading> getNewData() const;

signals:

public slots:

private:
    const QSharedPointer<ExtendedMeterReading> oldData;
    const QSharedPointer<ExtendedMeterReading> newData;
};

#endif // EXTENDEDMETERREADINGCHANGE_H
