#include "twonumbersbinding.h"

TwoNumbersBinding::TwoNumbersBinding(
        QObject *parent
): NumericBinding (parent),
    a(new DoubleNumber(0.0, this)),
    b(new DoubleNumber(0.0, this))
{
    connect(a, &DoubleNumber::valueChanged, this, &TwoNumbersBinding::transmit);
    connect(b, &DoubleNumber::valueChanged, this, &TwoNumbersBinding::transmit);
}

DoubleNumber* TwoNumbersBinding::getA() const
{
    return a;
}

DoubleNumber* TwoNumbersBinding::getB() const
{
    return b;
}
