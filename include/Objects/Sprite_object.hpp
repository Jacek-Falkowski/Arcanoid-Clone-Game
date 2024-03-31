#pragma once

#include "Resource_manager.hpp"
#include "SFML/Graphics.hpp"

class Sprite_object
{
public:
  void draw(sf::RenderWindow &window);

  void center_origin();

  sf::Sprite &get_sprite();

protected:
  Sprite_object(Resource_manager &resource_manager, std::string texture_name);

  void set_up_sprite(Resource_manager &resource_manager, std::string texture_name);

  virtual void set_up_texture(Resource_manager &resource_manager) = 0;

  sf::Sprite m_sprite;
};
