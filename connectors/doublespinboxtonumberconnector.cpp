#include "doublespinboxtonumberconnector.h"

#include <QObject>

void DoubleSpinBoxToNumberConnector::connect(const QDoubleSpinBox &spinBox, const DoubleNumber &number)
{
    QObject::connect(&spinBox, SIGNAL(valueChanged(const double)), &number, SLOT(setValue(const double)));
}
