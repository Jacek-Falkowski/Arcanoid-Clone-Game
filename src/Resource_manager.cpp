#include "Resource_manager.hpp"
#include "Utility.hpp"
#include "rapidjson/document.h"
#include <functional>
#include <future>
#include <filesystem>
namespace rj = rapidjson;

sf::Texture import_texture(const std::string &texture_name)
{
        std::filesystem::path texture_path = std::filesystem::path("img") / texture_name;

        std::regex png_suffix_regex(R"#(.+\.png)#");
        if (!std::regex_match(texture_name, png_suffix_regex))
        {
                throw std::runtime_error("Invalid texture file format: " + texture_name);
        }

        if (std::filesystem::exists(texture_path))
        {
                sf::Texture texture;
                if (texture.loadFromFile(texture_path.string()))
                        return texture;
                else
                        throw std::runtime_error("Cannot load texture: " + texture_name);
        }
        else
        {
                throw std::runtime_error("Texture file not found: " + texture_path.string());
        }
}

sf::Font import_font(const std::string &font_name)
{
        std::filesystem::path font_path = std::filesystem::path("fonts") / font_name;

        std::regex ttf_suffix_regex(R"#(.+\.ttf)#");
        if (!std::regex_match(font_name, ttf_suffix_regex))
        {
                throw std::runtime_error("Invalid texture file format: " + font_name);
        }

        if (std::filesystem::exists(font_path))
        {
                sf::Font font;
                if (font.loadFromFile(font_path.string()))
                        return font;
                else
                        throw std::runtime_error("Cannot load font: " + font_name);
        }
        else
        {
                throw std::runtime_error("Font file not found: " + font_path.string());
        }
}

music_ptr import_music(const std::string &music_name)
{
        std::filesystem::path music_path = std::filesystem::path("sfx") / music_name;

        std::regex ogg_suffix_regex(R"#(.+\.ogg)#");
        if (!std::regex_match(music_name, ogg_suffix_regex))
        {
                throw std::runtime_error("Invalid texture file format: " + music_name);
        }

        if (std::filesystem::exists(music_path))
        {
                music_ptr music = new sf::Music();
                if (music->openFromFile(music_path.string()))
                        return music;
                else
                        throw std::runtime_error("Cannot load music: " + music_name);
        }
        else
        {
                throw std::runtime_error("Music file not found: " + music_path.string());
        }
}

std::vector<int> import_maps(rapidjson::GenericArray<true, rapidjson::Value> arr)
{
        std::vector<int> map;

        for (rj::SizeType i = 0; i < arr.Size(); ++i)
        {
                if (arr[i].IsInt())
                {
                        map.push_back(arr[i].GetInt());
                }
        }

        return map;
}

Resource_manager::Resource_manager()
{
        std::string json;
        json.reserve(1500U);
        util::parse_json_file(json, "resources.json");

        rj::Document doc;
        doc.Parse(json.c_str());

        std::size_t n;
        rj::SizeType i;
        const rj::Value *arr;

        std::vector<std::pair<std::future<sf::Texture>, const char *>> texture_futures;
        std::vector<std::pair<std::future<sf::Font>, const char *>> font_futures;
        std::vector<std::future<music_ptr>> music_futures;
        std::vector<std::future<std::vector<int>>> map_futures;

        arr = &doc["textures"];
        assert(arr->IsArray());
        for (i = 0; i < arr->Size(); ++i)
        {
                auto name = (*arr)[i].GetString();
                texture_futures.emplace_back(std::make_pair(std::async(std::launch::async, import_texture, name), name));
        }

        arr = &doc["fonts"];
        assert(arr->IsArray());
        for (i = 0; i < arr->Size(); ++i)
        {
                auto name = (*arr)[i].GetString();
                font_futures.emplace_back(std::make_pair(std::async(std::launch::async, import_font, name), name));
        }

        arr = &doc["music"];
        assert(arr->IsArray());
        for (i = 0; i < arr->Size(); ++i)
        {
                music_futures.emplace_back(std::async(std::launch::async, import_music, (*arr)[i].GetString()));
        }

        arr = &doc["maps"];
        assert(arr->IsArray());
        for (i = 0; i < arr->Size(); ++i)
        {
                map_futures.emplace_back(std::async(std::launch::async, import_maps, (*arr)[i].GetArray()));
        }

        for (auto &pair : texture_futures)
                m_textures.insert(std::make_pair(pair.second, pair.first.get()));

        for (auto &pair : font_futures)
                m_fonts.insert(std::make_pair(pair.second, pair.first.get()));

        for (auto &future : music_futures)
                m_music.emplace_back(future.get());

        for (auto &future : map_futures)
                m_game_maps.emplace_back(future.get());
}

Resource_manager::~Resource_manager()
{
        for (auto &music : m_music)
                delete music;
}

sf::Texture &Resource_manager::get_texture(const std::string &texture_name)
{
        auto elem = m_textures.find(texture_name);
        if (elem != m_textures.end())
        {
                return elem->second;
        }

        throw std::runtime_error("Cannot find a texture: " + texture_name);
}

sf::Font &Resource_manager::get_font(const std::string &font_name)
{
        auto elem = m_fonts.find(font_name);
        if (elem != m_fonts.end())
        {
                return elem->second;
        }

        throw std::runtime_error("Cannot find a font_name: " + font_name);
}

std::vector<int> Resource_manager::get_game_maps(const int &i)
{
        return m_game_maps[i];
}
