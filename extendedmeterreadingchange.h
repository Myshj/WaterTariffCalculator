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
    Q_PROPERTY(ExtendedMeterReading* oldData READ getOldData)
    Q_PROPERTY(ExtendedMeterReading* newData READ getNewData)
public:
    explicit ExtendedMeterReadingChange(
            QObject *parent = 0
    );

    ExtendedMeterReading* getOldData() const;

    ExtendedMeterReading* getNewData() const;

signals:

public slots:

    void deepCopy(ExtendedMeterReadingChange* other)
    {
        oldData->deepCopy(other->oldData);
        newData->deepCopy(other->newData);
    }

private:
    ExtendedMeterReading* oldData;
    ExtendedMeterReading* newData;
};

#endif // EXTENDEDMETERREADINGCHANGE_H
