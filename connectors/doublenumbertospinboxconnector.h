#ifndef DOUBLENUMBERTOSPINBOXCONNECTOR_H
#define DOUBLENUMBERTOSPINBOXCONNECTOR_H

#include <QDoubleSpinBox>

#include "doublenumber.h"


/**
 * @brief The DoubleNumberToSpinBoxConnector class establishes connection from double number to spinbox.
 */
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
