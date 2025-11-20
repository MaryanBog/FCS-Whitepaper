#include <iostream>

#include <fcs/fcs.h>
#include <fcs/operators/f_operator.h>
#include <fcs/operators/e_operator.h>
#include <fcs/operators/finv_operator.h>
#include <fcs/operators/g_operator.h>

using namespace fcs;

int main() {

    // --- Создаём контроллер ---
    FCS controller;

    // --- Подключаем дефолтные операторы ---
    controller.setF(default_F);
    controller.setE(default_E);
    controller.setFInv(default_FInv);
    controller.setG(default_G);

    // Начальная ошибка
    double delta = 1.0;

    // --- Несколько шагов стабилизации ---
    for (int i = 0; i < 10; i++) {
        double u = controller.update(delta);   // управляющий сигнал
        delta = delta - u;                     // обновление ошибки (условное)
        std::cout << "Step " << i
                  << " | u = " << u
                  << " | new delta = " << delta
                  << std::endl;
    }

    return 0;
}
