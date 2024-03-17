#ifndef TITRE_HPP
#define TITRE_HPP

#include <SFML/Graphics.hpp>

class Jeu;

class Button
{
public:
    Button();
    void btn_create(float x, float y, float width, float height, float size, sf::Font& font, std::string text);
    void drawTo(sf::RenderWindow &window);
    bool isMouseOver(sf::RenderWindow &window);

private:
    sf::RectangleShape shape;
    sf::Text text;
};

struct EcranTitre
{
    void afficherEcranTitre(Jeu *jeu);
    void demarrage(Jeu *jeu);
    void paused(Jeu *jeu);
    void killed(Jeu *jeu);

    sf::Texture textureEcranTitre;
    sf::Sprite spriteEcranTitre;

    sf::Texture textureEldritch;
    sf::Sprite spriteEldritch;

    sf::Font font;
    sf::Text texteTitre;

    sf::Font fontVersion;
    sf::Text texteVersion;
    std::string Version = "Alpha : 0.2.0";

    sf::Font fontDemarrage;
    sf::Text texteDemarrage3;
    sf::Text texteDemarrage2;
    sf::Text texteDemarrage1;

    sf::Font fontKilled;
    sf::Text texteKilled;
    sf::Text texteKilled2;

    sf::Font fontPaused;
    sf::Text textePaused;

    sf::Font fontScore;
    sf::Text texteScore;

    sf::Font fontMap1;
    sf::Text texteMap1;

    sf::Font fontMap2;
    sf::Text texteMap2;

    sf::Font fontMap3;
    sf::Text texteMap3;

};

#endif