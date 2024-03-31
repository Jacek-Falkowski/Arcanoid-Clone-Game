#pragma once
#include "States/State_base.hpp"

class Level_state : public State
{
public:
    Level_state(Game *game);

    void input() override;

    void update() override;

    void draw() override;

private:
    Button Map1;
    Button Map2;
    Button Map3;
    Button Map4_boss;
    sf::Sprite m_background;
};