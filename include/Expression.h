#ifndef EXPRESSION_H
#define EXPRESSION_H


class Expression
{
    public:
        Expression();
        virtual void afficher() = 0;
        virtual float calculer() = 0;
        virtual ~Expression();

    protected:

    private:
};

#endif // EXPRESSION_H
