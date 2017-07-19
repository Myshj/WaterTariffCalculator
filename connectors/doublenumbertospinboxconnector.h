#ifndef DOUBLENUMBERTOSPINBOXCONNECTOR_H
#define DOUBLENUMBERTOSPINBOXCONNECTOR_H

#include <QDoubleSpinBox>

#include "doublenumber.h"

class DoubleNumberToSpinBoxConnector
{
public:

    static void connect(
            const DoubleNumber& number,
            const QDoubleSpinBox& spinBox
    );

private:
    virtual ~DoubleNumberToSpinBoxConnector() = 0;
};

#endif // DOUBLENUMBERTOSPINBOXCONNECTOR_H
