#ifndef DOUBLESPINBOXTONUMBERCONNECTOR_H
#define DOUBLESPINBOXTONUMBERCONNECTOR_H

#include <QDoubleSpinBox>

#include "doublenumber.h"


/**
 * @brief The DoubleSpinBoxToNumberConnector class establishes connection betweenspinbox and actual data.
 */
class DoubleSpinBoxToNumberConnector
{
public:

    static void connect(
            const QDoubleSpinBox& spinBox,
            const DoubleNumber& number
    );

private:

    virtual ~DoubleSpinBoxToNumberConnector() = 0;
};

#endif // DOUBLESPINBOXTONUMBERCONNECTOR_H
