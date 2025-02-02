#ifndef LOG_NEPERIEN_H
#define LOG_NEPERIEN_H

#include "include/operateur.h"

class log_neperien : public operateur
{
public:
    log_neperien();
    log_neperien(expression* arg){m_opg=arg;}
    virtual ~log_neperien();

    void afficher(std::ostream& os = std::cout) override;
    void afficher_pinv(std::ostream& os = std::cout) override;
    float calculer() override;
    expression* simplifier() override {return this;}
    float evaluer(const table_symboles& table) const override;
    protected:

    private:
};

#endif // LOG_NEPERIEN_H
