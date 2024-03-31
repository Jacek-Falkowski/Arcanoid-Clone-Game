#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Resource_manager.hpp"
#include "Music_player.hpp"

class State;

class Game
{
public:
    Game();

    void run_main_loop();

    unsigned int get_window_width() const;

    unsigned int get_window_height() const;

    sf::RenderWindow &get_render_window();

    void change_state(State *state);
    sf::Event& get_event() {return event;}

    Resource_manager &get_resource_manager();

    Music_player &get_music_player();

private:
    std::shared_ptr<State> m_state;
    sf::RenderWindow m_window;
    Resource_manager m_resource_manager;
    Music_player m_music_player;
    sf::Font m_arial;
    sf::Event event;
    static constexpr unsigned int wndWidth = 1920;
    static constexpr unsigned int wndHeight = 1080;
};
