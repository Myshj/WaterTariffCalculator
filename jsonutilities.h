#ifndef JSONUTILITIES_H
#define JSONUTILITIES_H

#include <QJsonObject>
#include <QSharedPointer>

#include <QString>

#include "doublenumber.h"
#include "extendedmeterreading.h"
#include "extendedmeterreadingchange.h"
#include "tariffsforwater.h"
#include "extendedmeterreadinginputsession.h"
#include "session.h"


/**
 * @brief The JsonUtilities class encapsulates static functions for saving/loading objects to/from QJsonObjects.
 */
class JsonUtilities
{

private:
    const static QString typeFieldName;
public:

    static QJsonObject saveDoubleNumber(const DoubleNumber& doubleNumber)
    {
        QJsonObject ret;

        ret[typeFieldName] = "DoubleNumber";
        ret["value"] = doubleNumber.getValue();

        return ret;
    }

    static DoubleNumber* loadDoubleNumber(const QJsonObject& json)
    {
        auto ret = new DoubleNumber();
        ret->setValue(json["value"].toDouble());
        return ret;
    }

    static QJsonObject saveExtendedMeterReading(const ExtendedMeterReading& extendedMeterReading)
    {
        QJsonObject ret;

        ret[typeFieldName] = "ExtendedMeterReading";
        ret["lessThen40"] = saveDoubleNumber(*extendedMeterReading.getLessThen40());
        ret["from40To44"] = saveDoubleNumber(*extendedMeterReading.getFrom40To44());
        ret["from45To49"] = saveDoubleNumber(*extendedMeterReading.getFrom45To49());
        ret["greaterThen50"] = saveDoubleNumber(*extendedMeterReading.getGreaterThen50());

        return ret;
    }

    static ExtendedMeterReading* loadExtendedMeterReading(const QJsonObject& json)
    {
        auto ret = new ExtendedMeterReading();
        ret->getLessThen40()->deepCopy(
                    loadDoubleNumber(json["lessThen40"].toObject())
        );

        ret->getFrom40To44()->deepCopy(
                    loadDoubleNumber(json["from40To44"].toObject())
        );

        ret->getFrom45To49()->deepCopy(
                    loadDoubleNumber(json["from45To49"].toObject())
        );

        ret->getGreaterThen50()->deepCopy(
                    loadDoubleNumber(json["greaterThen50"].toObject())
        );

        return ret;
    }

    static QJsonObject saveExtendedMeterReadingChange(const ExtendedMeterReadingChange& extendedMeterReadingChange)
    {
        QJsonObject ret;

        ret[typeFieldName] = "ExtendedMeterReadingChange";
        ret["oldData"] = saveExtendedMeterReading(*extendedMeterReadingChange.getOldData());
        ret["newData"] = saveExtendedMeterReading(*extendedMeterReadingChange.getNewData());

        return ret;
    }

    static ExtendedMeterReadingChange* loadExtendedMeterReadingChange(const QJsonObject& json)
    {
        auto ret = new ExtendedMeterReadingChange();
        ret->getOldData()->deepCopy(
                    loadExtendedMeterReading(json["oldData"].toObject())
        );
        ret->getNewData()->deepCopy(
                    loadExtendedMeterReading(json["newData"].toObject())
        );
        return ret;
    }

    static QJsonObject saveTariffsForWater(const TariffsForWater& tariffsForWater)
    {
        QJsonObject ret;

        ret[typeFieldName] = "TariffsForWater";
        ret["cold"] = saveDoubleNumber(*tariffsForWater.getCold());
        ret["heated"] = saveDoubleNumber(*tariffsForWater.getHeated());

        return ret;
    }

    static TariffsForWater* loadTariffsForWater(const QJsonObject& json)
    {
        auto ret = new TariffsForWater();
        ret->getCold()->deepCopy(loadDoubleNumber(json["cold"].toObject()));
        ret->getHeated()->deepCopy(loadDoubleNumber(json["heated"].toObject()));
        return ret;
    }

    static QJsonObject saveExtendedMeterReadingInputSession(const ExtendedMeterReadingInputSession& extendedMeterReadingInputSession)
    {
        QJsonObject ret;

        ret[typeFieldName] = "ExtendedMeterReadingInputSession";
        ret["change"] = saveExtendedMeterReadingChange(*extendedMeterReadingInputSession.getChange());
        ret["tariffs"] = saveTariffsForWater(*extendedMeterReadingInputSession.getTariffs());

        return ret;
    }

    static ExtendedMeterReadingInputSession* loadExtendedMeterReadingInputSession(const QJsonObject& json)
    {
        auto ret = new ExtendedMeterReadingInputSession();
        ret->getChange()->deepCopy(loadExtendedMeterReadingChange(json["change"].toObject()));
        ret->getTariffs()->deepCopy(loadTariffsForWater(json["tariffs"].toObject()));
        return ret;
    }

    static QJsonObject saveSession(const Session& session)
    {
        QJsonObject ret;

        ret[typeFieldName] = "Session";
        ret["input"] = saveExtendedMeterReadingInputSession(*session.getInput());
        ret["consumed"] = saveExtendedMeterReading(*session.getConsumed());
        ret["price"] = saveDoubleNumber(*session.getPrice());
        ret["correctedHeatedVolume"] = saveDoubleNumber(*session.getCorrectedHeatedVolume());

        return ret;
    }

    static Session* loadSession(const QJsonObject& json)
    {
        auto ret = new Session();
        ret->getInput()->deepCopy(loadExtendedMeterReadingInputSession(json["input"].toObject()));
        ret->getConsumed()->deepCopy(loadExtendedMeterReading(json["consumed"].toObject()));
        ret->getPrice()->deepCopy(loadDoubleNumber(json["price"].toObject()));
        ret->getCorrectedHeatedVolume()->deepCopy(loadDoubleNumber(json["correctedHeatedVolume"].toObject()));
        return ret;
    }

private:
    virtual ~JsonUtilities() = 0;
};

#endif // JSONUTILITIES_H
