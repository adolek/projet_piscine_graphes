#include "Header.h"

/*** Manipulation curseur ***/
void gotoligcol (int lig, int col)
{
    COORD mycoord ;

    mycoord.X = col ;
    mycoord.Y = lig ;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

/*** Fonction d'affichage de couleurs ***/
void Color (int couleurDuTexte, int couleurDeFond)
{
    HANDLE H=GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (H, couleurDeFond*16+couleurDuTexte);
}

/*** Affichage d'un carré de fonction de l'origine et des dimensions ***/
void carre (int x, int y, int longueur, int hauteur)
{
    gotoligcol (x, y) ;
    std::cout << static_cast<char>(218) ;
    for (int i=0 ; i<longueur ; ++i)
    {
        std::cout << static_cast<char>(196) ;
    }
    std::cout << static_cast<char>(191) ;
    for (int i=x ; i<x+hauteur ; ++i)
    {
        gotoligcol (i+1, y) ;
        std::cout << static_cast<char>(179) ;
        gotoligcol (i+1, y+longueur+1) ;
        std::cout << static_cast<char>(179) ;
    }
    gotoligcol (x+hauteur, y) ;
    std::cout << static_cast<char>(192) ;
    for (int i=0 ; i<longueur ; ++i)
    {
        std::cout << static_cast<char>(196) ;
    }
    std::cout << static_cast<char>(217) ;
}

/*** Conversion du temps en secondes en heure/minute/seconde ***/
void conversion_heure (int temps)
{
    int reste, duree ;
    reste = temps%3600 ;
    duree = (temps-reste)/3600 ;
    if (duree != 0)
    {
        std::cout << duree << "h " ; // afficher le nombre d'heures
    }
    temps = reste ;
    reste = temps%60 ;
    duree = (temps-reste)/60 ;
    if (duree != 0)
    {
        std::cout << duree << "min " ; // afficher le nombre de minutes
    }
    duree = reste ;
    if (duree != 0)
    {
        std::cout << duree << "s " ; // afficher le nombre de secondes
    }
}
