#include "fcs/operators/finv_operator.h"

namespace fcs {

    // Обратный к F оператор (если F = kF * x)
    static const double kF = 1.0;

    double default_FInv(double x) {
        return x / kF;
    }

}
