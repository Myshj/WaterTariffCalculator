#ifndef EXTENDEDMETERREADINGTODOUBLESPINBOXESCONNECTOR_H
#define EXTENDEDMETERREADINGTODOUBLESPINBOXESCONNECTOR_H

#include <QDoubleSpinBox>

#include "extendedmeterreading.h"


/**
 * @brief The ExtendedMeterReadingToDoubleSpinBoxesConnector class establishes connection from ExtendedMeterReadingToDoubleSpinBoxesConnector to spinboxes.
 */
class ExtendedMeterReadingToDoubleSpinBoxesConnector
{
public:
    static void connect(
            const ExtendedMeterReading& extendedMeterReading,
            const QDoubleSpinBox& lessThen40SpinBox,
            const QDoubleSpinBox& from40To44SpinBox,
            const QDoubleSpinBox& from45To49SpinBox,
            const QDoubleSpinBox& greaterThen50SpinBox
    );

private:
    virtual ~ExtendedMeterReadingToDoubleSpinBoxesConnector() = 0;
};

#endif // EXTENDEDMETERREADINGTODOUBLESPINBOXESCONNECTOR_H
