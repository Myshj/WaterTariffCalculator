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
    Q_PROPERTY(DoubleNumber* cold READ getCold)
    Q_PROPERTY(DoubleNumber* heated READ getHeated)
public:
    explicit TariffsForWater(
            QObject *parent = 0
    );

    DoubleNumber* getCold() const;

    DoubleNumber* getHeated() const;

signals:

public slots:

    void deepCopy(TariffsForWater* other)
    {
        cold->deepCopy(other->cold);
        heated->deepCopy(other->heated);
    }

private:
    DoubleNumber* cold;
    DoubleNumber* heated;
};

#endif // TARIFFSFORWATER_H
