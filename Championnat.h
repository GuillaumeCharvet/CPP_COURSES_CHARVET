#include <string>
#include <iostream>
#include "Course.h"

class Championnat{

    private:
        std::string _nomChampionnat;
        Course * _courses[4];

    public:
        std::string getNomChampionnat();
        void afficherMeilleursTemps(Course course);
        void afficherTempsMoyens();
        void afficherMeilleurTemps();
        void afficherMeilleurJoueur(Course course);
        void afficherMeilleurJoueurTotal();
        Championnat(std::string nomChampionnat);
};