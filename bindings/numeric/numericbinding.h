#ifndef NUMERICBINDING_H
#define NUMERICBINDING_H

#include <QObject>
#include <QSharedPointer>

#include "bindings/binding.h"
#include "doublenumber.h"

/**
 * @brief Represents binding with numeric target.
 */
class NumericBinding : public Binding
{
public:
    explicit NumericBinding(
            QObject* parent = 0
    );

    DoubleNumber* getTarget() const;

protected:
    DoubleNumber* target;
};

#endif // NUMERICBINDING_H
