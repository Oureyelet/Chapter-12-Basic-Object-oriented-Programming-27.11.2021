#ifndef DATE_H
#define DATE_H

class Rota
{
private:
    int m_monday{};
    int m_tuesday{};
    int m_wednesday{};

public:
    Rota(int mon, int tue, int wed);

    void SetRota(int mon, int tue, int wed);

    int getMon() { return m_monday; }
    int getTue() { return m_tuesday; }
    int getWed() { return m_wednesday; }
};

#endif // end DATE_H

