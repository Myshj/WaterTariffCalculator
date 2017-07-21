#include "doublenumberstotwonumbersbindingconnector.h"

void DoubleNumbersToTwoNumbersBindingConnector::connect(DoubleNumber *a, DoubleNumber *b, DoubleNumber *target, TwoNumbersBinding *binding)
{
    DoubleNumberToNumberConnector::connect(
                a,
                binding->getA()
                );
    DoubleNumberToNumberConnector::connect(
                b,
                binding->getB()
                );
    DoubleNumberToNumberConnector::connect(
                binding->getTarget(),
                target
                );
}
