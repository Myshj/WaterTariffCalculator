#include "twonumbersbinding.h"

TwoNumbersBinding::TwoNumbersBinding(
        const QSharedPointer<DoubleNumber>& a,
        const QSharedPointer<DoubleNumber>& b,
        const QSharedPointer<DoubleNumber>& target,
        QObject *parent
): NumericBinding (target, parent),
    a(a),
    b(b)
{
    connect(a.data(), &DoubleNumber::valueChanged, this, &TwoNumbersBinding::transmit);
    connect(b.data(), &DoubleNumber::valueChanged, this, &TwoNumbersBinding::transmit);
}

QSharedPointer<DoubleNumber> TwoNumbersBinding::getA() const
{
    return a;
}

QSharedPointer<DoubleNumber> TwoNumbersBinding::getB() const
{
    return b;
}
