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
            const QSharedPointer<DoubleNumber>& target,
            QObject* parent = 0
    );

    QSharedPointer<DoubleNumber> getTarget() const;

protected:
    const QSharedPointer<DoubleNumber> target;
};

#endif // NUMERICBINDING_H
