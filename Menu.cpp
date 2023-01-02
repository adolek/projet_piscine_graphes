#include "Header.h"

/*** MENU de choix des différentes fonctionnalités disponibles ***/
void menu ()
{
    /** Déclaration et initialisation des variables **/
    int choix = 0 ;
    int initial ;
    int num1, num2 ;
    int flot ;
    std::vector <int> liste_bfs ; // liste qui récupère le parcours du bfs
    std::vector <int> liste_dijkstra ; // liste qui récupère le parcours de dijkstra
    std::string nomFichier ("data_arcs.txt") ; // nom du fichier
    std::string nomFichier2 ("parametres.txt") ; // nom du fichier supplementaire

    Graphe g{nomFichier} ; // creation du graphe
    Graphe g2 ;

    accueil () ; // page d'accueil

    do
    {
        /** Choix du choix **/
        do
        {
            system ("cls") ; // efface la console
            affichage () ; // affichage du menu
            std::cin >> choix ;
        }
        while ((choix < 0) || (choix > 7)) ;

        /** Switch permettant le choix **/
        switch (choix)
        {
        case 1 : /** Afficher toutes les aretes du graphes **/
            system ("cls") ;
            g.afficher() ; //appel de la méthode pour afficher le graphe
            system ("pause") ;
            break ;

        case 2 : /** Modifier le temps de chaque type de trajet **/
            system ("cls") ;
            g.modification_temps () ; // appel de la méthode pour la modification des temps de trajets
            system ("pause") ;
            break ;

        case 3 : /** Afficher tous les trajets a partir d'un sommet choisi **/
            system ("cls") ;
            g.afficherTrajets () ; // appel de la méthode pour afficher les trajets issus de chaque sommet
            system ("pause") ;
            break ;

        case 4 : /** Parcours BFS avec gestion du poids **/
            system ("cls") ;
            /** Affichage du titre **/
            gotoligcol (0, 68) ;
            std::cout << "P A R C O U R S   B F S" ;
            gotoligcol (1, 66) ;
            for (int i=0 ; i<27 ; ++i)
            {
                std::cout << static_cast<char>(205) ;
            }
            /** Choix du sommet **/
            gotoligcol (3, 2) ;
            std::cout << "Choix du sommet :  " ;
            std::cin >> initial ; // choix du sommet initial
            /** Realisation de l'algorithme BFS avec traitement du poids puis affichage **/
            liste_bfs = g.parcours_bfs (initial) ; // appel de la méthode pour le parcours du bfs
            g.affichage_bfs (liste_bfs, initial) ; // appel de la méthode pour l'affichage des résultats du bfs
            system ("pause") ;
            break ;

        case 5 : /** Algorithme de Dijkstra **/
            system ("cls") ;
            /** Affichage du titre **/
            gotoligcol (0, 58) ;
            std::cout << "A L G O R I T H M E   D E   D I J K S T R A" ;
            gotoligcol (1, 56) ;
            for (int i=0 ; i<47 ; ++i)
            {
                std::cout << static_cast<char>(205) ;
            }
            /** Choix des sommets **/
            gotoligcol (3, 2) ;
            std::cout << "Sommet 1 :  " ;
            std::cin >> num1 ; // choix du sommet de départ
            gotoligcol (4, 2) ;
            std::cout << "Sommet 2 :  " ;
            std::cin >> num2 ; // choix du sommet d'arrivé
            /** Realisation de l'algorithme de Dijkstra puis affichage **/
            liste_dijkstra = g.algorithme_dijkstra (num1,num2) ; // appel de la méthode pour l'algorithme de dijkstra
            g.affichage_dijkstra (liste_dijkstra, num1, num2) ; // appel de la méthode pour l'affichage des résultats de dijkstra
            system ("pause") ;
            break ;

        case 6:
            system ("cls") ;
            menu2 () ; // passage sur le second menu avec modification des paramètres
            system ("cls") ;
            std::cout << "Tous les parametres supprimes ont ete restaures..." << std::endl << std::endl ;
            system ("pause") ;
            break ;

        case 7: /** Algorithme de Ford-Fulkerson **/
            system ("cls") ;
            /** Affichage du titre **/
            gotoligcol (0, 52) ;
            std::cout << "A L G O R I T H M E   D E   F O R D - F U L K E R S O N" ;
            gotoligcol (1, 50) ;
            for (int i=0 ; i<59 ; ++i)
            {
                std::cout << static_cast<char>(205) ;
            }
            /** Choix des sommets **/
            gotoligcol (3, 2) ;
            std::cout << "Sommet 1 :  " ;
            std::cin >> num1 ; // choix du sommet source
            gotoligcol (4, 2) ;
            std::cout << "Sommet 2 :  " ;
            std::cin >> num2 ; // choix du sommet puits
            /** Realisation de l'algorithme de Ford-Fulkerson puis affichage **/
            flot = g.algorithme_fordFulkerson(num1,num2); // appel de la méthode pour l'algorithme de ford-fulkerson
            g.affichage_fordFulkerson (flot, num1, num2) ; // appel de la méthode pour l'affichage des résultats de ford-fulkerson
            system ("pause") ;
            break ;

        case 0 : /** Quitter **/
            system ("cls") ;
            std::cout << "Quitter... Bye bye..." << std::endl ;
            system ("pause") ;
            break ;
        }
    }
    while (choix != 0) ;
}

void menu2 ()
{
    /** Déclaration et initialisation des variables **/
    int choix = 0 ;
    std::string choix2 ;
    std::string param ;
    int initial, flot ;
    int num1, num2 ;
    std::vector <int> liste_bfs ; // liste qui récupère le parcours du bfs
    std::vector <int> liste_dijkstra ; // liste qui récupère le parcours de dijkstra
    std::string nomFichier ("data_arcs.txt") ; // nom du fichier
    std::string nomFichier2 ("parametres.txt") ; // nom du fichier supplementaire
    Graphe g2;

    do
    {
        system ("cls") ;
        gotoligcol (0, 57) ;
        std::cout << "S U P P R E S S I O N   D E S   T R A J E T S" ;
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

        gotoligcol (14, 0) ;
        std::cout << "Quel type de trajet voulez-vous supprimer :  " ;
        std::cin >> param;
        g2.ajouterParam (param) ; // modification des paramètres initiaux

        std::cout << "Voulez vous choisir un autre parametre ? 'oui' ou 'non'"  << std::endl ;
        std::cin >> choix2;
    }
    while(choix2 != "non");


    g2.remplirGraphe(nomFichier, nomFichier2); // remplir le graphe avec les nouveaux paramètres

    do
    {
        /** Choix du choix **/
        do
        {
            system ("cls") ; // efface la console
            affichage () ; // affichage du menu
            gotoligcol (20, 49) ;
            std::cout << "                                                " ;
            gotoligcol (20, 49) ;
            std::cout << "Restaurer les parametres initiaux" ;
            gotoligcol (31, 59) ;
            std::cin >> choix ;
        }
        while ((choix < 0) || (choix > 7)) ;

        /** Switch permettant le choix **/
        switch (choix)
        {
        case 1 : /** Afficher toutes les aretes du graphes **/
            system ("cls") ;
            g2.afficher() ; //appel de la méthode pour afficher le graphe
            system ("pause") ;
            break ;

        case 2 : /** Modifier le temps de chaque type de trajet **/
            system ("cls") ;
            g2.modification_temps () ; // appel de la méthode pour la modification des temps de trajets
            system ("pause") ;
            break ;

        case 3 : /** Afficher tous les trajets a partir d'un sommet choisi **/
            system ("cls") ;
            g2.afficherTrajets () ; // appel de la méthode pour afficher les trajets issus de chaque sommet
            system ("pause") ;
            break ;

        case 4 : /** Parcours BFS avec gestion du poids **/
            system ("cls") ;
            /** Affichage du titre **/
            gotoligcol (0, 68) ;
            std::cout << "P A R C O U R S   B F S" ;
            gotoligcol (1, 66) ;
            for (int i=0 ; i<27 ; ++i)
            {
                std::cout << static_cast<char>(205) ;
            }
            /** Choix du sommet **/
            gotoligcol (3, 2) ;
            std::cout << "Choix du sommet :  " ;
            std::cin >> initial ; // choix du sommet initial
            /** Realisation de l'algorithme BFS avec traitement du poids puis affichage **/
            liste_bfs = g2.parcours_bfs (initial) ; // appel de la méthode pour le parcours du bfs
            g2.affichage_bfs (liste_bfs, initial) ; // appel de la méthode pour l'affichage des résultats du bfs
            system ("pause") ;
            break ;

        case 5 : /** Algorithme de Dijkstra **/
            system ("cls") ;
            /** Affichage du titre **/
            gotoligcol (0, 58) ;
            std::cout << "A L G O R I T H M E   D E   D I J K S T R A" ;
            gotoligcol (1, 56) ;
            for (int i=0 ; i<47 ; ++i)
            {
                std::cout << static_cast<char>(205) ;
            }
            /** Choix des sommets **/
            gotoligcol (3, 2) ;
            std::cout << "Sommet 1 :  " ;
            std::cin >> num1 ;
            gotoligcol (4, 2) ;
            std::cout << "Sommet 2 :  " ;
            std::cin >> num2 ;
            /** Realisation de l'algorithme de Dijkstra puis affichage **/
            liste_dijkstra = g2.algorithme_dijkstra (num1,num2) ; // appel de la méthode pour l'algorithme de dijkstra
            g2.affichage_dijkstra (liste_dijkstra, num1, num2) ; // appel de la méthode pour l'affichage des résultats de dijkstra
            system ("pause") ;
            break ;

        case 6:
            //system ("cls") ;
            //system ("pause") ;
            break ;

        case 7: /** Algorithme de Ford-Fulkerson **/
            system ("cls") ;
            /** Affichage du titre **/
            gotoligcol (0, 52) ;
            std::cout << "A L G O R I T H M E   D E   F O R D - F U L K E R S O N" ;
            gotoligcol (1, 50) ;
            for (int i=0 ; i<59 ; ++i)
            {
                std::cout << static_cast<char>(205) ;
            }
            /** Choix des sommets **/
            gotoligcol (3, 2) ;
            std::cout << "Sommet 1 :  " ;
            std::cin >> num1 ; // choix du sommet source
            gotoligcol (4, 2) ;
            std::cout << "Sommet 2 :  " ;
            std::cin >> num2 ; // choix du sommet puits
            /** Realisation de l'algorithme de Ford-Fulkerson puis affichage **/
            flot = g2.algorithme_fordFulkerson(num1,num2); // appel de la méthode pour l'algorithme de ford-fulkerson
            g2.affichage_fordFulkerson (flot, num1, num2) ; // appel de la méthode pour l'affichage des résultats de ford-fulkerson
            system ("pause") ;
            break ;

        case 0 : /** Quitter **/
            system ("cls") ;
            std::cout << "Quitter... Bye bye..." << std::endl ;
            system ("pause") ;
            exit(0);
            break ;
        }
    }
    while(choix!=6);
}

/*** Affichage accueil ***/
void accueil ()
{
    system ("cls") ;
    /** Carré top **/
    carre (4, 29, 99, 4) ;
    gotoligcol (6, 67) ;
    std::cout << "S T A T I O N   D E   S K I" ;
    /** Carré nom **/
    carre (20, 61, 39, 8) ;
    gotoligcol (22, 66) ;
    std::cout << "Nathan CHALDEBAS" ;
    gotoligcol (22, 86) ;
    std::cout << "TD 11" ;
    gotoligcol (24, 66) ;
    std::cout << " Adrien OLEKSIAK" ;
    gotoligcol (24, 86) ;
    std::cout << "Equipe 1106" ;
    gotoligcol (26, 66) ;
    std::cout << "Esteban SABATIER" ;
    gotoligcol (26, 86) ;
    std::cout << "ING 2" ;

    gotoligcol (32, 0) ;
    std::cout << "Nous recommandons d'utiliser la console avec la police Consolas et avec les dimensions 160 en largeur et 40 en hauteur pour une meilleure ergonomie du programme" ;


    gotoligcol (38, 100) ;
    system ("pause") ;
}

/*** Affichage du menu ***/
void affichage ()
{
    /** Carré top **/
    carre (0, 29, 99, 4) ;
    gotoligcol (2, 67) ;
    std::cout << "S T A T I O N   D E   S K I" ;

    /** Menu souligné **/
    gotoligcol (7, 76) ;
    std::cout << "M E N U" << std::endl ;
    gotoligcol (8, 74) ;
    for (int i=0 ; i<11 ; ++i)
    {
        std::cout << static_cast<char>(205) ;
    }

    /** Carré menu **/
    carre (6, 39, 79, 27) ;
    int k = 0 ;
    while (k < 21)
    {
        gotoligcol (9+k, 41) ;
        for (int i=0 ; i<77 ; ++i)
        {
            std::cout << static_cast<char>(196) ;
        }
        if (k < 20)
        {
            gotoligcol (10+k, 46) ;
            std::cout << static_cast<char>(179) ;
        }
        k += 2 ;
    }

    /** Choix **/
    gotoligcol (10, 43) ;
    std::cout << "1" ;
    gotoligcol (10, 49) ;
    std::cout << "Afficher les plans de la station" ;
    gotoligcol (12, 43) ;
    std::cout << "2" ;
    gotoligcol (12, 49) ;
    std::cout << "Modifier le temps des trajets" ;
    gotoligcol (14, 43) ;
    std::cout << "3" ;
    gotoligcol (14, 49) ;
    std::cout << "Afficher les chemins possibles a partir d'un sommet" ;
    gotoligcol (16, 43) ;
    std::cout << "4" ;
    gotoligcol (16, 49) ;
    std::cout << "Afficher tous les chemins a partir d'un sommet (BFS)" ;
    gotoligcol (18, 43) ;
    std::cout << "5" ;
    gotoligcol (18, 49) ;
    std::cout << "Afficher le chemin le plus court entre deux sommets (Dijkstra)" ;
    gotoligcol (20, 43) ;
    std::cout << "6" ;
    gotoligcol (20, 49) ;
    std::cout << "Optimisation des vacances (choix des parametres)" ;
    gotoligcol (22, 43) ;
    std::cout << "7" ;
    gotoligcol (22, 49) ;
    std::cout << "Flots de skieurs (Ford-Fulkerson)" ;
    gotoligcol (28, 43) ;
    std::cout << "0" ;
    gotoligcol (28, 49) ;
    std::cout << "Quitter" ;
    gotoligcol (31, 49) ;
    std::cout << "Choix :   " ;
}
