#include "rota.h"

// Rota constructor
Rota::Rota(int mon, int tue, int wed)
{
    SetRota(mon, tue, wed);
}

Rota::Rota()
{
    m_monday = 3;
    m_tuesday = 4;
    m_wednesday = 5;
}

//Rota member function
void Rota::SetRota(int mon, int tue, int wed)
{
    m_monday = mon;
    m_tuesday = tue;
    m_wednesday = wed;
}

int Rota::getMon() const
{
    return m_monday;
}

int Rota::getTue() const
{
    return m_tuesday;
}

int Rota::getWed() const
{
    return m_wednesday;
}