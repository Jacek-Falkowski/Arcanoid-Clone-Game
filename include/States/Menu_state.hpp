#pragma once
#include "States/State_base.hpp"

class Menu_state : public State
{
public:
    Menu_state(Game *game);

    void input() override;

    void update() override;

    void draw() override;

private:
    sf::Sprite m_background;
    Button Play_button;
    Button Level_button;
    Button Quit_button;
};