#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "include/table_symboles.h"

class expression
{
    public:
        expression();
        virtual ~expression();
        virtual void afficher(std::ostream& os = std::cout) = 0;
        virtual void afficher_pinv(std::ostream& os = std::cout) = 0;
        virtual float calculer() = 0;
		virtual expression* simplifier() = 0;
		virtual float evaluer(const table_symboles& table) const = 0;
    protected:

    private:
};

#endif // EXPRESSION_H

/*
template<typename T> class Singleton
{
    public:
        static T& Instance()
        {
            static T theSingleInstance; // suppose que T a un constructeur par défaut
            return theSingleInstance;
        }
};

class expression : public Singleton<expression>
{
    private:
        expression();
        virtual ~expression();
    friend class Singleton<expression>;
    public:
        virtual void afficher(std::ostream& os = std::cout) = 0;
        virtual void afficher_pinv(std::ostream& os = std::cout) = 0;
        virtual float calculer() = 0;
		virtual expression* simplifier() = 0;
    protected:
};
*/
