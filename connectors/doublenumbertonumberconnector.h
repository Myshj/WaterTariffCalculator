#ifndef DOUBLENUMBERTONUMBERCONNECTOR_H
#define DOUBLENUMBERTONUMBERCONNECTOR_H

#include "doublenumber.h"


/**
 * @brief The DoubleNumberToNumberConnector class establishes connection between two double numbers.
 */
class DoubleNumberToNumberConnector
{

public:
    static void connect(DoubleNumber* from, DoubleNumber* to)
    {
        QObject::connect(from, SIGNAL(valueChanged(const double)), to, SLOT(setValue(const double)));
    }

private:
    virtual ~DoubleNumberToNumberConnector() = 0;
};

#endif // DOUBLENUMBERTONUMBERCONNECTOR_H
