#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <algorithm>
#include "rapidjson/document.h"
#include <regex>

using music_ptr = sf::Music *;

class Resource_manager
{
public:
    Resource_manager();

    ~Resource_manager();

    sf::Texture &get_texture(const std::string &texture_name);

    sf::SoundBuffer &get_sound(const std::string &sound_name);

    sf::Font &get_font(const std::string &font_name);

    std::vector<int> get_game_maps(const int &i);

private:
    std::map<std::string, sf::Texture> m_textures;
    std::map<std::string, sf::Font> m_fonts;
    std::vector<music_ptr> m_music;
    std::vector<std::vector<int>> m_game_maps;

    friend class Music_player;

};
