#include "subtractionbinding.h"

SubtractionBinding::SubtractionBinding(
        const QSharedPointer<DoubleNumber> &a,
        const QSharedPointer<DoubleNumber> &b,
        const QSharedPointer<DoubleNumber> &target,
        QObject *parent
) : TwoNumbersBinding (a, b, target, parent)
{

}

void SubtractionBinding::transmit()
{
    const double aValue = a.data()->getValue();
    const double bValue = b.data()->getValue();

    target.data()->setValue(aValue - bValue);
}
