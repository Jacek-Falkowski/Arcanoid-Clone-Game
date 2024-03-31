#pragma once
#include "GUI.hpp"
#include "Resource_manager.hpp"
class Game;

class State
{
public:
    void logic();

    virtual void input();

    virtual void update();

    virtual void draw();

    

protected:
    
    explicit State(Game *game);

    Game *m_game;
    Resource_manager& m_resource_manager;
    const float m_window_width;
    const float m_window_height;
};
