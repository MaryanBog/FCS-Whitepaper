#include <iostream>
#include <cmath>

#include <fcs/fcs.h>
#include <fcs/operators/f_operator.h>
#include <fcs/operators/e_operator.h>
#include <fcs/operators/finv_operator.h>
#include <fcs/operators/g_operator.h>

using namespace fcs;

// Эмуляция привода (серво)
double simulate_servo(double current_pos, double command)
{
    // Простейшая модель: привод движется на часть команды
    double response_gain = 0.3;
    return current_pos + command * response_gain;
}

int main()
{
    // --- Создаём контроллер ---
    FCS ctrl;

    ctrl.setF(default_F);
    ctrl.setE(default_E);
    ctrl.setFInv(default_FInv);
    ctrl.setG(default_G);

    // Целевая позиция сервопривода
    double target = 45.0; // градусов

    // Текущая позиция
    double pos = 0.0;

    for (int i = 0; i < 20; i++) {

        // Отклонение
        double delta = target - pos;

        // Управляющее воздействие
        double u = ctrl.update(delta);

        // Эмуляция ответа серво
        pos = simulate_servo(pos, u);

        std::cout << "Step " << i
                  << " | delta=" << delta
                  << " | u=" << u
                  << " | pos=" << pos
                  << std::endl;
    }

    return 0;
}

