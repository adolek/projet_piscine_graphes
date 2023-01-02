#include "Arete.h"
#include "Header.h"

/** Constructeur **/
Arete::Arete (int num, std::string nom, std::string type, Sommet* som1, Sommet* som2,int capacite)
{
    m_numero = num ;
    m_nom = nom ;
    m_type = type ;
    m_sommet1 = som1 ;
    m_sommet2 = som2 ;
    m_capacite=capacite;
}

/** Accesseur numero **/
int Arete::getNumero () const
{
    return m_numero ;
}

/** Accesseur nom **/
std::string Arete::getNom () const
{
    return m_nom ;
}

/** Accesseur type **/
std::string Arete::getType() const
{
    return m_type;
}

/** Accesseurs mini **/
int Arete::getMini () const
{
    return m_mini ;
}
void Arete::setMini (int mini)
{
    m_mini = mini ;
}

/** Accesseurs temps ***/
int Arete::getTemps () const
{
    return m_temps ;
}
void Arete::setTemps (int temps)
{
    m_temps = temps ;
}

/** Accesseurs denivele **/
int Arete::getDenivele () const
{
    return m_denivele ;
}
void Arete::setDenivele (int denivele)
{
    m_denivele = denivele ;
}

/** Accesseurs poids **/
int Arete::getPoids () const
{
    return m_poids ;
}
void Arete::setPoids (int poids)
{
    m_poids = poids ;
}

/** Accesseurs des deux sommets **/
Sommet* Arete::getSommet1 () const
{
    return m_sommet1 ;
}
Sommet* Arete::getSommet2 () const
{
    return m_sommet2 ;
}

/** Accesseurs capacite **/
int Arete::getCapacite () const
{
    return m_capacite;
}
void Arete::setCapacite (int capacite)
{
    m_capacite = capacite ;
}

/** Accesseurs flot **/
int Arete::getFlot () const
{
    return m_flot ;
}
void Arete::setFlot (int flot)
{
    m_flot = flot ;
}

/** Methode affichage **/
void Arete::afficher_arete ()
{
    gotoligcol (5+m_numero, 0) ;
    std::cout << m_numero ; // afficher le numero de l'arete
    gotoligcol (5+m_numero, 12) ;
    std::cout << m_nom ; // afficher le nom
    gotoligcol (5+m_numero, 38) ;
    std::cout << m_type ; // afficher le type
    gotoligcol (5+m_numero, 52) ;
    m_sommet1->afficher_sommet () ; // afficher le nom du sommet de départ avec son altitude
    gotoligcol (5+m_numero, 89) ;
    m_sommet2->afficher_sommet () ; // afficher le nom du sommet d'arrivé avec son altitude
    gotoligcol (5+m_numero, 126) ;
    conversion_heure (m_poids) ; // afficher le poids de l'arete (le temps de trajet en heure/minutes/secondes)
}
