#ifndef DOUBLENUMBER_H
#define DOUBLENUMBER_H

#include <QObject>

/**
 * @brief Encapsulates double number with notifier.
 */
class DoubleNumber : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double value READ getValue WRITE setValue NOTIFY valueChanged RESET resetValue)
public:
    explicit DoubleNumber(const double value = 0.0, QObject *parent = 0);

    double getValue() const;

signals:
    void valueChanged();

public slots:

    void setValue(const double value);
    void resetValue(){
        setValue(0.0);
    }

private:
    double value;
};

#endif // DOUBLENUMBER_H
