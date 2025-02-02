#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "include/expression.h"


class operateur : public expression
{
    public:
        operateur();
        virtual ~operateur();

        expression* Getopg() { return m_opg; }
        void Setopg(expression* val) { m_opg = val; }
        expression* Getopd() { return m_opd; }
        void Setopd(expression* val) { m_opd = val; }

        expression* m_opg;
        expression* m_opd;

    protected:

    private:
};

#endif // OPERATEUR_H
