#ifndef EXPRESSION_H
#define EXPRESSION_H


class expression
{
public:
    expression();
    virtual ~expression();
    virtual void afficher() = 0;
    virtual void afficher_pinv() = 0;
    virtual float calculer() = 0;

protected:

private:
};

#endif // EXPRESSION_H
