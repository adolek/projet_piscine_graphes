#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

/*** Includes ***/
#include "Arete.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>

/*** Classe Sommet ***/
class Sommet
{
private :
    int m_numero ; // numero du sommet
    std::string m_nom ; // nom du sommet
    int m_altitude ; // altitude du sommet
    bool m_fait = false ; // fait ou pas
    int m_poids = 9999 ; // poids
    std::vector <std::pair <Sommet*, int>> m_successeurs ; //chaque sommet possède la liste de ses successeurs (un vecteur de pointeurs sur Sommet)
    int m_parent = 0 ; // predecessur au sommet

public :
    /** Constructeur **/
    Sommet (int num, std::string nom, int altitude) ;

    /** Accesseur numero **/
    int getNumero () const ;

    /** Accesseur nom **/
    std::string getNom () const ;

    /** Accesseur altitude **/
    int getAltitude () const ;

    /** Accesseurs fait **/
    bool getFait () const ;
    void setFait (bool fait) ;

    /** Accesseurs poids **/
    int getPoids () const ;
    void setPoids (int pds) ;

    /** Accesseur : pour la liste des successeurs **/
    const std::vector <std::pair <Sommet*, int>>& getSuccesseurs () const ;

    /** Accesseur parent **/
    void setParent (int parent) ;

    /** Setter pour ajouter un successeur à la liste **/
    void ajouterSuccesseurs (Sommet* sommet, int poids) ;

    /** Methode affichage **/
    void afficher_sommet () ;
};

#endif // SOMMET_H_INCLUDED
