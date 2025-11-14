#include "g_operator.h"

namespace fcs {

    static const double kG = 1.0;  // коэффициент управления

    double default_G(double delta) {
        return kG * delta;
    }

}

