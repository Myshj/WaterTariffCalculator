#ifndef DIVISIONBINDING_H
#define DIVISIONBINDING_H

#include "twonumbersbinding.h"


/**
 * @brief The DivisionBinding class binds division of two numbers to target.
 */
class DivisionBinding : public TwoNumbersBinding
{
public:
    explicit DivisionBinding(
            QObject* parent = 0
    );

// Binding interface
protected slots:
    void transmit() override;
};

#endif // DIVISIONBINDING_H
