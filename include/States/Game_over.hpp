#pragma once
#include "States/State_base.hpp"
#include <fstream>
#include <regex>
#include <filesystem>
#include <cstdio>
#include <string> 

class Game_over : public State
{
public:
    Game_over(Game *game, int score);

    void input() override;

    void update() override;

    void draw() override;

private:

    sf::Sprite m_background;
    sf::Text m_gameover;
    sf::Text m_score;
    sf::Text playerText;
    sf::String playerInput;

    
};