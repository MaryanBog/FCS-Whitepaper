#include "fcs/operators/e_operator.h"

namespace fcs {

    // Линейный E-оператор (степень корректировки)
    static const double alpha = 0.8;

    double default_E(double x) {
        return alpha * x;
    }

}
