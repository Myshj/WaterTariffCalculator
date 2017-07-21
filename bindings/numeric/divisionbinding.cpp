#include "divisionbinding.h"

DivisionBinding::DivisionBinding(
        QObject* parent
): TwoNumbersBinding (parent)
{

}

void DivisionBinding::transmit()
{
    const double aValue = a->getValue();
    const double bValue = b->getValue();

    target->setValue(aValue / bValue);
}
