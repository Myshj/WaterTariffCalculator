#include "tariffsforwater.h"

TariffsForWater::TariffsForWater(
        QObject *parent
) : QObject(parent),
    cold(new DoubleNumber(0.0, this)),
    heated(new DoubleNumber(0.0, this))
{

}

DoubleNumber* TariffsForWater::getCold() const
{
    return cold;
}

DoubleNumber* TariffsForWater::getHeated() const
{
    return heated;
}
