#include "doublenumbertospinboxconnector.h"

void DoubleNumberToSpinBoxConnector::connect(const DoubleNumber &number, const QDoubleSpinBox &spinBox)
{
    QObject::connect(&number, SIGNAL(valueChanged(const double)), &spinBox, SLOT(setValue(const double)));
}
