#include "extendedmeterreadinginputsession.h"

ExtendedMeterReadingInputSession::ExtendedMeterReadingInputSession(
        QObject *parent
) : QObject(parent),
    change(new ExtendedMeterReadingChange(this)),
    tariffs(new TariffsForWater(this))
{

}

ExtendedMeterReadingChange* ExtendedMeterReadingInputSession::getChange() const
{
    return change;
}

TariffsForWater* ExtendedMeterReadingInputSession::getTariffs() const
{
    return tariffs;
}
