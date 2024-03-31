#include "Objects/Paddle.hpp"


Paddle::Paddle(float x, float y, Resource_manager& resource_manager)
: Sprite_object(resource_manager, "paddle.png")
{
        m_sprite.setPosition(x, y);
        m_sprite.setOrigin(m_width / 2.f, m_height / 2.f);
}

void Paddle::update(int win_width)
{
        process_player_input(win_width);
        m_sprite.move(m_velocity);
}

void Paddle::process_player_input(int win_width)
{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
                m_velocity.x = -default_velocity;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) &&
                                        right() < win_width)
                m_velocity.x = default_velocity;
        else
                m_velocity.x = 0;
}

sf::FloatRect Paddle::getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}

void Paddle::set_up_texture(Resource_manager &resource_manager)
{
}
