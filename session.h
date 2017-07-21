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
            QObject *parent = 0
    );

    ExtendedMeterReadingInputSession* getInput() const;

    ExtendedMeterReading* getConsumed() const;

    DoubleNumber* getPrice() const;

    DoubleNumber* getCorrectedHeatedVolume() const;

signals:

public slots:

    void deepCopy(Session* other)
    {
        input->deepCopy(other->input);
        consumed->deepCopy(other->consumed);
        price->deepCopy(other->price);
        correctedHeatedVolume->deepCopy(other->correctedHeatedVolume);
    }

private:
    ExtendedMeterReadingInputSession* input;
    ExtendedMeterReading* consumed;
    DoubleNumber* price;
    DoubleNumber* correctedHeatedVolume;

    ConsumedWaterCalculationBinding* consumedBinding;
    WaterPriceCalculationBinding* priceBinding;
    DivisionBinding* correctedHeatedVolumeBinding;
};

#endif // SESSION_H
