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
    sf::Event evenement;
    sf::Clock timer;
    timer.restart();
    while (jeu->fenetre.isOpen())
    {
        while (jeu->fenetre.pollEvent(evenement))
        {
            if (evenement.type == sf::Event::KeyPressed && timer.getElapsedTime().asSeconds() > 1) 
                return;
        }
        texteKilled.setString("Vous etes mort...\nScore : " + std::to_string(jeu->gold.GoldCount));
        float largeurTexte = texteKilled.getLocalBounds().width;
        float hauteurTexte = texteKilled.getLocalBounds().height;
        texteKilled.setPosition((jeu->F_Largeur / 2) - (largeurTexte / 2), (jeu->F_Hauteur / 2) - (hauteurTexte));
        jeu->fenetre.clear();
        jeu->fenetre.draw(spriteEcranTitre);
        jeu->fenetre.draw(texteKilled);
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