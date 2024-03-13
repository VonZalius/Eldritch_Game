//#include <SFML/Graphics.hpp>
#include "Jeu.hpp"

int main()
{
    Jeu jeu;
    while (jeu.fenetre.isOpen())
        jeu.executer();
    return 0;
}