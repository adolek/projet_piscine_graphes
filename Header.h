#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/*** Includes ***/
#include "Sommet.h"
#include "Arete.h"
#include "Graphe.h"
#include <iostream>
#include <windows.h>
#include <time.h>

/*** Fonctions & Sous-programmes ***/
void gotoligcol (int lig, int col) ; // acceder aux coordonnées de la console
void Color (int couleurDuTexte, int couleurDeFond) ; // modifier la couleur du texte
void menu () ; // menu et appel des methodes
void menu2 () ; // menu secondaire
void accueil () ; // page d'accueil
void affichage () ; // affichage de tous les composants du menu
void carre (int x, int y, int longueur, int hauteur) ; // affichage d'un carré  dans la console
void conversion_heure (int temps) ; // conversion temps en minutes et secondes

#endif // HEADER_H_INCLUDED
