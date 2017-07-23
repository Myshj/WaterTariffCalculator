#ifndef DOUBLENUMBERSTOTWONUMBERSBINDINGCONNECTOR_H
#define DOUBLENUMBERSTOTWONUMBERSBINDINGCONNECTOR_H

#include "doublenumber.h"
#include "bindings/numeric/twonumbersbinding.h"

#include "connectors/doublenumbertonumberconnector.h"


/**
 * @brief The DoubleNumbersToTwoNumbersBindingConnector class establishes connection between binding members and actual data.
 */
class DoubleNumbersToTwoNumbersBindingConnector
{
public:
    virtual ~DoubleNumbersToTwoNumbersBindingConnector() = 0;

    static void connect(
            DoubleNumber* a,
            DoubleNumber* b,
            DoubleNumber* target,
            TwoNumbersBinding* binding
    );
};

#endif // DOUBLENUMBERSTOTWONUMBERSBINDINGCONNECTOR_H
