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
public:
    explicit ExtendedMeterReadingInputSession(
            const QSharedPointer<ExtendedMeterReadingChange>& change = QSharedPointer<ExtendedMeterReadingChange>(new ExtendedMeterReadingChange()),
            const QSharedPointer<TariffsForWater>& tariffs = QSharedPointer<TariffsForWater>(new TariffsForWater()),
            QObject *parent = 0
    );

    QSharedPointer<ExtendedMeterReadingChange> getChange() const;

    QSharedPointer<TariffsForWater> getTariffs() const;

signals:

public slots:

private:
    const QSharedPointer<ExtendedMeterReadingChange> change;
    const QSharedPointer<TariffsForWater> tariffs;
};

#endif // EXTENDEDMETERREADINGINPUTSESSION_H
