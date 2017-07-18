#include "extendedmeterreading.h"

ExtendedMeterReading::ExtendedMeterReading(
        const QSharedPointer<DoubleNumber>& lessThen40,
        const QSharedPointer<DoubleNumber>& from40To44,
        const QSharedPointer<DoubleNumber>& from45To49,
        const QSharedPointer<DoubleNumber>& greaterThen50,
        QObject *parent
        ) :
    QObject(parent),
    lessThen40(lessThen40),
    from40To44(from40To44),
    from45To49(from45To49),
    greaterThen50(greaterThen50)
{

}

QSharedPointer<DoubleNumber> ExtendedMeterReading::getLessThen40() const
{
    return lessThen40;
}

QSharedPointer<DoubleNumber> ExtendedMeterReading::getFrom40To44() const
{
    return from40To44;
}

QSharedPointer<DoubleNumber> ExtendedMeterReading::getFrom45To49() const
{
    return from45To49;
}

QSharedPointer<DoubleNumber> ExtendedMeterReading::getGreaterThen50() const
{
    return greaterThen50;
}
