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
public:
    explicit ExtendedMeterReading(
            const QSharedPointer<DoubleNumber>& lessThen40 = QSharedPointer<DoubleNumber>(new DoubleNumber()),
            const QSharedPointer<DoubleNumber>& from40To44 = QSharedPointer<DoubleNumber>(new DoubleNumber()),
            const QSharedPointer<DoubleNumber>& from45To49 = QSharedPointer<DoubleNumber>(new DoubleNumber()),
            const QSharedPointer<DoubleNumber>& greaterThen50 = QSharedPointer<DoubleNumber>(new DoubleNumber()),
            QObject *parent = 0
            );

    QSharedPointer<DoubleNumber> getLessThen40() const;

    QSharedPointer<DoubleNumber> getFrom40To44() const;

    QSharedPointer<DoubleNumber> getFrom45To49() const;

    QSharedPointer<DoubleNumber> getGreaterThen50() const;

public slots:


signals:

private:
    const QSharedPointer<DoubleNumber> lessThen40;
    const QSharedPointer<DoubleNumber> from40To44;
    const QSharedPointer<DoubleNumber> from45To49;
    const QSharedPointer<DoubleNumber> greaterThen50;
};

#endif // EXTENDEDMETERREADING_H
