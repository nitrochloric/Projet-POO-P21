#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <Expression.h>


class Operateur : public Expression
{
    public:
        Operateur();
        virtual ~Operateur();

    protected:
        Expression* m_opG;
        Expression* m_opD;

    private:
};

#endif // OPERATEUR_H
