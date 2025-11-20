#include <iostream>

#include <fcs/fcs.h>
#include <fcs/operators/f_operator.h>
#include <fcs/operators/e_operator.h>
#include <fcs/operators/finv_operator.h>
#include <fcs/operators/g_operator.h>

using namespace fcs;

// Простейшая модель изменения высоты дрона
double simulate_drone(double altitude, double thrust)
{
    // thrust > 0 поднимает дрон, thrust < 0 опускает
    double k = 0.4;
    return altitude + thrust * k;
}

int main()
{
    // --- Контроллер FCS ---
    FCS ctrl;

    ctrl.setF(default_F);
    ctrl.setE(default_E);
    ctrl.setFInv(default_FInv);
    ctrl.setG(default_G);

    // Цель — держать высоту 10.0 метров
    double target_alt = 10.0;

    // Стартовая высота
    double alt = 0.0;

    for (int i = 0; i < 25; i++)
    {
        // Отклонение
        double delta = target_alt - alt;

        // Управляющее воздействие (тяга)
        double thrust = ctrl.update(delta);

        // Эмуляция движения дрона
        alt = simulate_drone(alt, thrust);

        std::cout
            << "Step " << i
            << " | delta=" << delta
            << " | thrust=" << thrust
            << " | altitude=" << alt
            << std::endl;
    }

    return 0;
}

