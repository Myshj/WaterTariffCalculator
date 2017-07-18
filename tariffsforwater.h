#ifndef TARIFFSFORWATER_H
#define TARIFFSFORWATER_H

#include <QObject>
#include <QSharedPointer>
#include "doublenumber.h"

/**
 * @brief Encapsulates pair of tariffs for cold and heated water.
 */
class TariffsForWater : public QObject
{
    Q_OBJECT
public:
    explicit TariffsForWater(
            const QSharedPointer<DoubleNumber>& cold = QSharedPointer<DoubleNumber>(new DoubleNumber()),
            const QSharedPointer<DoubleNumber>& heated = QSharedPointer<DoubleNumber>(new DoubleNumber()),
            QObject *parent = 0
    );

    QSharedPointer<DoubleNumber> getCold() const;

    QSharedPointer<DoubleNumber> getHeated() const;

signals:

public slots:

private:
    const QSharedPointer<DoubleNumber> cold;
    const QSharedPointer<DoubleNumber> heated;
};

#endif // TARIFFSFORWATER_H
