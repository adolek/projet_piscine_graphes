#include "Reference.h"

/** Constructeur **/
Refer::Refer (std::string type, int temps, int distance, int mini, int capacite)
{
    m_type = type ;
    m_temps = temps ;
    m_distance = distance ;
    m_mini = mini ;
    m_capacite = capacite ;
}

/** Accesseurs mini **/
int Refer::getMini () const
{
    return m_mini ;
}
void Refer::setMini (int mini)
{
    m_mini = mini ;
}

/** Accesseur type **/
std::string Refer::getType () const
{
    return m_type ;
}

/** Accesseurs temps **/
int Refer::getTemps () const
{
    return m_temps ;
}
void Refer::setTemps (int tps)
{
    m_temps = tps ;
}

/** Accesseur distance **/
int Refer::getDistance () const
{
    return m_distance ;
}

/** Accesseur capacite **/
int Refer::getCapacite() const
{
    return m_capacite;
}
