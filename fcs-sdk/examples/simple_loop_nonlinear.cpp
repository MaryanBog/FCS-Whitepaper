#include <iostream>
#include <cmath>

#include <fcs/fcs.h>
#include <fcs/operators/f_operator.h>
#include <fcs/operators/e_operator.h>
#include <fcs/operators/finv_operator.h>
#include <fcs/operators/g_operator.h>

using namespace fcs;

// Нелинейный G с насыщением по "тяге"
double nonlinear_G(double delta)
{
    // базовый линейный усилитель
    double k = 1.0;
    double u = k * delta;

    // мягкая насыщение через tanh
    // ограничиваем управление диапазоном [-0.5, 0.5]
    double umax = 0.5;
    return umax * std::tanh(u / umax);
}

int main()
{
    FCS controller;

    // Оставляем стандартные F, E, FInv
    controller.setF(default_F);
    controller.setE(default_E);
    controller.setFInv(default_FInv);

    // Вместо default_G используем наш нелинейный
    controller.setG([](double d) {
        return nonlinear_G(d);
    });

    // Начальная ошибка
    double delta = 3.0; // больше, чем раньше, чтобы увидеть насыщение

    std::cout << "Nonlinear FXI–Δ–E test with saturated G\n";

    for (int i = 0; i < 20; i++) {
        double u = controller.update(delta);

        // простая модель "процесса": новое дельта = старое - управление
        delta = delta - u;

        std::cout << "Step " << i
                  << " | u = " << u
                  << " | delta = " << delta
                  << std::endl;
    }

    return 0;
}
