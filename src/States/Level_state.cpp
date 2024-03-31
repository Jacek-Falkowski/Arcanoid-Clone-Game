#include "States/Menu_state.hpp"
#include "Game.hpp"
#include "Collision.hpp"
#include <iostream>
#include "States/Play_state.hpp"
#include "States/Level_state.hpp"

Level_state::Level_state(Game *game)
    : State{game}, Map1{480, 270, m_game->get_resource_manager(), "first.png"}, Map2{1440, 270, m_game->get_resource_manager(), "second.png"}, Map3{480, 810, m_game->get_resource_manager(), "third.png"}, Map4_boss{1440, 810, m_game->get_resource_manager(), "fourth.png"}
{
    m_background.setTexture(m_resource_manager.get_texture("background.png"));
    m_background.setScale(game->get_window_width() / m_background.getLocalBounds().width,
                          game->get_window_height() / m_background.getLocalBounds().height);
}

void Level_state::input()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        m_game->change_state(new Menu_state(m_game));

    if (Map1.MouseIntersect() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_game->change_state(new Play_state(m_game, 0));
    }

    if (Map2.MouseIntersect() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_game->change_state(new Play_state(m_game, 1));
    }

    if (Map3.MouseIntersect() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_game->change_state(new Play_state(m_game, 2));
    }

    if (Map4_boss.MouseIntersect() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        m_game->change_state(new Play_state(m_game, 3));
    }
}

void Level_state::update()
{
}

void Level_state::draw()
{
    m_game->get_render_window().draw(m_background);
    Map1.draw(m_game->get_render_window());
    Map2.draw(m_game->get_render_window());
    Map3.draw(m_game->get_render_window());
    Map4_boss.draw(m_game->get_render_window());
}
