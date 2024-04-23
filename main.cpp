//#include <SFML/Graphics.hpp>
#include "Jeu.hpp"

int main()
{
    std::ifstream fichierIn("data/Score.txt"); // Crée un objet ifstream et ouvre le fichier
    std::string ligne;
    int Largeur;
    int Hauteur;

    if (fichierIn.is_open())
    {
        getline(fichierIn, ligne);
        if (sscanf(ligne.c_str(), "%dx%d", &Largeur, &Hauteur) == 2)
        {

        }
        else
        {
        std::cout << "Erreur de conversion." << std::endl;
        return 0;
        }
        fichierIn.close();
    }

    Jeu jeu(Largeur, Hauteur);
    while (jeu.fenetre.isOpen())
        jeu.executer();
    return 0;
}