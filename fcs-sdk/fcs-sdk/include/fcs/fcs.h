#ifndef FCS_SDK_FCS_H
#define FCS_SDK_FCS_H

namespace fcs {

    // --- Типы операторов ---
    typedef double (*FOperator)(double);
    typedef double (*EOperator)(double);
    typedef double (*FInvOperator)(double);
    typedef double (*GOperator)(double);

    // --- Основной класс FCS ---
    class FCS {
    public:
        // Конструктор
        FCS();

        // Инициализация операторов
        void setF(FOperator f_op);
        void setE(EOperator e_op);
        void setFInv(FInvOperator finv_op);
        void setG(GOperator g_op);

        // Основная функция обновления
        double update(double delta);

    private:
        FOperator F;
        EOperator E;
        FInvOperator FInv;
        GOperator G;
    };

} // namespace fcs

#endif // FCS_SDK_FCS_H
