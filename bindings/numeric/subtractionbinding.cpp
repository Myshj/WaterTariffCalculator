#include "subtractionbinding.h"

SubtractionBinding::SubtractionBinding(
        QObject *parent
) : TwoNumbersBinding (parent)
{

}

void SubtractionBinding::transmit()
{
    const double aValue = a->getValue();
    const double bValue = b->getValue();

    target->setValue(aValue - bValue);
}
