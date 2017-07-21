#ifndef TWONUMBERSBINDING_H
#define TWONUMBERSBINDING_H

#include <QSharedPointer>

#include "bindings/numeric/numericbinding.h"
#include "doublenumber.h"

class TwoNumbersBinding : public NumericBinding
{
public:
    explicit TwoNumbersBinding(
            QObject* parent = 0
    );

    DoubleNumber* getA() const;

    DoubleNumber* getB() const;

protected:

    DoubleNumber* a;
    DoubleNumber* b;
};

#endif // TWONUMBERSBINDING_H
