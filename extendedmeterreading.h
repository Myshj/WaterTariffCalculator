#ifndef EXTENDEDMETERREADING_H
#define EXTENDEDMETERREADING_H

#include <QObject>
#include <QSharedPointer>

#include "doublenumber.h"

/**
 * @brief Encapsulates data from multitariff meter.
 */
class ExtendedMeterReading : public QObject
{
    Q_OBJECT
    Q_PROPERTY(DoubleNumber* lessThen40 READ getLessThen40)
    Q_PROPERTY(DoubleNumber* from40To44 READ getFrom40To44)
    Q_PROPERTY(DoubleNumber* from45To49 READ getFrom45To49)
    Q_PROPERTY(DoubleNumber* greaterThen50 READ getGreaterThen50)
public:
    explicit ExtendedMeterReading(
            QObject *parent = 0
    );

    DoubleNumber* getLessThen40() const;

    DoubleNumber* getFrom40To44() const;

    DoubleNumber* getFrom45To49() const;

    DoubleNumber* getGreaterThen50() const;

public slots:

    void deepCopy(ExtendedMeterReading* other);

signals:

private:
    DoubleNumber* lessThen40;
    DoubleNumber* from40To44;
    DoubleNumber* from45To49;
    DoubleNumber* greaterThen50;
};

#endif // EXTENDEDMETERREADING_H
