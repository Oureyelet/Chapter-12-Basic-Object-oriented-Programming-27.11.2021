#ifndef ROTA_H
#define ROTA_H

class Rota
{
private:
    int m_monday{};
    int m_tuesday{};
    int m_wednesday{};

public:
    Rota();

    Rota(int mon, int tue, int wed);

    void SetRota(int mon, int tue, int wed);

    int getMon() const;
    int getTue() const; 
    int getWed() const; 
};

#endif // end ROTA_H

