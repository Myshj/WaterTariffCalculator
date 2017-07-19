#ifndef DOUBLESPINBOXTONUMBERCONNECTOR_H
#define DOUBLESPINBOXTONUMBERCONNECTOR_H

#include <QDoubleSpinBox>

#include "doublenumber.h"


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
