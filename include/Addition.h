#ifndef ADDITION_H
#define ADDITION_H

#include <Operateur.h>
#include <iostream>

using namespace std;

class Addition : public Operateur
{
    public:
        Addition();
        inline void afficher() override { m_opG->afficher(); cout << "+"; m_opD->afficher(); };
        inline float calculer() override {return m_opG->calculer()+m_opD->calculer();};
        virtual ~Addition();

    protected:

    private:
};

#endif // ADDITION_H
