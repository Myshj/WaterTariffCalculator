#ifndef EXTENDEDMETERREADINGINPUTSESSION_H
#define EXTENDEDMETERREADINGINPUTSESSION_H

#include <QObject>
#include <QSharedPointer>

#include "extendedmeterreadingchange.h"
#include "tariffsforwater.h"

/**
 * @brief Encapsulates meter reading change and actual tariffs.
 */
class ExtendedMeterReadingInputSession : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ExtendedMeterReadingChange* change READ getChange)
    Q_PROPERTY(TariffsForWater* tariffs READ getTariffs)
public:
    explicit ExtendedMeterReadingInputSession(
            QObject *parent = 0
    );

    ExtendedMeterReadingChange* getChange() const;

    TariffsForWater* getTariffs() const;

signals:

public slots:

    void deepCopy(ExtendedMeterReadingInputSession* other)
    {
        change->deepCopy(other->change);
        tariffs->deepCopy(other->tariffs);
    }

private:
    ExtendedMeterReadingChange* change;
    TariffsForWater* tariffs;
};

#endif // EXTENDEDMETERREADINGINPUTSESSION_H
