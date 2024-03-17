#include "Titre.hpp"
#include "Jeu.hpp"

Button::Button()
{}

void Button::btn_create(float x, float y, float width, float height, float size, sf::Font& font, std::string text)
{
    // Définit la forme du bouton
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);

    // Définit la couleur de fond à transparent
    shape.setFillColor(sf::Color::Transparent);
        
    // Définit le pourtour en blanc avec une épaisseur de 2 pixels
    shape.setOutlineThickness(4.f);
    shape.setOutlineColor(sf::Color::White);

    // Définit le texte du bouton
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(size); // Taille de la police
    this->text.setFillColor(sf::Color::White); // Couleur du texte
    // Positionne le texte au centre du bouton
    sf::FloatRect textRect = this->text.getLocalBounds();
    this->text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    this->text.setPosition(sf::Vector2f(x+width/2.0f, y+height/2.0f));
}

void Button::drawTo(sf::RenderWindow &window)
{
    window.draw(this->shape);
    window.draw(this->text);
}

    // Vérifie si la souris est sur le bouton
bool Button::isMouseOver(sf::RenderWindow &window)
{
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float btnPosX = shape.getPosition().x;
    float btnPosY = shape.getPosition().y;

    float btnxPosWidth = shape.getPosition().x + shape.getLocalBounds().width;
    float btnyPosHeight = shape.getPosition().y + shape.getLocalBounds().height;

    if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
        return true;
    return false;
}

void EcranTitre::afficherEcranTitre(Jeu *jeu)
{
    sf::Event evenement;
    Button btn;
    Button btn2;

    if (!font.loadFromFile("sprites/police.ttf"))
        return;
    btn.btn_create((jeu->F_Largeur / 2) - 200, 650, 400, 100, 60, font, "Commencer la partie");
    btn2.btn_create((jeu->F_Largeur / 2) - 100, 800, 200, 100, 60, font, "Quitter");

    while (jeu->fenetre.isOpen())
    {
        while (jeu->fenetre.pollEvent(evenement))
        {
            if (evenement.type == sf::Event::MouseButtonPressed)
            {
                if (evenement.mouseButton.button == sf::Mouse::Left)
                {
                    if (btn.isMouseOver(jeu->fenetre))
                        return;
                    if (btn2.isMouseOver(jeu->fenetre))
                    {
                        jeu->sound.sound5.play();
                        jeu->fenetre.close();
                    }
                }
            }
            else if (evenement.type == sf::Event::Closed)
            {
                jeu->fenetre.close();
            }
        }

        jeu->fenetre.clear();
        jeu->fenetre.draw(spriteEcranTitre);
        jeu->fenetre.draw(spriteEldritch);
        jeu->fenetre.draw(texteTitre);
        jeu->fenetre.draw(texteVersion);
        btn.drawTo(jeu->fenetre);
        btn2.drawTo(jeu->fenetre);
        jeu->fenetre.display();
    }
}

void EcranTitre::demarrage(Jeu *jeu)
{
    sf::Clock timer;
    timer.restart();
    while (jeu->fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 0.5)
    {
        jeu->fenetre.clear();
        jeu->fenetre.draw(spriteEcranTitre);
        jeu->fenetre.draw(texteDemarrage3);
        if(jeu->map.map_select == 0)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap1);
        else if(jeu->map.map_select == 1)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap2);
        else if(jeu->map.map_select == 2)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap3);
        jeu->fenetre.display();
    }
    timer.restart();
    while (jeu->fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 1)
    {
        jeu->fenetre.clear();
        jeu->fenetre.draw(spriteEcranTitre);
        jeu->fenetre.draw(texteDemarrage2);
        if(jeu->map.map_select == 0)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap1);
        else if(jeu->map.map_select == 1)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap2);
        else if(jeu->map.map_select == 2)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap3);
        jeu->fenetre.display();
    }
    timer.restart();
    while (jeu->fenetre.isOpen() && timer.getElapsedTime().asSeconds() <= 1.5)
    {
        jeu->fenetre.clear();
        jeu->fenetre.draw(spriteEcranTitre);
        jeu->fenetre.draw(texteDemarrage1);
        if(jeu->map.map_select == 0)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap1);
        else if(jeu->map.map_select == 1)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap2);
        else if(jeu->map.map_select == 2)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap3);
        jeu->fenetre.display();
    }
}

void EcranTitre::shop(Jeu *jeu)
{

    sf::Event evenement;

    Button btn;
    Button btn2;
    Button btn3;
    Button btn4;
    Button btn5;
    Button btn6;
    Button btn7;
    Button btn8;
    Button btn9;
    Button btn10;
    Button btn11;

    int skin = 0;

    if (!font.loadFromFile("sprites/police.ttf"))
        return;
    btn.btn_create(100, 100, 400, 100, 60, font, "L'Inconnu");
    btn2.btn_create(600, 100, 420, 100, 60, font, "Sir Tonivar");
    btn3.btn_create(100, 250, 400, 100, 60, font, "L'Enchanteresse");
    btn4.btn_create(600, 250, 420, 100, 60, font, "Mage Barbe-Tordu");
    btn5.btn_create(100, 400, 400, 100, 60, font, "Sir Valan");
    btn6.btn_create(600, 400, 420, 100, 60, font, "Dame d'Autrefois");
    btn7.btn_create(100, 550, 400, 100, 60, font, "Seigneur dechu");
    btn8.btn_create(600, 550, 420, 100, 60, font, "Sir Kerwin");
    btn9.btn_create(100, 700, 400, 100, 60, font, "Cadet Geufroid");
    btn10.btn_create(600, 700, 420, 100, 60, font, "Balthazar Griffe-de-Lion");
    btn11.btn_create(1100, 100, 400, 100, 60, font, "Reprendre");

    jeu->sound.sound5.play();
    while (jeu->fenetre.isOpen())
    {
        while (jeu->fenetre.pollEvent(evenement))
        {
            if (evenement.type == sf::Event::MouseButtonPressed)
            {
                if (evenement.mouseButton.button == sf::Mouse::Left)
                {
                    if (btn.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite))
                            jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        textePaused.setString("Un aventurier perdu au loin des Vrakens...");
                        skin = 0;
                    }
                    else if (btn2.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite2))
                            jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        textePaused.setString("Trouvez 30 pieces au Sanctuaire");
                        skin = 1;
                    }
                    else if (btn3.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite3))
                            jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        textePaused.setString("Trouvez 60 pieces au Sanctuaire");
                        skin = 2;
                    }
                    else if (btn4.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite4))
                            jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        textePaused.setString("Trouvez 100 pieces au Sanctuaire");
                        skin = 3;
                    }
                    else if (btn5.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite5))
                            jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        textePaused.setString("Trouvez 30 pieces aux Ruines");
                        skin = 4;
                    }
                    else if (btn6.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite6))
                            jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        textePaused.setString("Trouvez 60 pieces aux Ruines");
                        skin = 5;
                    }
                    else if (btn7.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite7))
                            jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        textePaused.setString("Trouvez 100 pieces aux Ruines");
                        skin = 6;
                    }
                    else if (btn8.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite8))
                            jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        textePaused.setString("Trouvez 30 pieces au Canal");
                        skin = 7;
                    }
                    else if (btn9.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite9))
                            jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        textePaused.setString("Trouvez 60 pieces au Canal");
                        skin = 8;
                    }
                    else if (btn10.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite0))
                            jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        textePaused.setString("Trouvez 100 pieces au Canal");
                        skin = 9;
                    }
                    else if (btn11.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        if ((skin == 1 && jeu->HighScore1 < 30) ||
                            (skin == 2 && jeu->HighScore1 < 60) ||
                            (skin == 3 && jeu->HighScore1 < 100) ||
                            (skin == 4 && jeu->HighScore2 < 30) ||
                            (skin == 5 && jeu->HighScore2 < 60) ||
                            (skin == 6 && jeu->HighScore2 < 100) ||
                            (skin == 7 && jeu->HighScore3 < 30) ||
                            (skin == 8 && jeu->HighScore3 < 60) ||
                            (skin == 9 && jeu->HighScore3 < 100) )
                        {
                            if (jeu->joueur.textureJoueur.loadFromFile(jeu->joueur.joueurSprite))
                                jeu->joueur.sprite.setTexture(jeu->joueur.textureJoueur);
                        }

                        float goodsize = static_cast<float>(jeu->joueur.TailleSprite) / static_cast<float>(jeu->joueur.frameWidth);
                        jeu->joueur.sprite.setScale(goodsize, goodsize);
                        jeu->joueur.sprite.setOrigin(jeu->joueur.frameWidth / 2, (jeu->joueur.frameHeight / 2) + 6);
                        return;
                    }
                }
            }
        }
        float goodsize = static_cast<float>(jeu->joueur.TailleSprite) / static_cast<float>(jeu->joueur.frameWidth);
        jeu->joueur.sprite.setScale(goodsize * -10, goodsize * 10);
        jeu->joueur.sprite.setPosition(1400, 630);
        jeu->joueur.sprite.setTextureRect(jeu->joueur.framesJoueur[0]);

        float largeurTexte = textePaused.getLocalBounds().width;
        textePaused.setPosition((jeu->F_Largeur / 2) - (largeurTexte / 2), 850);
        jeu->fenetre.clear();
        jeu->fenetre.draw(spriteEcranTitre);
        jeu->fenetre.draw(textePaused);
        btn.drawTo(jeu->fenetre);
        btn2.drawTo(jeu->fenetre);
        btn3.drawTo(jeu->fenetre);
        btn4.drawTo(jeu->fenetre);
        btn5.drawTo(jeu->fenetre);
        btn6.drawTo(jeu->fenetre);
        btn7.drawTo(jeu->fenetre);
        btn8.drawTo(jeu->fenetre);
        btn9.drawTo(jeu->fenetre);
        btn10.drawTo(jeu->fenetre);
        btn11.drawTo(jeu->fenetre);
        jeu->fenetre.draw(jeu->joueur.sprite);
        if(jeu->map.map_select == 0)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap1);
        else if(jeu->map.map_select == 1)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap2);
        else if(jeu->map.map_select == 2)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap3);
        jeu->fenetre.display();
    }
}

void EcranTitre::paused(Jeu *jeu)
{

    sf::Event evenement;

    Button btn;
    Button btn2;
    if (!font.loadFromFile("sprites/police.ttf"))
        return;
    btn.btn_create((jeu->F_Largeur / 2) - 200, 450, 400, 100, 60, font, "Reprendre");
    btn2.btn_create((jeu->F_Largeur / 2) - 210, 600, 420, 100, 60, font, "Abandonner");

    jeu->sound.sound5.play();
    while (jeu->fenetre.isOpen())
    {
        while (jeu->fenetre.pollEvent(evenement))
        {
            if (evenement.type == sf::Event::MouseButtonPressed)
            {
                if (evenement.mouseButton.button == sf::Mouse::Left)
                {
                    if (btn.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        return;
                    }
                    if (btn2.isMouseOver(jeu->fenetre))
                    {
                        jeu->sound.sound5.play();
                        jeu->backStatus = true;
                        return;
                    }
                }
            }
        }
        textePaused.setString("Pause");
        float largeurTexte = textePaused.getLocalBounds().width;
        textePaused.setPosition((jeu->F_Largeur / 2) - (largeurTexte / 2), 200);
        jeu->fenetre.clear();
        jeu->fenetre.draw(spriteEcranTitre);
        jeu->fenetre.draw(textePaused);
        jeu->fenetre.draw(jeu->gold.texteCount);
        btn.drawTo(jeu->fenetre);
        btn2.drawTo(jeu->fenetre);
        jeu->fenetre.draw(texteVersion);
        if(jeu->map.map_select == 0)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap1);
        else if(jeu->map.map_select == 1)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap2);
        else if(jeu->map.map_select == 2)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap3);
        jeu->fenetre.display();
    }
}

void EcranTitre::killed(Jeu *jeu)
{
    Button btn;

    sf::Event evenement;

    if (!font.loadFromFile("sprites/police.ttf"))
        return;
    btn.btn_create((jeu->F_Largeur / 2) - 200, 600, 400, 100, 60, font, "Retourner au camp");

    while (jeu->fenetre.isOpen())
    {
        while (jeu->fenetre.pollEvent(evenement))
        {
            if (evenement.type == sf::Event::MouseButtonPressed)
            {
                if (evenement.mouseButton.button == sf::Mouse::Left)
                {
                    if (btn.isMouseOver(jeu->fenetre))
                    {             
                        jeu->sound.sound5.play();
                        return;
                    }
                }
            }
        }
        texteKilled.setString("Vous vous etes pris un sacre coup !");
        texteKilled2.setString("Score : " + std::to_string(jeu->gold.GoldCount));
        float largeurTexte = texteKilled.getLocalBounds().width;
        float hauteurTexte = texteKilled.getLocalBounds().height;
        texteKilled.setPosition((jeu->F_Largeur / 2) - (largeurTexte / 2), 300);
        float largeurTexte2 = texteKilled2.getLocalBounds().width;
        texteKilled2.setPosition((jeu->F_Largeur / 2) - (largeurTexte2 / 2), 350 + hauteurTexte);
        jeu->fenetre.clear();
        jeu->fenetre.draw(spriteEcranTitre);
        jeu->fenetre.draw(texteKilled);
        jeu->fenetre.draw(texteKilled2);
        jeu->fenetre.draw(texteVersion);
        btn.drawTo(jeu->fenetre);
        if(jeu->map.map_select == 0)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap1);
        else if(jeu->map.map_select == 1)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap2);
        else if(jeu->map.map_select == 2)
            jeu->fenetre.draw(jeu->ecranTitre.texteMap3);
        jeu->fenetre.display();
    }
}