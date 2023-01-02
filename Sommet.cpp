#include "Sommet.h"

/** Constructeur **/
Sommet::Sommet (int num, std::string nom, int altitude)
{
    m_numero = num ;
    m_nom = nom ;
    m_altitude = altitude ;
}

/** Accesseur numero **/
int Sommet::getNumero () const
{
    return m_numero ;
}

/** Accesseur nom **/
std::string Sommet::getNom () const
{
    return m_nom ;
}

/** Accesseur altitude **/
int Sommet::getAltitude () const
{
    return m_altitude ;
}

/** Accesseurs fait **/
bool Sommet::getFait () const
{
    return m_fait ;
}
void Sommet::setFait (bool fait)
{
    m_fait = fait ;
}

/** Accesseurs poids **/
int Sommet::getPoids () const
{
    return m_poids ;
}
void Sommet::setPoids (int pds)
{
    m_poids = pds ;
}
/** Accesseur parent **/
void Sommet::setParent (int parent)
{
    m_parent = parent ;
}

/** Accesseur liste successeurs **/
const std::vector <std::pair <Sommet*, int>>& Sommet::getSuccesseurs () const
{
    return m_successeurs ;
}

/** Setter ajouter un successeur à la liste **/
void Sommet::ajouterSuccesseurs (Sommet* sommet, int poids)
{
    m_successeurs.push_back (std::make_pair (sommet, poids)) ;
}

/** Methode affichage **/
void Sommet::afficher_sommet ()
{
    std::cout << m_nom << " (" << m_altitude << "m)" ;
}
