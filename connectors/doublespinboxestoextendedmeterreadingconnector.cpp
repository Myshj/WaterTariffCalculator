#include "doublespinboxestoextendedmeterreadingconnector.h"

void DoubleSpinboxesToExtendedMeterReadingConnector::connect(
        const QDoubleSpinBox& lessThen40SpinBox,
        const QDoubleSpinBox& from40To44SpinBox,
        const QDoubleSpinBox& from45To49SpinBox,
        const QDoubleSpinBox& greaterThen50SpinBox,
        const ExtendedMeterReading& extendedMeterReading
)
{
    QObject::connect(&lessThen40SpinBox, SIGNAL(valueChanged(const double)), extendedMeterReading.getLessThen40().data(), SLOT(setValue(const double)));
    QObject::connect(&from40To44SpinBox, SIGNAL(valueChanged(const double)), extendedMeterReading.getFrom40To44().data(), SLOT(setValue(const double)));
    QObject::connect(&from45To49SpinBox, SIGNAL(valueChanged(const double)), extendedMeterReading.getFrom45To49().data(), SLOT(setValue(const double)));
    QObject::connect(&greaterThen50SpinBox, SIGNAL(valueChanged(const double)), extendedMeterReading.getGreaterThen50().data(), SLOT(setValue(const double)));
}
