#include "rota.h"

// Rota constructor
Rota::Rota(int mon, int tue, int wed)
{
    SetRota(mon, tue, wed);
}

//Rota member function
void Rota::SetRota(int mon, int tue, int wed)
{
    m_monday = mon;
    m_tuesday = tue;
    m_wednesday = wed;
}