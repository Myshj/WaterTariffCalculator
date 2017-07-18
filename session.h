#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QSharedPointer>

#include "doublenumber.h"

#include "extendedmeterreadinginputsession.h"
#include "extendedmeterreading.h"

#include "consumedwatercalculationbinding.h"
#include "waterpricecalculationbinding.h"

/**
 * @brief Encapsulates session input, statistics and output
 */
class Session : public QObject
{
    Q_OBJECT
public:
    explicit Session(
            const QSharedPointer<ExtendedMeterReadingInputSession>& input = QSharedPointer<ExtendedMeterReadingInputSession>::create(),
            const QSharedPointer<ExtendedMeterReading>& consumed = QSharedPointer<ExtendedMeterReading>::create(),
            const QSharedPointer<DoubleNumber>& price = QSharedPointer<DoubleNumber>::create(),
            QObject *parent = 0
    );

    QSharedPointer<ExtendedMeterReadingInputSession> getInput() const;

    QSharedPointer<ExtendedMeterReading> getConsumed() const;

    QSharedPointer<ConsumedWaterCalculationBinding> getConsumedBinding() const;

    QSharedPointer<WaterPriceCalculationBinding> getPriceBinding() const;

    QSharedPointer<DoubleNumber> getPrice() const;

signals:

public slots:

private:
    const QSharedPointer<ExtendedMeterReadingInputSession> input;
    const QSharedPointer<ExtendedMeterReading> consumed;
    const QSharedPointer<DoubleNumber> price;

    const QSharedPointer<ConsumedWaterCalculationBinding> consumedBinding;
    const QSharedPointer<WaterPriceCalculationBinding> priceBinding;
};

#endif // SESSION_H
