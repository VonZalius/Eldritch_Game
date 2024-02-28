#include "Jeu.hpp"

void EcranTitre::afficherEcranTitre(sf::RenderWindow& fenetre)
{
    sf::Event evenement;
    while (fenetre.isOpen())
    {
        while (fenetre.pollEvent(evenement))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
            {
                fenetre.close();
            }
            if (evenement.type == sf::Event::KeyPressed)
            {
                return; // Quitte l'écran titre lorsque n'importe quelle touche est pressée
            }
            else if (evenement.type == sf::Event::Closed)
            {
                fenetre.close();
            }
        }

        fenetre.clear();
        fenetre.draw(spriteEcranTitre);
        fenetre.draw(spriteEldritch);
        fenetre.draw(texteTitre);
        fenetre.display();
    }
}

void EcranTitre::demarrage(sf::RenderWindow& fenetre)
{
    sf::Event evenement;
    sf::Clock timer;
    timer.restart();
    while (fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 1)
    {
        while (fenetre.pollEvent(evenement))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                fenetre.close();
        fenetre.clear();
        fenetre.draw(spriteEcranTitre);
        fenetre.draw(texteDemarrage3);
        fenetre.display();
    }
    timer.restart();
    while (fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 1)
    {
        while (fenetre.pollEvent(evenement))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                fenetre.close();
        fenetre.clear();
        fenetre.draw(spriteEcranTitre);
        fenetre.draw(texteDemarrage2);
        fenetre.display();
    }
    timer.restart();
    while (fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 1)
    {
        while (fenetre.pollEvent(evenement))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                fenetre.close();
        fenetre.clear();
        fenetre.draw(spriteEcranTitre);
        fenetre.draw(texteDemarrage1);
        fenetre.display();
    }
}

void EcranTitre::killed(sf::RenderWindow& fenetre)
{
    sf::Event evenement;
    sf::Clock timer;
    timer.restart();
    while (fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 1)
    {
        while (fenetre.pollEvent(evenement))
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
                fenetre.close();
        fenetre.clear();
        fenetre.draw(spriteEcranTitre);
        fenetre.draw(texteKilled);
        fenetre.display();
    }
}