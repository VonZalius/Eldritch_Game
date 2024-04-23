#ifndef JEU_HPP
#define JEU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <fstream>
#include <iostream>
#include "Map.hpp"
#include "Attaques.hpp"
#include "Titre.hpp"

struct Joueur
{
    sf::Vector2f position;
    float vitesse; // pixels par seconde
    float vitesseAugmentee;
    float vitesse_modifier = 4.2;
    int TailleSprite;
    float Taille_modifier = 2;
    static const int collision_div = 15;
    sf::Sprite sprite;


    // Taille originelle du Sprite
    static const int frameWidth = 32;
    static const int frameHeight = 32;

    // Texture principale
    std::string joueurSprite = "sprites/camelot_/mordred_.png";



    std::string joueurSprite2 = "sprites/camelot_/percival_.png";
    std::string joueurSprite3 = "sprites/camelot_/guinevere_.png";
    std::string joueurSprite4 = "sprites/camelot_/merlin_.png";  // Sanctuaire

    std::string joueurSprite5 = "sprites/camelot_/lancelot_.png";
    std::string joueurSprite6 = "sprites/camelot_/ladyOfTheLake_.png";
    std::string joueurSprite7 = "sprites/camelot_/fisherKing_.png"; //Ruines

    std::string joueurSprite8 = "sprites/camelot_/gawain_.png";
    std::string joueurSprite9 = "sprites/camelot_/morganLeFay_.png";
    std::string joueurSprite0 = "sprites/camelot_/arthurPendragon_.png"; // Canal



    sf::Texture textureJoueur; // Ajout pour gérer la texture du sprite du joueur
    std::vector<sf::IntRect> framesJoueur;
    // Position des différent sprite pour l'animation, compter a partir de 0 !!
    static const int frameStartX = 0;
    static const int frameStartY = 0;
    static const int frameEndX = 3;
    static const int frameEndY = 0;

    // Texture secondaire
    //std::string joueurSprite_2 = "sprites/camelot_/percival_.png";
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

struct Sound
{
    std::string musiqueFile1 = "music/Pixel Music Pack/Ogg/Pixel 3.ogg";
    sf::Music musique1;
    static const int volume1 = 5;

    std::string musiqueFile2 = "music/Pixel Music Pack/Ogg/Pixel 1.ogg";
    sf::Music musique2;
    static const int volume2 = 5;

    std::string SoundFile1 = "music/FreeSFX/GameSFX/Magic/Retro Magic 54.wav";
    sf::SoundBuffer buffer1;
    sf::Sound sound1;
    static const int soundVolume1 = 3;

    std::string SoundFile2 = "music/FreeSFX/GameSFX/Explosion/Retro Explosion Swoshes 04.wav";
    sf::SoundBuffer buffer2;
    sf::Sound sound2;
    static const int soundVolume2 = 5;

    std::string SoundFile3 = "music/FreeSFX/GameSFX/Impact/Retro Impact 20.wav";
    sf::SoundBuffer buffer3;
    sf::Sound sound3;
    static const int soundVolume3 = 5;

    std::string SoundFile4 = "music/FreeSFX/GameSFX/FootStep/Retro FootStep Grass 01.wav";
    sf::SoundBuffer buffer4;
    sf::Sound sound4;
    static const int soundVolume4 = 5;
    sf::Clock soundClock4;

    std::string SoundFile5 = "music/FreeSFX/GameSFX/Blops/Retro Blop 22.wav";
    sf::SoundBuffer buffer5;
    sf::Sound sound5;
    static const int soundVolume5 = 5;
    sf::Clock soundClock5;
};

struct Gold
{
    Gold();
    void generer(int T_LARGEUR, int T_HAUTEUR);
    void gold_rng(Jeu *jeu);
    void afficherGold(Jeu *jeu);
    void getGold(int x, int y);

    std::vector<std::vector<bool>> grille;
    bool status;
    int rngX;
    int rngY;
    int GoldCount;

    sf::Sprite sprite;
    int TailleSprite;
    float Taille_modifier = 1;

    // Taille originelle du Sprite
    static const int Width = 16;
    static const int Height = 16;

    // Texture principale
    std::string goldSprite = "sprites/Coin_Gems/MonedaD.png";
    sf::Texture textureGold; // Ajout pour gérer la texture du sprite du joueur
    std::vector<sf::IntRect> framesGold;
    sf::Clock animationTimer;
    int currentFrame = 0;
    // Position des différent sprite pour l'animation, compter a partir de 0 !!
    static const int TileStartX = 0;
    static const int TileStartY = 0;
    static const int TileEndX = 4;
    static const int TileEndY = 0;

    //Affichage Score
    sf::Font font;
    sf::Text texteCount;

    //Son
    std::string SoundFile1 = "music/FreeSFX/GameSFX/PickUp/Retro PickUp Coin 04.wav";
    sf::SoundBuffer buffer1;
    sf::Sound sound1;
    static const int soundVolume1 = 5;
};

class Jeu
{
public:
    Jeu(int Largeur, int Hauteur);
    void executer();

    sf::RenderWindow fenetre;
    int F_Hauteur = 1440;
    int F_Largeur = 2560;
    bool killedStatus = false;
    bool backStatus = false;
    //int TotalScore;
    int HighScore1;
    int HighScore2;
    int HighScore3;
    int sprite_reminder;
    std::string sprite_reminder_str;

    bool want_to_pause = false;
    sf::Font font_wtp;
    sf::Text texte_wtp;
    
    Button shop;

    Joueur joueur;

    EcranTitre ecranTitre;

    Attaques attaques;

    Map map;

    Sound sound;

    Gold gold;

    void initialiserJeu();
    void traiterEvenements();
    void mettreAJour_hub(sf::Time deltaTime);
    void mettreAJour(sf::Time deltaTime);
    bool collision(int p, sf::Time deltaTime, float vitesseActuelle);
    void dessiner_hub();
    void dessiner();
    void reinitialiser();
};

#endif
