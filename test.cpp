#include <string>
#include <iostream>
#include "Course.cpp"

using namespace std;

int main(){

    Course course1 = Course("Course 1");
    Course course2 = Course("Course 2");
    Course course3 = Course("Course 3");
    Course course4 = Course("Course 4");
    Course course5 = Course("Course 5");

    course1.ajoutScoreDeJoueur(50,"Josette");
    course1.ajoutScoreDeJoueur(20,"Bébère");
    course1.ajoutScoreDeJoueur(500,"Roseline");
    course1.ajoutScoreDeJoueur(10,"Germain");
    course1.ajoutScoreDeJoueur(2,"Auguste");

    course1.afficherScores();
    course1.afficherMeilleurJoueur();
    cout << "La moyenne des scores est de " << course1.moyenne() << endl;

    return 0;
}