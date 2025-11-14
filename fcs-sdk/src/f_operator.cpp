#include "f_operator.h"

namespace fcs {

    static const double kF = 1.0;   // масштаб

    double default_F(double delta) {
        return kF * delta;
    }

}

