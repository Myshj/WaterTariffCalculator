#ifndef SUBTRACTIONBINDING_H
#define SUBTRACTIONBINDING_H

#include "bindings/numeric/twonumbersbinding.h"


class SubtractionBinding : public TwoNumbersBinding
{
public:
    explicit SubtractionBinding(
            QObject* parent = 0
    );

// Binding interface
protected slots:
    void transmit() override;
};

#endif // SUBTRACTIONBINDING_H
