#ifndef LOG_NEPERIEN_H
#define LOG_NEPERIEN_H

#include "operateur.h"

class log_neperien : public operateur
{
public:
    log_neperien();
    log_neperien(expression* arg){m_opg=arg;}
    virtual ~log_neperien();

    void afficher() override;
    void afficher_pinv() override;
    float calculer() override;

    protected:

    private:
};

#endif // LOG_NEPERIEN_H
