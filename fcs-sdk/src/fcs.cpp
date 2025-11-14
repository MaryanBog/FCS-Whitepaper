#include "fcs.h"

namespace fcs {

    // --- Конструктор ---
    FCS::FCS()
        : F(nullptr), E(nullptr), FInv(nullptr), G(nullptr)
    {}

    // --- Установка операторов ---
    void FCS::setF(FOperator f_op) {
        F = f_op;
    }

    void FCS::setE(EOperator e_op) {
        E = e_op;
    }

    void FCS::setFInv(FInvOperator finv_op) {
        FInv = finv_op;
    }

    void FCS::setG(GOperator g_op) {
        G = g_op;
    }

    // --- Основной цикл обновления ---
    double FCS::update(double delta) {

        // Базовая проверка: все операторы должны быть заданы
        if (!F || !E || !FInv || !G) {
            // В проде сюда можно повесить assert или error-code.
            // Пока — возвращаем 0 как безопасное значение.
            return 0.0;
        }

        // 1. FXI = F(delta)
        double x = F(delta);

        // 2. X' = E(FXI)
        double x_next = E(x);

        // 3. delta' = FInv(X')
        double delta_next = FInv(x_next);

        // 4. u = G(delta')
        double u = G(delta_next);

        return u;
    }

} // namespace fcs
