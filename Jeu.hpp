#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "Map.hpp"
#include "Attaques.hpp"

struct Joueur
{
    sf::Vector2f position;
    float vitesse = 200.0f; // pixels par seconde
    float vitesseAugmentee = 400.0f;
    static const int TailleSprite = 64;
    static const int collision_div = 10;
    sf::Sprite sprite;


    // Taille originelle du Sprite
    static const int frameWidth = 32;
    static const int frameHeight = 32;

    // Texture principale
    std::string joueurSprite = "sprites/camelot_/percival_.png";
    sf::Texture textureJoueur; // Ajout pour gérer la texture du sprite du joueur
    std::vector<sf::IntRect> framesJoueur;
    // Position des différent sprite pour l'animation, compter a partir de 0 !!
    static const int frameStartX = 0;
    static const int frameStartY = 0;
    static const int frameEndX = 3;
    static const int frameEndY = 0;

    // Texture secondaire
    std::string joueurSprite_2 = "sprites/camelot_/percival_.png";
    sf::Texture textureJoueur_2; // Ajout pour gérer la texture du sprite du joueur
    std::vector<sf::IntRect> framesJoueur_2;
    // Position des différent sprite pour l'animation, compter a partir de 0 !!
    static const int frameStartX_2 = 0;
    static const int frameStartY_2 = 1;
    static const int frameEndX_2 = 3;
    static const int frameEndY_2 = 2;

    sf::Clock animationClock;
    int currentFrame = 0;
};

struct EcranTitre
{
    void afficherEcranTitre(sf::RenderWindow& fenetre);
    void demarrage(sf::RenderWindow& fenetre);
    void killed(sf::RenderWindow& fenetre);

    sf::Texture textureEcranTitre;
    sf::Sprite spriteEcranTitre;

    sf::Texture textureEldritch;
    sf::Sprite spriteEldritch;

    sf::Font font;
    sf::Text texteTitre;

    sf::Font fontDemarrage;
    sf::Text texteDemarrage3;
    sf::Text texteDemarrage2;
    sf::Text texteDemarrage1;

    sf::Font fontKilled;
    sf::Text texteKilled;
};

struct Sound
{
    std::string musiqueFile1 = "music/Pixel Music Pack/Ogg/Pixel 3.ogg";
    sf::Music musique1;
    static const int volume1 = 10;

    std::string musiqueFile2 = "music/Pixel Music Pack/Ogg/Pixel 1.ogg";
    sf::Music musique2;
    static const int volume2 = 10;

    std::string SoundFile1 = "music/FreeSFX/GameSFX/Magic/Retro Magic 11.wav";
    sf::SoundBuffer buffer1;
    sf::Sound sound1;
    static const int soundVolume1 = 10;

    std::string SoundFile2 = "music/FreeSFX/GameSFX/Explosion/Retro Explosion Swoshes 04.wav";
    sf::SoundBuffer buffer2;
    sf::Sound sound2;
    static const int soundVolume2 = 10;

    std::string SoundFile3 = "music/FreeSFX/GameSFX/Impact/Retro Impact 20.wav";
    sf::SoundBuffer buffer3;
    sf::Sound sound3;
    static const int soundVolume3 = 10;
};

class Jeu
{
public:
    Jeu();
    void executer();

    sf::RenderWindow fenetre;
    static const int F_Hauteur = 1080;
    static const int F_Largeur = 1920;
    bool killedStatus = false;

    Joueur joueur;

    EcranTitre ecranTitre;

    Attaques attaques;

    Map map;

    Sound sound;

    void initialiserJeu();
    void traiterEvenements();
    void mettreAJour(sf::Time deltaTime);
    bool collision(int p, sf::Time deltaTime, float vitesseActuelle);
    void dessiner();
    void reinitialiser();
};

#endif
