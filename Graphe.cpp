#include "Graphe.h"

/*** Constructeur ***/
Graphe::Graphe (std::string nomFichier)
{
    /** D�claration des variables **/
    int num, altitude, temps, distance, capacite, numero, num_depart, num_arrive, temps_remontee, temps_sup ;
    std::string nom_lieu, nom_trajet, type ;

    /** Ouverture du fichier et r�cup�ration de l'ordre, de la taille et des sommets **/
    std::ifstream ifs{nomFichier} ; // ouverture du fichier
    if (!ifs)
    {
        throw std::runtime_error ("Impossible d'ouvrir en lecture " + nomFichier) ;
    }
    ifs >> m_ordre ; // recuperation du nombre total de sommets
    if (ifs.fail())
    {
        throw std::runtime_error("Probleme lecture ordre du graphe") ;
    }
    for (int i=0 ; i<m_ordre ; ++i) // pour chaque sommet
    {
        ifs >> num >> nom_lieu >> altitude ; // recuperation du numero, nom et altitude de chaque sommet
        m_sommets.push_back (new Sommet(num, nom_lieu, altitude)) ; // creation de chaque sommet
    }
    ifs >> m_taille; // recuperation du nombre d'aretes
    if (ifs.fail())
    {
        throw std::runtime_error ("Probleme lecture taille du graphe") ;
    }

    /** R�cup�ration des informations de r�f�rence **/
    for (int i=0 ; i<6 ; ++i) // pour les descentes
    {
        ifs >> type >> temps >> distance >> capacite;
        if (ifs.fail())
        {
            throw std::runtime_error ("Probleme lecture arc") ;
        }
        m_reference.push_back (new Refer(type,temps,distance,0,capacite)) ;
    }
    for (int i=0 ; i<5 ; ++i) // pour les remont�es
    {
        ifs >> type >> temps_sup >> temps_remontee >> distance >> capacite ;
        std::cout << capacite;
        if (ifs.fail())
        {
            throw std::runtime_error("Probleme lecture arc") ;
        }
        m_reference.push_back (new Refer(type,temps_remontee,distance,temps_sup,capacite)) ;
    }

    /** R�cup�ration des informations sur chaque arete **/
    for (int i=0; i<m_taille ; ++i) // pour chaque arete
    {
        ifs >> numero >> nom_trajet >> type >> num_depart >> num_arrive ; // recuperation du numero, nom, type sommet de d�part et d'arriv� pour chaque arete
        if (ifs.fail())
        {
            throw std::runtime_error("Probleme lecture arc") ;
        }
        for (const auto& elem : m_reference)
        {
            if(elem->getType() == type)
            {
                capacite=elem->getCapacite (); // pour chaque type on r�cup�re la capacit� max de la piste
            }
        }
        Arete*nouv = new Arete (numero, nom_trajet, type, m_sommets[num_depart-1], m_sommets[num_arrive-1], capacite) ; // cr�ation de l'arete
        calcul_temps (nouv) ; // calcul du temps de trajet de chaque arete en fonction du type et du d�nivel�
        if((type=="V")||(type=="B")||(type=="R")||(type=="N")||(type=="KL")||(type=="SURF"))
        {
            m_descente.push_back (nouv) ; // ajout dans le vecteur des descents chaque arete de descente
        }
        else if((type=="TPH")||(type=="TC")||(type=="TSD")||(type=="TS")||(type=="TK"))
        {
            m_remontee.push_back (nouv) ; // ajout dans le vecteur des remont�es chaque arete de remont�e
        }
        else
        {
            if((numero==58)||(numero==59))
            {
                nouv->setPoids (1800) ; // initialisation du temps de trajet du bus A
            }
            if((numero==60)||(numero==61))
            {
                nouv->setPoids (2400) ; // initialisation du temps de trajet du bus B
            }
        }
        m_aretes.push_back (nouv) ; // ajout de l'arete dans le vecteur arete
        m_sommets[num_depart-1]->ajouterSuccesseurs (m_sommets[num_arrive-1], nouv->getPoids()) ; // ajout des successeurs � chaque sommet
    }
}
Graphe::Graphe()
{
// constructeur sans parametre
}

/*** Destructeur ***/
Graphe::~Graphe ()
{
    for (auto s : m_sommets)
    {
        delete s;
    }
}

/*** M�thode remplir un graphe ***/
void Graphe::remplirGraphe(std::string nomFichier, std::string nomFichier2)
{
    /** D�claration des variables **/
    int num, altitude, temps, distance, capacite, numero, num_depart, num_arrive, temps_remontee, temps_sup ;
    std::string nom_lieu, nom_trajet, type ;

    std::ofstream ofs(nomFichier2, std::ios::out);
    if (ofs)
    {
        for(auto elem : m_params)
        {
            ofs << elem << std::endl;
        }
        ofs.close(); // fermeture du flux
    }

    /** Ouverture du fichier et r�cup�ration de l'ordre, de la taille et des sommets **/
    std::ifstream ifs{nomFichier} ; // ouverture du fichier
    if (!ifs)
    {
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier ) ;
    }
    ifs >> m_ordre ; // recuperation du nombre total de sommets
    if (ifs.fail())
    {
        throw std::runtime_error("Probleme lecture ordre du graphe") ;
    }

    for (int i=0 ; i<m_ordre ; ++i) // pour chaque sommet
    {
        ifs >> num >> nom_lieu >> altitude ; // recuperation du numero, nom et altitude de chaque sommet
        m_sommets.push_back( new Sommet(num, nom_lieu, altitude) ) ; // creation de chaque sommet
    }
    ifs >> m_taille; // recuperation du nombre d'aretes
    if (ifs.fail())
    {
        throw std::runtime_error("Probleme lecture taille du graphe") ;
    }

    /** R�cup�ration des informations de r�f�rence **/
    for (int i=0 ; i<6 ; ++i) // pour les descentes
    {
        ifs >> type >> temps >> distance >> capacite ;
        if (ifs.fail())
        {
            throw std::runtime_error("Probleme lecture arc") ;
        }
        m_reference.push_back (new Refer(type,temps,distance,0,capacite)) ;
    }
    for (int i=0 ; i<5 ; ++i) // pour les remont�es
    {
        ifs >> type >> temps_sup >> temps_remontee >> distance >> capacite ;
        if (ifs.fail())
        {
            throw std::runtime_error("Probleme lecture arc") ;
        }
        m_reference.push_back (new Refer(type,temps_remontee,distance,temps_sup,capacite)) ;
    }

    /** R�cup�ration des informations sur chaque arete **/
    for (int i=0; i<m_taille ; ++i) // pour chaque arete
    {
        ifs >> numero >> nom_trajet >> type >> num_depart >> num_arrive ; // recuperation du numero, nom, type sommet de d�part et d'arriv� pour chaque arete
        bool check = false;
        for (auto elem : m_params)
        {
            if(elem == type)  // si le type est diff�rent du parametre
            {
                check = true;
            }
        }
        if(check == false)
        {
            if (ifs.fail())
            {
                throw std::runtime_error("Probleme lecture arc") ;
            }
            int capacite;
            for (const auto& elem : m_reference)
            {
                if (elem->getType() == type)
                {
                    capacite=elem->getCapacite () ; // pour chaque type on r�cup�re la capacit� max de la piste
                }
            }
            Arete*nouv = new Arete (numero, nom_trajet, type, m_sommets[num_depart-1], m_sommets[num_arrive-1], capacite) ; // cr�ation de l'arete
            calcul_temps (nouv) ; // calcul du temps de trajet de chaque arete en fonction du type et du d�nivel�
            if((type=="V")||(type=="B")||(type=="R")||(type=="N")||(type=="KL")||(type=="SURF"))
            {
                m_descente.push_back (nouv) ; // ajout dans le vecteur des descents chaque arete de descente
            }
            else if((type=="TPH")||(type=="TC")||(type=="TSD")||(type=="TS")||(type=="TK"))
            {
                m_remontee.push_back (nouv) ; // ajout dans le vecteur des remont�es chaque arete de remont�e
            }
            else
            {
                if((numero==58)||(numero==59))
                {
                    nouv->setPoids (1800) ; // initialisation du temps de trajet du bus A
                }
                if((numero==60)||(numero==61))
                {
                    nouv->setPoids (2400) ; // initialisation du temps de trajet du bus B
                }
            }
            m_aretes.push_back (nouv) ; // ajout de l'arete dans le vecteur arete
            m_sommets[num_depart-1]->ajouterSuccesseurs (m_sommets[num_arrive-1], nouv->getPoids()) ; // ajout des successeurs � chaque sommet
        }
    }
}

/*** M�thode pour modifier les param�tres ***/
void Graphe::ajouterParam(std::string param)
{
    m_params.push_back (param) ; // ajout des parametres a supprimer dans le vecteur
}

/*** Methode modification temps trajet ***/
void Graphe::modification_temps ()
{
    /** D�claration des variables **/
    std::string type ;
    int valeur_min, valeur_sec, valeur_tot ;

    do
    {
        affichage_modification () ; // affichage des informations sur chaque type de trajets
        gotoligcol (22, 0) ;
        std::cout << "Choisir le type de trajet que vous voulez modifier (0 pour quitter) :  " ;
        std::cin >> type ; // choix du type
    }
    while ((type!="V")&&(type!="B")&&(type!="R")&&(type!="N")&&(type!="KL")&&(type!="SURF")&&(type!="TPH")&&(type!="TC")&&(type!="TSD")&&(type!="TS")&&(type!="TK")&&(type!="BUSA")&&(type!="BUSB")&&(type!="0")) ;

    if (type == "V") // pour les pistes verte
    {
        modification_temps_descente (type) ;
    }
    if (type == "B") // pour les pistes bleue
    {
        modification_temps_descente (type) ;
    }
    if (type == "R") // pour les pistes rouges
    {
        modification_temps_descente (type) ;
    }
    if (type == "N") // pour les pistes noires
    {
        modification_temps_descente (type) ;
    }
    if (type == "KL") // pour les pistes de kilom�tre lanc�
    {
        modification_temps_descente (type) ;
    }
    if (type == "SURF") // pour le snowpark
    {
        modification_temps_descente (type) ;
    }
    if (type == "TPH") // pour les t�l�ph�riques
    {
        modification_temps_remontee (type) ;
    }
    if (type == "TC") // pour les t�l�cabines
    {
        modification_temps_remontee (type) ;
    }
    if (type == "TSD") // pour les t�l�si�ges d�brayables
    {
        modification_temps_remontee (type) ;
    }
    if (type == "TS") // pour les t�l�si�ges
    {
        modification_temps_remontee (type) ;
    }
    if (type == "TK") // pour les t�l�skis
    {
        modification_temps_remontee (type) ;
    }
    if (type == "BUSA") // pour le bus A qui va du sommet 1600 au sommet 1800
    {
        std::cout << std::endl << "Nouvelle valeur du temps :     min    s          (Modifier les minutes puis appuyer sur ENTRER pour modifier les secondes)" ;
        gotoligcol (24, 28) ;
        std::cin >> valeur_min ; // selection de la valeur en minutes
        gotoligcol (24, 35) ;
        std::cin >> valeur_sec ; // selection de la valeur en secondes
        valeur_tot = valeur_min*60+valeur_sec ; // calcul du temps total en secondes
        m_aretes[57]->setPoids (valeur_tot) ; // modification pour l'aller et le retour de chaque arete
        m_aretes[58]->setPoids (valeur_tot) ;
        affichage_modification () ; // afficher les modifications
        std::cout << std::endl << std::endl << std::endl << "Modification enregistree" << std::endl << std::endl ;
    }
    if (type == "BUSB") // pour le bus A qui va du sommet 1600 au sommet 2000
    {
        std::cout << std::endl << "Nouvelle valeur du temps :     min    s          (Modifier les minutes puis appuyer sur ENTRER pour modifier les secondes)" ;
        gotoligcol (24, 28) ;
        std::cin >> valeur_min ; // selection de la valeur en minutes
        gotoligcol (24, 35) ;
        std::cin >> valeur_sec ; // selection de la valeur en secondes
        valeur_tot = valeur_min*60+valeur_sec ; // calcul du temps total en secondes
        m_aretes[59]->setPoids (valeur_tot) ; // modification pour l'aller et le retour de chaque arete
        m_aretes[60]->setPoids (valeur_tot) ;
        affichage_modification () ; // afficher les modifications
        std::cout << std::endl << std::endl << std::endl << "Modification enregistree" << std::endl << std::endl ;
    }
    if (type == "0")
    {
        std::cout << std::endl << "Echap... aucune modification" << std::endl << std::endl ;
    }

    for (const auto& elem : m_aretes)
    {
        if (elem->getType() == type) // pour chaque type
        {
            calcul_temps (elem) ; // calcul du nouveau temps de trajet pour chaque arete
        }
    }
}

/*** Methode modification temps trajet descente ***/
void Graphe::modification_temps_descente (std::string type)
{
    int valeur_min, valeur_sec, valeur_tot ;
    std::cout << std::endl << "Nouvelle valeur du temps :     min    s          (Modifier les minutes puis appuyer sur ENTRER pour modifier les secondes)" ;
    gotoligcol (24, 28) ;
    std::cin >> valeur_min ; // selection de la valeur en minutes
    gotoligcol (24, 35) ;
    std::cin >> valeur_sec ; // selection de la valeur en secondes
    valeur_tot = valeur_min*60+valeur_sec ; // calcul du temps total en secondes
    for (int k=0 ; k<6 ; k++)
    {
        if(m_reference[k]->getType() == type) // pour chaque type
        {
            m_reference[k]->setTemps(valeur_tot) ; // modification du temps dans les vecteurs des informations de r�f�rence
        }
    }
    affichage_modification () ; // afficher les modifications
    std::cout << std::endl << std::endl << std::endl << "Modification enregistree" << std::endl << std::endl ;
}

/** Methode modification temps trajet remontee ***/
void Graphe::modification_temps_remontee (std::string type)
{
    int valeur_min, valeur_sec, valeur_tot ;
    int temps ;
    std::cout << std::endl << "Valeur a modifier (1 pour le temps fixe ou 2 pour le temps proportionnnel au denivele) :  " ;
    std::cin >> temps ;

    if(temps == 1)
    {
        for (int k=6 ; k<11 ; k++)
        {
            if(m_reference[k]->getType() == type)
            {
                std::cout << std::endl << "Nouvelle valeur du temps fixe :     min    s          (Modifier les minutes puis appuyer sur ENTRER pour modifier les secondes)" ;
                gotoligcol (26, 33) ;
                std::cin >> valeur_min ;
                gotoligcol (26, 40) ;
                std::cin >> valeur_sec ;
                valeur_tot = valeur_min*60+valeur_sec ;
                m_reference[k]->setMini(valeur_tot) ; // modification du temps suppl�mentaire dans les vecteurs des informations de r�f�rence
            }
        }
    }
    if(temps == 2)
    {
        for (int k=6 ; k<11 ; k++)
        {
            if(m_reference[k]->getType() == type)
            {
                std::cout << std::endl << "Nouvelle valeur du temps proportionnel au denivele :     min    s          (Modifier les minutes puis appuyer sur ENTRER pour modifier les secondes)" ;
                gotoligcol (26, 54) ;
                std::cin >> valeur_min ;
                gotoligcol (26, 61) ;
                std::cin >> valeur_sec ;
                valeur_tot = valeur_min*60+valeur_sec ;
                m_reference[k]->setTemps(valeur_tot) ; // modification du temps dans les vecteurs des informations de r�f�rence
            }
        }
    }
    affichage_modification () ;
    std::cout << std::endl << std::endl << std::endl << "Modification enregistree" << std::endl << std::endl ;
}

/*** M�thode calcul temps ***/
void Graphe::calcul_temps (Arete* a)
{
    for (const auto& elem : m_reference) // pour chaque type
    {
        if (a->getType() == elem->getType())
        {
            a->setTemps (elem->getTemps()) ;
            a->setMini (elem->getMini()) ;
        }
    }
    a->setDenivele (abs(a->getSommet1()->getAltitude() - a->getSommet2()->getAltitude())) ; // calcul de la valeur absolue du d�nivel� entre deux sommets
    a->setPoids (a->getMini() + a->getDenivele() * a->getTemps() / 100) ; // calcul du temps de chaque trajet par rapport � la r�f�rence de chaque type
}

/*** M�thode d'algorithme de BFS ***/
std::vector<int> Graphe::parcours_bfs(int initial)
{
    std::queue<int> file;
    int poids_total = 0 ;
    std::vector<int> liste((int)m_sommets.size(),-1);

    file.push(initial);
    m_sommets[initial-1]->setPoids (0) ; // initialisation du poids � 0
    m_sommets[initial-1]->setFait(true); // initialisation du fait � vrai

    while(!file.empty()) // tant que la file est pleine
    {
        initial = file.front();
        poids_total = m_sommets[initial-1]->getPoids() ; // r�cup�ration du poids
        file.pop();
        std::vector<std::pair <Sommet*, int>> successeurs = m_sommets[initial-1]->getSuccesseurs();
        for(auto top : successeurs) // parcours des successeurs du sommets
        {
            if(top.first->getFait() == false)
            {
                int som = top.first->getNumero () ;
                m_sommets[som-1]->setFait (true) ; // marquage du sommet
                top.first->setPoids (poids_total+top.second) ; // calcul du nouveau temps
                liste[som-1] = initial ;
                file.push (som) ;
            }
        }
    }
    return liste ;
}

/*** M�thode algorithme BFS retour bool pour algo ford-fulkerson ***/
bool Graphe::parcours_bfs_bool(int source, int puits, std::vector<int>& parent)
{
    int num=1;
    std::queue<int> file;
    std::vector<bool>visited;
    for(int i = 0; i<m_taille; i++)
    {
        visited.push_back (0) ; // mettre tous les sommets � non fait
    }

    file.push(source);
    visited[source-1] = true ; // marquer le sommet source comme fait
    parent[source-1] = -1 ;

    while (!file.empty()) // tant que la file est pleine
    {

        int som1 = file.front();
        file.pop();
        for (int som2 = 1; som2 < m_ordre+1 ; som2++) // parcours de tous les sommets
        {
            for(const auto& elem : m_aretes) // pour chaque arete
            {
                if(elem->getSommet1()->getNumero()==som1 && elem->getSommet2()->getNumero()==som2)
                {
                    num = elem->getNumero();
                    if (visited[som2-1] == false && m_aretes[num-1]->getFlot() > 0) // si le sommet pas fait et flot >0
                    {
                        file.push(som2) ;
                        parent[som2-1] = som1 ; // ajout du pr�d�cesseur
                        visited[som2-1] = true ; // marquage du sommet comme fait
                    }
                }
            }
        }
    }
    return (visited[puits-1] == true);
}

/*** M�thode d'algorithme de Dijkstra ***/
std::vector <int> Graphe::algorithme_dijkstra (int debut, int fin)
{
    int poids_total = 0 ;
    std::queue <int> file ;
    std::vector<std::pair<const Sommet*,int>> suite ;
    std::vector<int> liste((int)m_sommets.size(),-1);

    file.push(debut) ;
    m_sommets[debut-1]->setPoids (0) ; // initialisation du poids � 0
    while (file.front () != fin) // tant que la file est pleine
    {
        debut = file.front () ;
        m_sommets[debut-1]->setFait(true) ; // marquage du sommet comme fait
        poids_total = m_sommets[debut-1]->getPoids() ; // r�cup�ration du poids du sommet fait
        file.pop() ;
        for(const auto& elem : m_sommets[debut-1]->getSuccesseurs()) // parcours de tous les successeurs du sommet choisi
        {
            if (elem.first->getFait () == false) // si le sommet n'a pas deja ete fait
            {
                if (poids_total + elem.second < elem.first->getPoids ()) // si le nouveau poids est inf�rieur � l'ancien poids du sommet
                {
                    elem.first->setPoids (poids_total + elem.second) ; // modification du poids du sommet avec le nouveau poids
                    liste[elem.first->getNumero ()] = debut ; // r�cup�ration du numero du sommet
                    file.push (elem.first->getNumero ()) ;
                }
            }
        }
    }
    return liste ;
}


/*** M�thode algorithme Ford-Fulkerson ***/
int Graphe::algorithme_fordFulkerson(int source, int puits)
{
    int som1=0, som2=0, num=0, num2=0;
    int max_flow = 0;
    std::vector<int>parent;
    for(int i = 0; i<m_taille; i++)
    {
        parent.push_back (0) ;
    }
    for (const auto& elem : m_aretes)
    {
        elem->setFlot (elem->getCapacite()) ; // r�cup�ration de la capacit� de chaque arete
    }

    while (parcours_bfs_bool(source, puits, parent)) // tant que le sommet puits n'est pas atteint
    {
        int path_flow = INT_MAX;
        for (som2 = puits; som2 != source; som2 = parent[som2-1]) // parcours de chaque sommet puis de ses pr�d�cesseurs
        {
            som1 = parent[som2-1];
            for(const auto& elem : m_aretes) // pour chaque arete
            {
                if(elem->getSommet1()->getNumero()==som1 && elem->getSommet2()->getNumero()==som2)
                {
                    num = elem->getNumero();
                }
                if(elem->getSommet2()->getNumero()==som1 && elem->getSommet1()->getNumero()==som2)
                {
                    num2=elem->getNumero();
                }
            }
            path_flow = std::min (path_flow, m_aretes[num]->getFlot()) ; // calcul du minimum entre deux valeurs
        }

        for (som2 = puits; som2 != source; som2 = parent[som2-1]) // parcours de chaque sommet puis de ses pr�d�cesseurs
        {
            som1 = parent[som2-1];
            m_aretes[num-1]->setFlot(m_aretes[num-1]->getFlot()-path_flow); // calcul du nouveau flot
            m_aretes[num2-1]->setFlot(m_aretes[num2-1]->getFlot()+path_flow);
        }
        max_flow += path_flow ; // ajout dans le flot maximum du flot de chaque arete faite
    }
    return max_flow;
}
