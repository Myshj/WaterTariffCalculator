#include "extendedmeterreadingchange.h"

ExtendedMeterReadingChange::ExtendedMeterReadingChange(
        QObject *parent
) : QObject(parent),
    oldData(new ExtendedMeterReading(this)),
    newData(new ExtendedMeterReading(this))
{

}

ExtendedMeterReading* ExtendedMeterReadingChange::getOldData() const
{
    return oldData;
}

ExtendedMeterReading* ExtendedMeterReadingChange::getNewData() const
{
    return newData;
}
