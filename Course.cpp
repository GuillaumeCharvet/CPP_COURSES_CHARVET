#include "Course.h"
#include <string>
#include <iostream>

std::string Course::getNomCourse(){
    return _nomCourse;
}

void Course::ajoutScoreDeJoueur(int score, std::string joueur){
    // Contient l'indice auquel doit se placer le score si le joueur n'a pas de score
    // ou -1 si il ne doit pas être placé
    int ind_lowscore = 0;
    // Contient l'indice du joueur dans la course si il est
    // présent dans les 3 meilleurs scores ou -1 si il est absent
    int ind_joueur = -1;
    bool joueur_present = false;
    for (int i = 0; i < 3; i++)
    {
        if (joueur == *_nomsJoueurs[i])
        {
            joueur_present = true;
            ind_joueur = i;
        }
        if (*_scoresJoueurs[i] < *_scoresJoueurs[ind_lowscore])
        {
            ind_lowscore = i;
        }
    }
    if (joueur_present)
    {
        if (*_scoresJoueurs[ind_joueur] < score)
        {
            *_scoresJoueurs[ind_joueur] = score;
        }        
    }
    else if (*_scoresJoueurs[ind_lowscore] < score)
    {
        *_scoresJoueurs[ind_lowscore] = score;
        *_nomsJoueurs[ind_lowscore] = joueur;
    }
}

void Course::afficherScores(){
    for (int i = 0; i < 3; i++)
    {
        if (*_nomsJoueurs[i] != "")
        {
            std::cout << "Score du joueur " << *_nomsJoueurs[i] << " : " << *_scoresJoueurs[i] << std::endl;
        }        
    }
}

void Course::afficherMeilleurJoueur(){
    int ind_meilleur = -1;
    if (*_scoresJoueurs[0] == -1)
    {
        std::cout << "Aucun joueur n'a encore joué à cette course." << std::endl;
    }
    else
    {
        ind_meilleur = 0;
        for (int i = 1; i < 3; i++)
        {
            if (*_scoresJoueurs[i] > *_scoresJoueurs[ind_meilleur])
            {
                ind_meilleur = i;
            }        
        }
        std::cout << "Le meilleur joueur est " << *_nomsJoueurs[ind_meilleur] << std::endl;
    }
}

float Course::moyenne(){
    float sum;
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        if (*_scoresJoueurs[i] != -1)
        {
            sum += *_scoresJoueurs[i];
            num += 1;
        }
    }
    if (num != 0)
    {
        return (sum/num);
    }
    else
    {
        std::cout << "Aucun score, impossibilité de faire une moyenne !" << std::endl;
        return -1;
    }
}

Course::Course(std::string nomCourse){
    _nomCourse = nomCourse;
    *(_scoresJoueurs[0]) = -1;
    *(_scoresJoueurs[1]) = -1;
    *(_scoresJoueurs[2]) = -1;
    *(_nomsJoueurs[0]) = "no";
    *(_nomsJoueurs[1]) = "no";
    *(_nomsJoueurs[2]) = "no";
}