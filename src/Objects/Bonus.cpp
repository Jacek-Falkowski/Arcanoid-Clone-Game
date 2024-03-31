#include "Objects/Bonus.hpp"

Bonus::Bonus(float x, float y, Resource_manager& resource_manager)
        : Sprite_object(resource_manager, "bonus.png")
{
        destroyed = false;
        m_radius = m_sprite.getLocalBounds().width / 2;
        m_sprite.setPosition(x, y);
        m_sprite.setOrigin(m_radius, m_radius);

        set_up_texture(resource_manager);
}

void Bonus::update(int win_width, int win_height)
{
        m_sprite.move(velocity);
        solve_bound_collisions(win_width, win_height);
}

void Bonus::solve_bound_collisions(int win_width, int win_height) noexcept
{
        if (bottom() > win_height) {
                velocity.y = 0;
                destroyed = true;
        }
}
void Bonus::set_up_texture(Resource_manager& resource_manager)
{
}

sf::FloatRect Bonus::getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}

BonusBall::BonusBall(float x, float y, Resource_manager& resource_manager)
:Bonus( x, y, resource_manager)
{
    set_isSpecial1(true);
}

Bonushealth::Bonushealth(float x, float y, Resource_manager& resource_manager)
:Bonus( x, y, resource_manager)
{
    set_isSpecial2(true);
}