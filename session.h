#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QSharedPointer>

#include "doublenumber.h"

#include "extendedmeterreadinginputsession.h"
#include "extendedmeterreading.h"

#include "consumedwatercalculationbinding.h"
#include "waterpricecalculationbinding.h"

#include "bindings/numeric/divisionbinding.h"

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
            const QSharedPointer<DoubleNumber>& correctedHeatedVolume = QSharedPointer<DoubleNumber>::create(),
            QObject *parent = 0
    );

    QSharedPointer<ExtendedMeterReadingInputSession> getInput() const;

    QSharedPointer<ExtendedMeterReading> getConsumed() const;

    QSharedPointer<ConsumedWaterCalculationBinding> getConsumedBinding() const;

    QSharedPointer<WaterPriceCalculationBinding> getPriceBinding() const;

    QSharedPointer<DoubleNumber> getPrice() const;

    QSharedPointer<DoubleNumber> getCorrectedHeatedVolume() const;

signals:

public slots:

private:
    const QSharedPointer<ExtendedMeterReadingInputSession> input;
    const QSharedPointer<ExtendedMeterReading> consumed;
    const QSharedPointer<DoubleNumber> price;
    const QSharedPointer<DoubleNumber> correctedHeatedVolume;

    const QSharedPointer<ConsumedWaterCalculationBinding> consumedBinding;
    const QSharedPointer<WaterPriceCalculationBinding> priceBinding;
    const QSharedPointer<DivisionBinding> correctedHeatedVolumeBinding;
};

#endif // SESSION_H
