#ifndef DOUBLESPINBOXESTOEXTENDEDMETERREADINGCONNECTOR_H
#define DOUBLESPINBOXESTOEXTENDEDMETERREADINGCONNECTOR_H

#include <QDoubleSpinBox>

#include "extendedmeterreading.h"


/**
 * @brief The DoubleSpinboxesToExtendedMeterReadingConnector class establishes connection from spinboxes to actual data.
 */
class DoubleSpinboxesToExtendedMeterReadingConnector
{
public:

    static void connect(
            const QDoubleSpinBox& lessThen40SpinBox,
            const QDoubleSpinBox& from40To44SpinBox,
            const QDoubleSpinBox& from45To49SpinBox,
            const QDoubleSpinBox& greaterThen50SpinBox,
            const ExtendedMeterReading& extendedMeterReading
    );

private:
    virtual ~DoubleSpinboxesToExtendedMeterReadingConnector() = 0;
};

#endif // DOUBLESPINBOXESTOEXTENDEDMETERREADINGCONNECTOR_H
