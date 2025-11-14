#include "finv_operator.h"

namespace fcs {

    static const double kF = 1.0;

    double default_FInv(double x) {
        return x / kF;
    }

}

