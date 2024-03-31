#include "Objects/Brick.hpp"

Brick::Brick(float x, float y, Resource_manager& resource_manager)
:Sprite_object(resource_manager, "normal.png"),brick_health{1},score_value{10}
{
    m_sprite.setPosition(x, y);
    m_sprite.setOrigin(m_width / 2.f, m_height / 2.f);

}

void Brick::set_up_texture(Resource_manager& resource_manager) 
{

}
void Brick::update()
{
}

void Brick::draw(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}


sf::FloatRect Brick::getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}

void Brick::dmg()
{
    brick_health--;
    dmg_taken++;
    //m_sprite.setTextureRect(sf::IntRect(0, dmg_taken * m_height, m_width, m_height));
}

BronzeBrick::BronzeBrick(float x, float y, Resource_manager& resource_manager)
:Brick(x, y, resource_manager)
{
    m_sprite.setPosition(x, y);
    set_health(2);
    m_sprite.setOrigin(m_width / 2.f, m_height / 2.f);\
    set_up_sprite(resource_manager, "bronze.png");
    set_score_value(20);


}

SilverBrick::SilverBrick(float x, float y, Resource_manager& resource_manager)
:Brick(x, y, resource_manager)
{
    m_sprite.setPosition(x, y);
    set_health(3);
    m_sprite.setOrigin(m_width / 2.f, m_height / 2.f);\
    set_up_sprite(resource_manager, "silver.png");
    set_score_value(30);


}
GoldBrick::GoldBrick(float x, float y, Resource_manager& resource_manager)
:Brick(x, y, resource_manager)
{
    m_sprite.setPosition(x, y);
    set_health(4);
    m_sprite.setOrigin(m_width / 2.f, m_height / 2.f);\
    set_up_sprite(resource_manager, "gold.png");
    set_score_value(40);


}

SpecialBrickball::SpecialBrickball(float x, float y, Resource_manager& resource_manager)
:Brick(x, y, resource_manager)
{
    m_sprite.setPosition(x, y);
    m_sprite.setOrigin(m_width / 2.f, m_height / 2.f);\
    set_up_sprite(resource_manager, "special.png");
    set_score_value(50);
    set_isSpecial1(true);

}

SpecialBrickhealth::SpecialBrickhealth(float x, float y, Resource_manager& resource_manager)
:Brick(x, y, resource_manager)
{
    m_sprite.setPosition(x, y);
    m_sprite.setOrigin(m_width / 2.f, m_height / 2.f);\
    set_up_sprite(resource_manager, "special.png");
    set_score_value(50);
    set_isSpecial2(true);

}

