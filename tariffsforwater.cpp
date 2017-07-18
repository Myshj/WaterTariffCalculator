#include "tariffsforwater.h"

TariffsForWater::TariffsForWater(
        const QSharedPointer<DoubleNumber>& cold,
        const QSharedPointer<DoubleNumber>& heated,
        QObject *parent
) : QObject(parent),
    cold(cold),
    heated(heated)
{

}

QSharedPointer<DoubleNumber> TariffsForWater::getCold() const
{
    return cold;
}

QSharedPointer<DoubleNumber> TariffsForWater::getHeated() const
{
    return heated;
}
