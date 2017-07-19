#ifndef JSONUTILITIES_H
#define JSONUTILITIES_H

#include <QJsonObject>

#include "doublenumber.h"
#include "extendedmeterreading.h"
#include "extendedmeterreadingchange.h"
#include "tariffsforwater.h"
#include "extendedmeterreadinginputsession.h"
#include "session.h"


class JsonUtilities
{
public:


    static QJsonObject saveDoubleNumber(const DoubleNumber& doubleNumber)
    {
        QJsonObject ret;

        ret["type"] = "DoubleNumber";
        ret["value"] = doubleNumber.getValue();

        return ret;
    }

    static QJsonObject saveExtendedMeterReading(const ExtendedMeterReading& extendedMeterReading)
    {
        QJsonObject ret;

        ret["type"] = "ExtendedMeterReading";
        ret["lessThen40"] = saveDoubleNumber(*extendedMeterReading.getLessThen40());
        ret["from40T044"] = saveDoubleNumber(*extendedMeterReading.getFrom40To44());
        ret["from45Tp49"] = saveDoubleNumber(*extendedMeterReading.getFrom45To49());
        ret["greaterThen50"] = saveDoubleNumber(*extendedMeterReading.getGreaterThen50());

        return ret;
    }

    static QJsonObject saveExtendedMeterReadingChange(const ExtendedMeterReadingChange& extendedMeterReadingChange)
    {
        QJsonObject ret;

        ret["type"] = "ExtendedMeterReadingChange";
        ret["oldData"] = saveExtendedMeterReading(*extendedMeterReadingChange.getOldData());
        ret["newData"] = saveExtendedMeterReading(*extendedMeterReadingChange.getNewData());

        return ret;
    }

    static QJsonObject saveTariffsForWater(const TariffsForWater& tariffsForWater)
    {
        QJsonObject ret;

        ret["type"] = "TariffsForWater";
        ret["cold"] = saveDoubleNumber(*tariffsForWater.getCold());
        ret["heated"] = saveDoubleNumber(*tariffsForWater.getHeated());

        return ret;
    }

    static QJsonObject saveExtendedMeterReadingInputSession(const ExtendedMeterReadingInputSession& extendedMeterReadingInputSession)
    {
        QJsonObject ret;

        ret["type"] = "ExtendedMeterReadingInputSession";
        ret["change"] = saveExtendedMeterReadingChange(*extendedMeterReadingInputSession.getChange());
        ret["tariffs"] = saveTariffsForWater(*extendedMeterReadingInputSession.getTariffs());

        return ret;
    }

    static QJsonObject saveSession(const Session& session)
    {
        QJsonObject ret;

        ret["type"] = "Session";
        ret["input"] = saveExtendedMeterReadingInputSession(*session.getInput());
        ret["consumed"] = saveExtendedMeterReading(*session.getConsumed());
        ret["price"] = saveDoubleNumber(*session.getPrice());
        ret["correctedHeatedVolume"] = saveDoubleNumber(*session.getCorrectedHeatedVolume());

        return ret;
    }

private:
    virtual ~JsonUtilities() = 0;
};

#endif // JSONUTILITIES_H
