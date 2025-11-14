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

        // Порядок строгий:
        // 1. FXI = F(delta)
        // 2. X' = E(FXI)
        // 3. delta' = FInv(X')
        // 4. u = G(delta')

        // Реализация будет добавлена на следующем шаге
        return 0.0;
    }

}
