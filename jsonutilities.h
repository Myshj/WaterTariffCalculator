#ifndef JSONUTILITIES_H
#define JSONUTILITIES_H

#include <QJsonObject>
#include <QSharedPointer>

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

    static QSharedPointer<DoubleNumber> loadDoubleNumber(const QJsonObject& json)
    {
        return QSharedPointer<DoubleNumber>::create(json["value"].toDouble());
    }

    static QJsonObject saveExtendedMeterReading(const ExtendedMeterReading& extendedMeterReading)
    {
        QJsonObject ret;

        ret["type"] = "ExtendedMeterReading";
        ret["lessThen40"] = saveDoubleNumber(*extendedMeterReading.getLessThen40());
        ret["from40To44"] = saveDoubleNumber(*extendedMeterReading.getFrom40To44());
        ret["from45To49"] = saveDoubleNumber(*extendedMeterReading.getFrom45To49());
        ret["greaterThen50"] = saveDoubleNumber(*extendedMeterReading.getGreaterThen50());

        return ret;
    }

    static QSharedPointer<ExtendedMeterReading> loadExtendedMeterReading(const QJsonObject& json)
    {
        return QSharedPointer<ExtendedMeterReading>::create(
                    loadDoubleNumber(json["lessThen40"].toObject()),
                    loadDoubleNumber(json["from40To44"].toObject()),
                    loadDoubleNumber(json["from45To49"].toObject()),
                    loadDoubleNumber(json["greaterThen50"].toObject())
        );
    }

    static QJsonObject saveExtendedMeterReadingChange(const ExtendedMeterReadingChange& extendedMeterReadingChange)
    {
        QJsonObject ret;

        ret["type"] = "ExtendedMeterReadingChange";
        ret["oldData"] = saveExtendedMeterReading(*extendedMeterReadingChange.getOldData());
        ret["newData"] = saveExtendedMeterReading(*extendedMeterReadingChange.getNewData());

        return ret;
    }

    static QSharedPointer<ExtendedMeterReadingChange> loadExtendedMeterReadingChange(const QJsonObject& json)
    {
        return QSharedPointer<ExtendedMeterReadingChange>::create(
                    loadExtendedMeterReading(json["oldData"].toObject()),
                    loadExtendedMeterReading(json["newData"].toObject())
        );
    }

    static QJsonObject saveTariffsForWater(const TariffsForWater& tariffsForWater)
    {
        QJsonObject ret;

        ret["type"] = "TariffsForWater";
        ret["cold"] = saveDoubleNumber(*tariffsForWater.getCold());
        ret["heated"] = saveDoubleNumber(*tariffsForWater.getHeated());

        return ret;
    }

    static QSharedPointer<TariffsForWater> loadTariffsForWater(const QJsonObject& json)
    {
        return QSharedPointer<TariffsForWater>::create(
                    loadDoubleNumber(json["cold"].toObject()),
                    loadDoubleNumber(json["heated"].toObject())
        );
    }

    static QJsonObject saveExtendedMeterReadingInputSession(const ExtendedMeterReadingInputSession& extendedMeterReadingInputSession)
    {
        QJsonObject ret;

        ret["type"] = "ExtendedMeterReadingInputSession";
        ret["change"] = saveExtendedMeterReadingChange(*extendedMeterReadingInputSession.getChange());
        ret["tariffs"] = saveTariffsForWater(*extendedMeterReadingInputSession.getTariffs());

        return ret;
    }

    static QSharedPointer<ExtendedMeterReadingInputSession> loadExtendedMeterReadingInputSession(const QJsonObject& json)
    {
        return QSharedPointer<ExtendedMeterReadingInputSession>::create(
                    loadExtendedMeterReadingChange(json["change"].toObject()),
                    loadTariffsForWater(json["tariffs"].toObject())
        );
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

    static QSharedPointer<Session> loadSession(const QJsonObject& json)
    {
        return QSharedPointer<Session>::create(
                    loadExtendedMeterReadingInputSession(json["input"].toObject()),
                    loadExtendedMeterReading(json["consumed"].toObject()),
                    loadDoubleNumber(json["price"].toObject()),
                    loadDoubleNumber(json["correctedHeatedVolume"].toObject())
        );
    }

private:
    virtual ~JsonUtilities() = 0;
};

#endif // JSONUTILITIES_H
