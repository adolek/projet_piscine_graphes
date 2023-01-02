#include "Graphe.h"

/*** Méthode d'affichage ***/
void Graphe::afficher () const
{
    system ("cls") ;
    gotoligcol (0, 61) ;
    std::cout << "P L A N S   D E   L A   S T A T I O N" ;
    gotoligcol (1, 59) ;
    for (int i=0 ; i<41 ; ++i)
    {
        std::cout << static_cast<char>(205) ;
    }
    gotoligcol (2, 53) ;
    std::cout << "Nombre de sommets : " << m_ordre << "          Nombre d'aretes : " << m_taille ; // affichage de l'ordre
    gotoligcol (4, 0) ;
    std::cout << "Numero" ;
    gotoligcol (5, 0) ;
    for (int i=0 ; i<6 ; ++i)
    {
        std::cout << static_cast<char>(196) ;
    }
    gotoligcol (4, 12) ;
    std::cout << "Nom" ;
    gotoligcol (5, 12) ;
    for (int i=0 ; i<3 ; ++i)
    {
        std::cout << static_cast<char>(196) ;
    }
    gotoligcol (4, 38) ;
    std::cout << "Type" ;
    gotoligcol (5, 38) ;
    for (int i=0 ; i<4 ; ++i)
    {
        std::cout << static_cast<char>(196) ;
    }
    gotoligcol (4, 52) ;
    std::cout << "Sommet 1 (avec altitude)" ;
    gotoligcol (5, 52) ;
    for (int i=0 ; i<24 ; ++i)
    {
        std::cout << static_cast<char>(196) ;
    }
    gotoligcol (4, 89) ;
    std::cout << "Sommet 2 (avec altitude)" ;
    gotoligcol (5, 89) ;
    for (int i=0 ; i<24 ; ++i)
    {
        std::cout << static_cast<char>(196) ;
    }
    gotoligcol (4, 126) ;
    std::cout << "Poids" ;
    gotoligcol (5, 126) ;
    for (int i=0 ; i<5 ; ++i)
    {
        std::cout << static_cast<char>(196) ;
    }
    for (auto elem : m_aretes) // pour chaque arete affichages des informations
    {
        elem->afficher_arete () ;
        std::cout << std::endl ;
    }
    std::cout << std::endl ;
}

/*** Methode trajets de depart et d'arrivee ***/
void Graphe::afficherTrajets () const
{
    int indice = 1 ;
    int nb = 1 ;
    int numero ;
    std::string initial ;

    system ("cls") ;
    gotoligcol (0, 63) ;
    std::cout << "C H E M I N S   P O S S I B L E S" ;
    gotoligcol (1, 61) ;
    for (int i=0 ; i<37 ; ++i)
    {
        std::cout << static_cast<char>(205) ;
    }

    gotoligcol (3, 2) ;
    std::cout << "Choix du sommet :  " ;
    std::cin >> initial ;
    numero = stoi(initial) ;

    /** Trajets qui partent du sommet **/
    gotoligcol (6, 4) ;
    if (initial == m_sommets[numero-1]->getNom())
    {
        std::cout << "Trajets qui partent du sommet " << initial << " : " ;
    }
    else
    {
        std::cout << "Trajets qui partent du sommet " << initial << " (nom : " << m_sommets[numero-1]->getNom() << ") :" ;
    }
    for(const auto& elem : m_aretes) // parcours de chaque arete
    {
        if(elem->getSommet1()->getNumero() == numero)
        {
            gotoligcol (7+indice, 6) ;
            std::cout << "Trajet no" << indice << " : ";
            gotoligcol (7+indice, 20) ;
            std::cout << " - " << elem->getNom() ;
            gotoligcol (7+indice, 40) ;
            std::cout << "(numero : " << elem->getNumero() << ")" ;
            gotoligcol (7+indice, 60) ;
            std::cout << "Type : " << elem->getType() ;
            gotoligcol (7+indice, 73) ;
            std::cout << "vers le sommet " ;
            elem->getSommet2()->afficher_sommet() ;
            indice++;
        }
    }
    carre (5, 2,150, indice+2) ;
    gotoligcol (7, 4) ;
    for (int i=0 ; i<148 ; ++i)
    {
        std::cout << static_cast<char>(196) ;
    }

    /** Trajets qui arrivent au sommet **/
    gotoligcol (11+indice, 4) ;
    if (initial == m_sommets[numero-1]->getNom())
    {
        std::cout << "Trajets qui arrivent au sommet " << initial << " : " ;
    }
    else
    {
        std::cout << "Trajets qui partent au sommet " << initial << " (nom : " << m_sommets[numero-1]->getNom() << ") :" ;
    }
    for(auto elem : m_aretes)
    {
        if(elem->getSommet2()->getNumero() == numero)
        {
            gotoligcol (12+indice+nb, 6) ;
            std::cout << "Trajet no" << nb << " : ";
            gotoligcol (12+indice+nb, 20) ;
            std::cout << " - " << elem->getNom() ;
            gotoligcol (12+indice+nb, 40) ;
            std::cout << "(numero : " << elem->getNumero() << ")" ;
            gotoligcol (12+indice+nb, 60) ;
            std::cout << "Type : " << elem->getType() ;
            gotoligcol (12+indice+nb, 73) ;
            std::cout << "du sommet " ;
            elem->getSommet2()->afficher_sommet() ;
            nb++;
        }
    }
    carre (10+indice, 2,150, nb+2) ;
    gotoligcol (12+indice, 4) ;
    for (int i=0 ; i<148 ; ++i)
    {
        std::cout << static_cast<char>(196) ;
    }
    gotoligcol (15+indice+nb, 2) ;
}

/*** Méthode d'affichage des motifications du temps ***/
void Graphe::affichage_modification ()
{
    int i=0 ;
    system ("cls") ;
    gotoligcol (0, 57) ;
    std::cout << "M O D I F I C A T I O N   D E S   T R A J E T S" ;
    gotoligcol (1, 55) ;
    for (int i=0 ; i<51 ; ++i)
    {
        std::cout << static_cast<char>(205) ;
    }

    /** Carré de gauche **/
    carre (3, 38, 31, 7) ;
    gotoligcol (4, 40) ;
    std::cout << "V : piste verte" ;
    gotoligcol (5, 40) ;
    std::cout << "B : piste bleue" ;
    gotoligcol (6, 40) ;
    std::cout << "R : piste rouge" ;
    gotoligcol (7, 40) ;
    std::cout << "N : piste noire" ;
    gotoligcol (8, 40) ;
    std::cout << "KL : piste de kilometre lance" ;
    gotoligcol (9, 40) ;
    std::cout << "SURF : snowpark" ;

    /** Carré du droite **/
    carre (3, 90, 28, 7) ;
    gotoligcol (4, 92) ;
    std::cout << "TPH : telepherique" ;
    gotoligcol (5, 92) ;
    std::cout << "TC : telecabine" ;
    gotoligcol (6, 92) ;
    std::cout << "TSD : telesiege debrayable" ;
    gotoligcol (7, 92) ;
    std::cout << "TS : telesiege" ;
    gotoligcol (8, 92) ;
    std::cout << "TK : teleski" ;
    gotoligcol (9, 92) ;
    std::cout << "BUS : bus" ;

    /** Temps des descentes **/
    carre (12, 4, 37, 7) ;
    for (int k=0 ; k<6 ; k++)
    {
        gotoligcol (13+i, 6) ;
        std::cout << m_reference[k]->getType() << " : " ;
        conversion_heure(m_reference[k]->getTemps ()) ;
        std::cout << "pour " << m_reference[k]->getDistance() << "m de denivele" ;
        i++ ;
    }

    /** Temps des remontees **/
    i=0 ;
    carre (12, 58, 42, 6) ;
    for (int k=6 ; k<11 ; k++)
    {
        gotoligcol (13+i, 60) ;
        std::cout << m_reference[k]->getType() << " : " ;
        conversion_heure(m_reference[k]->getMini()) ;
        std::cout << "+ " ;
        conversion_heure(m_reference[k]->getTemps ()) ;
        std::cout << "pour " << m_reference[k]->getDistance() << "m de denivele" << std::endl ;
        i++ ;
    }

    /** Temps trajet de bus **/
    carre(12, 115, 35, 3) ;
    gotoligcol (13, 117) ;
    std::cout << "BUSA : " << m_aretes[57]->getNom () << " " ;
    conversion_heure (m_aretes[57]->getPoids ()) ;
    gotoligcol (14, 117) ;
    std::cout << "BUSB : " << m_aretes[59]->getNom () << " " ;
    conversion_heure (m_aretes[59]->getPoids ()) ;

    gotoligcol (19, 0) ;
}

/*** Méthode d'affichage du résultat de l'algorithme BFS ***/
void Graphe::affichage_bfs (std::vector<int> res, unsigned int somInit)
{
    gotoligcol (5, 0) ;
    for(unsigned int i = 0; i < res.size(); ++i)
    {
        if(i != somInit)
        {
            if(res[i] != -1)
            {
                std::cout << i+1 << " <-- ";
                unsigned int temp = res[i];
                while(temp != somInit)
                {
                    std::cout << temp << " <-- ";
                    temp = res[temp-1];
                }
                std::cout << temp << "          ( poids : ";
                conversion_heure(m_sommets[i]->getPoids()) ;
                std::cout << ")"<< std::endl ;
            }
        }
    }
    for (const auto& elem : m_sommets) // réinitialisation des paramètres pour pouvoir effectuer le bfs plusieurs fois
    {
        elem->setFait (false) ;
        elem->setPoids (9999) ;
    }
    std::cout << std::endl ;
}

/*** Méthode d'affichage du résultat de l'algorithme de Dijkstra ***/
void Graphe::affichage_dijkstra(std::vector<int> res, int a, int b)
{
    gotoligcol (6, 0) ;
    std::cout << "Itineraire le plus rapide entre le sommet " << a << " et " << b << " : " << std::endl ;
    int temp = b;
    do
    {
        std::cout << temp << " <-- ";
        temp = res[temp];
    }
    while(temp != a);
    std::cout << temp <<std::endl;
    std::cout << std::endl << "Temps du parcours : " << std::endl ;
    conversion_heure(m_sommets[b-1]->getPoids()) ;
    std::cout << std::endl << std::endl ;

    for (const auto& elem : m_sommets) // réinitialisation des paramètres pour pouvoir effectuer dijkstra plusieurs fois
    {
        elem->setFait (false) ;
        elem->setPoids (9999) ;
    }
}

/*** Méthode d'affichage du résultat de l'algorithme de Ford-Fulkerson ***/
void Graphe::affichage_fordFulkerson (int flot, int source, int puits)
{
    gotoligcol (6, 0) ;
    std::cout << "Flot maximum :  " << flot << " skieurs/heure" << std::endl ;

    std::cout << std::endl ;
}
