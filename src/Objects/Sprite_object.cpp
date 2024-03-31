#include "Objects/Sprite_object.hpp"

void Sprite_object::draw(sf::RenderWindow& window)
{
        window.draw(m_sprite);
}

void Sprite_object::center_origin()
{
        m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
}

sf::Sprite& Sprite_object::get_sprite()
{
        return m_sprite;
}

Sprite_object::Sprite_object(Resource_manager& resource_manager, std::string texture_name)
{
        m_sprite.setTexture(resource_manager.get_texture(texture_name));
}

void Sprite_object::set_up_sprite(Resource_manager& resource_manager, std::string texture_name)
{
        m_sprite.setTexture(resource_manager.get_texture(texture_name));
}
