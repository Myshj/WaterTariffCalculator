#ifndef TWONUMBERSBINDING_H
#define TWONUMBERSBINDING_H

#include <QSharedPointer>

#include "bindings/numeric/numericbinding.h"
#include "doublenumber.h"

class TwoNumbersBinding : public NumericBinding
{
public:
    explicit TwoNumbersBinding(
            const QSharedPointer<DoubleNumber>& a,
            const QSharedPointer<DoubleNumber>& b,
            const QSharedPointer<DoubleNumber>& target,
            QObject* parent = 0
    );

    QSharedPointer<DoubleNumber> getA() const;

    QSharedPointer<DoubleNumber> getB() const;

protected:

    const QSharedPointer<DoubleNumber> a;
    const QSharedPointer<DoubleNumber> b;
};

#endif // TWONUMBERSBINDING_H
