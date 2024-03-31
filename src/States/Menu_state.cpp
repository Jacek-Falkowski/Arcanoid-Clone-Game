#include "States/Menu_state.hpp"
#include "Game.hpp"
#include "Collision.hpp"
#include <iostream>
#include "States/Play_state.hpp"
#include "States/Level_state.hpp"

Menu_state::Menu_state(Game *game)
    : State{game},
      Play_button{static_cast<float>(m_game->get_window_width() / 2), 505, m_game->get_resource_manager(), "start.png"},
      Level_button{static_cast<float>(m_game->get_window_width() / 2), 680, m_game->get_resource_manager(), "levels.png"},
      Quit_button{static_cast<float>(m_game->get_window_width() / 2), 855, m_game->get_resource_manager(), "exit.png"}
{
    m_background.setTexture(m_resource_manager.get_texture("menu.png"));
    m_background.setScale(game->get_window_width() / m_background.getLocalBounds().width,
                          game->get_window_height() / m_background.getLocalBounds().height);

}

void Menu_state::input()
{
    if (Play_button.MouseIntersect() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_game->change_state(new Play_state(m_game, 1));
        m_game->get_music_player().force_next();
    }

    if (Level_button.MouseIntersect() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_game->change_state(new Level_state(m_game));
    }

    if (Quit_button.MouseIntersect() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_game->get_render_window().close();
    }


}

void Menu_state::update()
{
}

void Menu_state::draw()
{
    m_game->get_render_window().draw(m_background);
    Play_button.draw(m_game->get_render_window());
    Level_button.draw(m_game->get_render_window());
    Quit_button.draw(m_game->get_render_window());
}
