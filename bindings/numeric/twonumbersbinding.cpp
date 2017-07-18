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
    connect(a.data(), SIGNAL(valueChanged(const double)), this, SLOT(transmit()));
    connect(b.data(), SIGNAL(valueChanged(const double)), this, SLOT(transmit()));
}

QSharedPointer<DoubleNumber> TwoNumbersBinding::getA() const
{
    return a;
}

QSharedPointer<DoubleNumber> TwoNumbersBinding::getB() const
{
    return b;
}
