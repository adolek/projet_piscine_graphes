#ifndef REFERENCE_H_INCLUDED
#define REFERENCE_H_INCLUDED

/*** Includes ***/
#include "Sommet.h"
#include "Arete.h"

/*** Classe Refer ***/
class Refer
{
private :
    std::string m_type ; // type d'arete
    int m_temps ; // temps par denivele
    int m_distance ; // denivele
    int m_mini ; // temps supplementaire
    int m_capacite; // capacite de reference en fonction du type d'arete

public:
    /** Constructeur **/
    Refer (std::string type, int temps, int distance, int mini, int capacite) ;

    /** Accesseurs mini **/
    int getMini () const ;
    void setMini (int mini) ;

    /** Accesseur type **/
    std::string getType () const ;

    /** Accesseurs temps **/
    int getTemps () const ;
    void setTemps (int tps) ;

    /** Accesseur distance **/
    int getDistance () const ;

    /** Accesseur capacite **/
    int getCapacite () const ;
};

#endif // REFERENCE_H_INCLUDED
