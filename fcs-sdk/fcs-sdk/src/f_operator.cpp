#include "fcs/operators/f_operator.h"

namespace fcs {

    // Линейный F-оператор
    static const double kF = 1.0;

    double default_F(double delta) {
        return kF * delta;
    }

}
