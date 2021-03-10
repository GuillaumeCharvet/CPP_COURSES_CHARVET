#include <string>
#include <iostream>

class Course{

    private:
        std::string _nomCourse;
        int * _scoresJoueurs[3];        
        std::string * _nomsJoueurs[3];

    public:
        std::string getNomCourse();
        void ajoutScoreDeJoueur(int score, std::string joueur);
        void afficherScores();
        void afficherMeilleurJoueur();
        float moyenne();
        Course(std::string nomCourse);

};