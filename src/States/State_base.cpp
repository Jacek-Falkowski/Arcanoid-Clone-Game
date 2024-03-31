#include "States/State_base.hpp"
#include "Game.hpp"

State::State(Game *game)
    : m_game{game},
        m_resource_manager{game->get_resource_manager()},
      m_window_width{static_cast<float>(game->get_window_width())},
      m_window_height{static_cast<float>(game->get_window_height())}
{
}

void State::input()
{

}

void State::update()
{
        
}
void State::draw()
{
        
}

void State::logic()
{
        input();
        update();
        draw();
}
