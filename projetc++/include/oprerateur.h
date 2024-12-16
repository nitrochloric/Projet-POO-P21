#ifndef OPRERATEUR_H
#define OPRERATEUR_H


class oprerateur
{
    public:
        oprerateur();
        virtual ~oprerateur();

        unsigned float Get() { return m_opG; }
        void Set(unsigned float val) { m_opG = val; }
        unsigned float Get() { return m_opD; }
        void Set(unsigned float val) { m_opD = val; }

    protected:

    private:
        unsigned float m_opG;
        unsigned float m_opD;
};

#endif // OPRERATEUR_H
