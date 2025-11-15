#include "fcs/operators/g_operator.h"

namespace fcs {

    // Линейный G-оператор (управляющее воздействие)
    static const double kG = 1.0;

    double default_G(double delta) {
        return kG * delta;
    }

}
