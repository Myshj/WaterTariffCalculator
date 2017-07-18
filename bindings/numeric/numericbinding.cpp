#include "numericbinding.h"

NumericBinding::NumericBinding(
        const QSharedPointer<DoubleNumber>& target,
        QObject *parent
): Binding (parent),
    target(target)
{

}

QSharedPointer<DoubleNumber> NumericBinding::getTarget() const
{
    return target;
}
