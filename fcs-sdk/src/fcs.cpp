#include "fcs/fcs.h"

namespace fcs {

    // Конструктор
    FCS::FCS()
        : F(nullptr), E(nullptr), FInv(nullptr), G(nullptr) {}

    // Установка оператора F
    void FCS::setF(FOperator f_op) {
        F = f_op;
    }

    // Установка оператора E
    void FCS::setE(EOperator e_op) {
        E = e_op;
    }

    // Установка оператора F⁻¹
    void FCS::setFInv(FInvOperator finv_op) {
        FInv = finv_op;
    }

    // Установка оператора G
    void FCS::setG(GOperator g_op) {
        G = g_op;
    }

    // Основной цикл управления
    double FCS::update(double delta) {
        if (!F || !E || !FInv || !G)
            return 0.0; // оператор не настроен

        double x  = F(delta);   // преобразование в FXI-пространство
        double xe = E(x);       // корректировка
        double d  = FInv(xe);   // обратное преобразование
        double u  = G(d);       // управляющее воздействие

        return u;
    }

} // namespace fcs

