#ifndef DIVISIONBINDING_H
#define DIVISIONBINDING_H

#include "twonumbersbinding.h"


class DivisionBinding : public TwoNumbersBinding
{
public:
    explicit DivisionBinding(
            const QSharedPointer<DoubleNumber>& a,
            const QSharedPointer<DoubleNumber>& b,
            const QSharedPointer<DoubleNumber>& target,
            QObject* parent = 0
    );

// Binding interface
protected slots:
    void transmit() override;
};

#endif // DIVISIONBINDING_H
