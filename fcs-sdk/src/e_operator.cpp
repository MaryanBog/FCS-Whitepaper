#include "e_operator.h"

namespace fcs {

    static const double alpha = 0.8;  // степень сжатия

    double default_E(double x) {
        return alpha * x;
    }

}

