#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "States/State_base.hpp"
#include "States/Play_state.hpp"
#include "States/Menu_state.hpp"
#include <thread>

#include <iostream>

Game::Game()
    : m_resource_manager{},
      m_music_player(m_resource_manager)
{
    m_window.create({wndWidth, wndHeight}, "Arkanoid");
    m_window.setFramerateLimit(60);
    change_state(new Menu_state(this));
}

void Game::run_main_loop()
{
    m_music_player.play();

    std::thread thread([&](){
        while (true) {
            if (m_music_player.finished())
                m_music_player.next();

            m_music_player.try_force_switch();

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        };
    });

    while (m_window.isOpen())
    {
        m_window.clear();

        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }
        auto state_guard = m_state;
        m_state->logic();

        m_window.display();
    }

    thread.join();
}

unsigned int Game::get_window_width() const
{
    return wndWidth;
}

unsigned int Game::get_window_height() const
{
    return wndHeight;
}

sf::RenderWindow &Game::get_render_window()
{
    return m_window;
}

void Game::change_state(State *state)
{
    m_state.reset(std::move(state));
}

Resource_manager &Game::get_resource_manager()
{
    return m_resource_manager;
}

Music_player &Game::get_music_player()
{
    return m_music_player;
}