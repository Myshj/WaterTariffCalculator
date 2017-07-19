#include "extendedmeterreadingtodoublespinboxesconnector.h"

void ExtendedMeterReadingToDoubleSpinBoxesConnector::connect(
        const ExtendedMeterReading &extendedMeterReading,
        const QDoubleSpinBox &lessThen40SpinBox,
        const QDoubleSpinBox &from40To44SpinBox,
        const QDoubleSpinBox &from45To49SpinBox,
        const QDoubleSpinBox &greaterThen50SpinBox
)
{
    QObject::connect(extendedMeterReading.getLessThen40().data(), SIGNAL(valueChanged(const double)), &lessThen40SpinBox, SLOT(setValue(const double)));
    QObject::connect(extendedMeterReading.getFrom40To44().data(), SIGNAL(valueChanged(const double)), &from40To44SpinBox, SLOT(setValue(const double)));
    QObject::connect(extendedMeterReading.getFrom45To49().data(), SIGNAL(valueChanged(const double)), &from45To49SpinBox, SLOT(setValue(const double)));
    QObject::connect(extendedMeterReading.getGreaterThen50().data(), SIGNAL(valueChanged(const double)), &greaterThen50SpinBox, SLOT(setValue(const double)));
}
