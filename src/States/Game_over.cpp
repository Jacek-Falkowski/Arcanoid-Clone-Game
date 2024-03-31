#include "States/Game_over.hpp"
#include "Game.hpp"
#include <iostream>
#include "States/Play_state.hpp"
#include "States/Level_state.hpp"
#include "States/Menu_state.hpp"

namespace fs = std::filesystem;

Game_over::Game_over(Game *game, int score)
    : State{game},
      m_gameover{"GAME OVER", m_resource_manager.get_font("Arial.ttf"), 80},
      m_score{std::string("Your Score: ") + std::to_string(score), m_resource_manager.get_font("Arial.ttf"), 45},
      playerText{"", m_resource_manager.get_font("Arial.ttf"), 25}

{
    m_background.setTexture(m_resource_manager.get_texture("background.png"));
    m_background.setScale(game->get_window_width() / m_background.getLocalBounds().width,
                          game->get_window_height() / m_background.getLocalBounds().height);
    m_gameover.setStyle(sf::Text::Bold);
    m_gameover.setFillColor(sf::Color::Red);
    m_gameover.setOrigin(m_gameover.getLocalBounds().width / 2.f, m_gameover.getLocalBounds().height / 2.f);
    m_gameover.setPosition(m_game->get_window_width() / 2.f, 90);

    m_score.setStyle(sf::Text::Bold);
    m_score.setOrigin(m_gameover.getLocalBounds().width / 2.f, m_gameover.getLocalBounds().height / 2.f);
    m_score.setPosition(m_game->get_window_width() / 2.f, 300);

    m_score.setOrigin(m_score.getLocalBounds().width / 2.f, m_score.getLocalBounds().height / 2.f);
    m_gameover.setFillColor(sf::Color::Red);

    playerText.setStyle(sf::Text::Bold);
    playerText.setFillColor(sf::Color::Red);
    playerText.setOrigin(m_gameover.getLocalBounds().width / 2.f, m_gameover.getLocalBounds().height / 2.f);
    playerText.setPosition(m_game->get_window_width() / 2.f, 500);

}

void Game_over::input()
{

}

void Game_over::update()
{
}

void Game_over::draw()
{
    m_game->get_render_window().draw(m_background);
    m_game->get_render_window().draw(m_gameover);
    m_game->get_render_window().draw(m_score);
    m_game->get_render_window().draw(playerText);
}
