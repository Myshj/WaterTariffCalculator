#include "numericbinding.h"

NumericBinding::NumericBinding(
        QObject *parent
): Binding (parent),
    target(new DoubleNumber(0.0, this))
{

}

DoubleNumber* NumericBinding::getTarget() const
{
    return target;
}
