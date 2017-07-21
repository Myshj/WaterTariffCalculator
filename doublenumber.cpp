#include "doublenumber.h"

#include <QtDebug>

DoubleNumber::DoubleNumber(const double value, QObject *parent) : QObject(parent), value(value)
{

}

double DoubleNumber::getValue() const
{
    return value;
}

void DoubleNumber::deepCopy(DoubleNumber* other)
{
    setValue(other->value);
}

void DoubleNumber::setValue(const double value)
{
    if(this->value != value){
        this->value = value;
        emit valueChanged(value);
    }
}

void DoubleNumber::resetValue(){
    setValue(0.0);
}
