#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

/*** Includes ***/
#include "Sommet.h"
#include <string>

/*** Classe Arete ***/
class Sommet;
class Arete
{
private :
    int m_numero ; // numero de l'arete
    std::string m_nom ; // nom de l'arete
    std::string m_type ; // type de l'arete
    int m_temps ; // temps de référence pour chaque type
    int m_mini ; // temps supplémentaire
    int m_denivele ; // denivele entre deux sommets
    Sommet* m_sommet1 ; // sommet de départ de l'arete
    Sommet* m_sommet2 ; // sommet d'arrivé de l'arete
    int m_poids ; // poids (temps du trajet) de l'arete
    int m_capacite ; // capacité de l'arete
    int m_flot ; // flot maximum de l'arete

public :
    /** Constructeur **/
    Arete (int num, std::string nom, std::string type, Sommet* som1, Sommet* som2,int capacite) ;

    /** Accesseur numero **/
    int getNumero () const ;

    /** Accesseur nom **/
    std::string getNom () const ;

    /** Accesseur type **/
    std::string getType () const ;

    /** Accesseurs mini **/
    int getMini () const ;
    void setMini (int mini);

    /** Accesseurs temps **/
    int getTemps () const ;
    void setTemps (int temps) ;

    /** Accesseurs denivele **/
    int getDenivele () const ;
    void setDenivele (int denivele) ;

    /** Accesseurs poids **/
    int getPoids () const ;
    void setPoids (int poids) ;

    /** Accesseurs des deux sommets **/
    Sommet* getSommet1 () const ;
    Sommet* getSommet2 () const ;

    /** Accesseurs capacite **/
    int getCapacite () const ;
    void setCapacite (int capacite) ;

    /** Accesseurs flot **/
    int getFlot () const ;
    void setFlot (int flot) ;

    /** Methode affichage **/
    void afficher_arete () ;
};

#endif // ARETE_H_INCLUDED
