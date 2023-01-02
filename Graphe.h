#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

/*** Includes ***/
#include "Arete.h"
#include "Sommet.h"
#include "Reference.h"
#include "Header.h"
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>

/*** Classe Graphe ***/
class Graphe
{
private :
    int m_ordre ; // nombre total de sommets
    int m_taille ; // nombre total d'arete
    std::vector <Sommet*> m_sommets ; //liste des sommets (vecteur de pointeurs sur Sommet)
    std::vector <Arete*> m_aretes ; // liste des aretes (vecteur de pointeurs sur Arete)
    std::vector <Arete*> m_descente ; // liste des descentes
    std::vector <Arete*> m_remontee ; // liste des remontees
    std::vector <Refer*> m_reference; // liste des informations de reference
    std::vector <std::string> m_params ; // parametre a modifier

public :
    /** Constructeur **/
    Graphe (std::string nomFichier) ;
    Graphe () ;

    /** Destructeur **/
    ~Graphe () ;

    /** M�thode remplir un graphe **/
    void remplirGraphe (std::string nomFichier, std::string nomFichier2) ;

    /** M�thode pour modifier les param�tres **/
    void ajouterParam (std::string param) ;

    /** M�thode d'affichage **/
    void afficher () const ;

    /** M�thode trajets de depart et d'arrivee **/
    void afficherTrajets() const ;

    /** M�thode modification temps trajet **/
    void modification_temps () ;

    /** M�thode modification temps trajet descente **/
    void modification_temps_descente (std::string type) ;

    /** M�thode modification temps trajet remontee **/
    void modification_temps_remontee (std::string type) ;

    /** M�thode affichage modification **/
    void affichage_modification () ;

    /** M�thode calcul temps **/
    void calcul_temps (Arete* a) ;

    /** M�thode algorithme BFS **/
    std::vector<int> parcours_bfs(int initial) ;
    bool parcours_bfs_bool(int s, int t, std::vector<int>& parent);
    void affichage_bfs(std::vector<int> res, unsigned int somInit) ;

    /** M�thode d'algorithme de Dijkstra **/
    std::vector <int> algorithme_dijkstra (int debut, int fin) ;
    void affichage_dijkstra(std::vector<int> res, int a, int b) ;

    /** M�thode algorithme Ford-Fulkerson **/
    int algorithme_fordFulkerson (int source, int puits) ;
    void affichage_fordFulkerson (int flot, int source, int puits) ;
};

#endif // GRAPHE_H_INCLUDED
