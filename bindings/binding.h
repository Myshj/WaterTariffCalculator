#ifndef BINDING_H
#define BINDING_H

#include <QObject>

/**
 * @brief Represents general data binding.
 */
class Binding : public QObject
{
    Q_OBJECT
public:

    explicit Binding(QObject* parent = 0);

signals:

protected slots:

    virtual void transmit() = 0;
};

#endif // BINDING_H
