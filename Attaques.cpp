#include "Jeu.hpp"

//950
Attaques::Attaques() :
    A(-150, 0, "sprites/attaqueA1_A.png", "sprites/attaqueA1_B.png", strike_1),
    B(800, 0, "sprites/attaqueA1_A.png", "sprites/attaqueA1_B.png", strike_2),
    C(325, -500, "sprites/attaqueA1_A.png", "sprites/attaqueA1_B.png", strike_3),
    D(325, 450, "sprites/attaqueA1_A.png", "sprites/attaqueA1_B.png", strike_4)
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
    if (status == true)
    {
        void (*tableauDeFonctions[])(Jeu *jeu) =
            {A.degatZone, B.degatZone, C.degatZone, D.degatZone};
        (*tableauDeFonctions[rng])(jeu);
    }
    else if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        rng = rand() % 4;
        status = true;
    }
}

//Moitiée de map ouest
void strike_1(Jeu *jeu)
{
    if (jeu->attaques.A.status == Inactif)
        jeu->attaques.attaqueTimer.restart();
    jeu->attaques.A.status = Charge;
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        jeu->attaques.A.status = Actif;
        if (jeu->joueur.position.x < jeu->F_Largeur / 2)
            jeu->killedStatus = true;   
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 2)
    {
        jeu->attaques.A.status = Inactif;
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Moitiée de map est
void strike_2(Jeu *jeu)
{
    if (jeu->attaques.B.status == Inactif)
        jeu->attaques.attaqueTimer.restart();
    jeu->attaques.B.status = Charge;
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        jeu->attaques.B.status = Actif;
        if (jeu->joueur.position.x + jeu->joueur.TailleSprite > jeu->F_Largeur / 2)
            jeu->killedStatus = true;   
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 2)
    {
        jeu->attaques.B.status = Inactif;
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Moitiée de map nord
void strike_3(Jeu *jeu)
{
    if (jeu->attaques.C.status == Inactif)
        jeu->attaques.attaqueTimer.restart();
    jeu->attaques.C.status = Charge;
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        jeu->attaques.C.status = Actif;
        if (jeu->joueur.position.y < jeu->F_Hauteur / 2)
            jeu->killedStatus = true;   
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 2)
    {
        jeu->attaques.C.status = Inactif;
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

//Moitiée de map sud
void strike_4(Jeu *jeu)
{
    if (jeu->attaques.D.status == Inactif)
        jeu->attaques.attaqueTimer.restart();
    jeu->attaques.D.status = Charge;
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 1)
    {
        jeu->attaques.D.status = Actif;
        if (jeu->joueur.position.y + jeu->joueur.TailleSprite > jeu->F_Hauteur / 2)
            jeu->killedStatus = true;   
    }
    if (jeu->attaques.attaqueTimer.getElapsedTime().asSeconds() >= 2)
    {
        jeu->attaques.D.status = Inactif;
        jeu->attaques.attaqueTimer.restart();
        jeu->attaques.status = false;
    }
}

// NE PAS OUBLIER D'AJOUTER UN RESET DANS REINITIALISER