#include "Jeu.hpp"

//950
Attaques::Attaques() :
    A(-150, 0, "sprites/attaqueA1_A.png", "sprites/attaqueA1_B.png", strike_1),
    B(1750, 0, "sprites/attaqueA1_A.png", "sprites/attaqueA1_B.png", strike_2),
    C(325, -500, "sprites/attaqueA1_A.png", "sprites/attaqueA1_B.png", strike_3),
    D(325, 1400, "sprites/attaqueA1_A.png", "sprites/attaqueA1_B.png", strike_4)
{}

Paterne::Paterne(int X, int Y, std::string TA, std::string TB, FonctionPtr ptr) : degatZone(ptr)
{
    if (texture_A.loadFromFile(TA))
    {
        sprite_A.setTexture(texture_A); 
        sprite_A.setPosition(X, Y);
    }
    if (texture_B.loadFromFile(TB))
    {
        sprite_B.setTexture(texture_B); 
        sprite_B.setPosition(X, Y);
    }
}

void Attaques::attaques_rng(Jeu *jeu)
{
    srand(time(0));
            int rng = rand() % 4;
    void (*tableauDeFonctions[])(Jeu *jeu) =
                {A.degatZone, A.degatZone, A.degatZone, A.degatZone};
    (*tableauDeFonctions[rng])(jeu);
}

void strike_1(Jeu *jeu)
{
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 3)
    {
        jeu->attaques.A.status = Charge;
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 5)
    {
        jeu->attaques.A.status = Actif;
        if (jeu->joueur.position.x < jeu->F_Largeur / 2)
            jeu->killedStatus = true;   
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 6)
    {
        jeu->attaques.A.status = Inactif;
        jeu->attaques.attaqueTimer.restart();
    }
}

void strike_2(Jeu *jeu)
{
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 3)
    {
        jeu->attaques.B.status = Charge;
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 5)
    {
        jeu->attaques.B.status = Actif;
        if (jeu->joueur.position.x > jeu->F_Largeur / 2)
            jeu->killedStatus = true;   
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 6)
    {
        jeu->attaques.B.status = Inactif;
        jeu->attaques.attaqueTimer.restart();
    }
}

void strike_3(Jeu *jeu)
{
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 3)
    {
        jeu->attaques.C.status = Charge;
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 5)
    {
        jeu->attaques.C.status = Actif;
        if (jeu->joueur.position.y < jeu->F_Hauteur / 2)
            jeu->killedStatus = true;   
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 6)
    {
        jeu->attaques.C.status = Inactif;
        jeu->attaques.attaqueTimer.restart();
    }
}

void strike_4(Jeu *jeu)
{
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 3)
    {
        jeu->attaques.D.status = Charge;
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 5)
    {
        jeu->attaques.D.status = Actif;
        if (jeu->joueur.position.y > jeu->F_Hauteur / 2)
            jeu->killedStatus = true;   
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 6)
    {
        jeu->attaques.D.status = Inactif;
        jeu->attaques.attaqueTimer.restart();
    }
}