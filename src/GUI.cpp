#include <SFML/Graphics.hpp>
#include "GUI.hpp"

Button::Button(float x, float y, Resource_manager &resource_manager,std::string texture_name)
:  Sprite_object(resource_manager, "start.png")
{
    m_sprite.setPosition(x, y);
    m_sprite.setOrigin(m_width / 2.f, m_height / 2.f);
    set_up_sprite(resource_manager, texture_name);
}

void Button::update()
{
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}

sf::FloatRect Button::GetPossition()
{
	return m_sprite.getGlobalBounds();
}

bool Button::MouseIntersect()
{
	return GetPossition().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()));
}

void Button::set_up_texture(Resource_manager &resource_manager)
{

}