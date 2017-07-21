#include "extendedmeterreading.h"

ExtendedMeterReading::ExtendedMeterReading(
        QObject* parent
) :
    QObject(parent),
    lessThen40(new DoubleNumber(0.0, this)),
    from40To44(new DoubleNumber(0.0, this)),
    from45To49(new DoubleNumber(0.0, this)),
    greaterThen50(new DoubleNumber(0.0, this))
{

}

DoubleNumber* ExtendedMeterReading::getLessThen40() const
{
    return lessThen40;
}

DoubleNumber* ExtendedMeterReading::getFrom40To44() const
{
    return from40To44;
}

DoubleNumber* ExtendedMeterReading::getFrom45To49() const
{
    return from45To49;
}

DoubleNumber* ExtendedMeterReading::getGreaterThen50() const
{
    return greaterThen50;
}

void ExtendedMeterReading::deepCopy(ExtendedMeterReading* other)
{
    lessThen40->deepCopy(other->lessThen40);
    from40To44->deepCopy(other->from40To44);
    from45To49->deepCopy(other->from45To49);
    greaterThen50->deepCopy(other->greaterThen50);
}
