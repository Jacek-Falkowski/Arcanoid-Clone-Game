#pragma once
#include "Objects/Ball.hpp"
#include "Objects/Paddle.hpp"
#include "Objects/Brick.hpp"
#include "Objects/Bonus.hpp"
#include "States/State_base.hpp"

enum class State_of_game
{
        play,
        lost,
        win
};

class Game;

class Play_state : public State
{
public:
        Play_state(Game *game, int map);

        void input() override;

        void update() override;

        void draw() override;

        int score;
private:
        bool Ball_on_paddle;
        Ball ball;
        Paddle paddle;
        int health;
        enum State_of_game curr_state;
        sf::Text press_space;
        sf::Text win_label;
        sf::Text lost_label;
        sf::Text health_label;
        sf::Text score_label;
        std::vector<Brick> bricks;
        std::vector<Bonus> bonuses;
        std::vector<ExtraBall> bonusballs;
        GoldBrick test;
        GoldBrick test2;
        sf::Sprite m_background;
        
};