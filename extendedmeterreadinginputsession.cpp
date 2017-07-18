#include "extendedmeterreadinginputsession.h"

ExtendedMeterReadingInputSession::ExtendedMeterReadingInputSession(
        const QSharedPointer<ExtendedMeterReadingChange>& change,
        const QSharedPointer<TariffsForWater>& tariffs,
        QObject *parent
) : QObject(parent),
    change(change),
    tariffs(tariffs)
{

}

QSharedPointer<ExtendedMeterReadingChange> ExtendedMeterReadingInputSession::getChange() const
{
    return change;
}

QSharedPointer<TariffsForWater> ExtendedMeterReadingInputSession::getTariffs() const
{
    return tariffs;
}
