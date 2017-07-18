#include "extendedmeterreadingchange.h"

ExtendedMeterReadingChange::ExtendedMeterReadingChange(
        const QSharedPointer<ExtendedMeterReading>& oldData,
        const QSharedPointer<ExtendedMeterReading>& newData,
        QObject *parent
) : QObject(parent),
    oldData(oldData),
    newData(newData)
{

}

QSharedPointer<ExtendedMeterReading> ExtendedMeterReadingChange::getOldData() const
{
    return oldData;
}

QSharedPointer<ExtendedMeterReading> ExtendedMeterReadingChange::getNewData() const
{
    return newData;
}
