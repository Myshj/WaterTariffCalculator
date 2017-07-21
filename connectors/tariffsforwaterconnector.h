#ifndef TARIFFSFORWATERCONNECTOR_H
#define TARIFFSFORWATERCONNECTOR_H

#include "tariffsforwater.h"
#include "doublenumbertonumberconnector.h"

class TariffsForWaterConnector
{
public:

    static void connect(
            TariffsForWater* from,
            TariffsForWater* to
    )
    {
        DoubleNumberToNumberConnector::connect(
                    from->getCold(),
                    to->getCold()
        );

        DoubleNumberToNumberConnector::connect(
                    from->getHeated(),
                    to->getHeated()
        );
    }

private:
    virtual ~TariffsForWaterConnector() = 0;
};

#endif // TARIFFSFORWATERCONNECTOR_H
