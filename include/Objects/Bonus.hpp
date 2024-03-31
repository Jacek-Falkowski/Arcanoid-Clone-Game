#pragma once
#include "SFML/Graphics.hpp"
#include "Shape.hpp"

class Bonus : public Circle, public Sprite_object
{
public:
    Bonus(float x, float y, Resource_manager &resource_manager);

    void update(int win_width, int win_height);

    float x() const noexcept override { return m_sprite.getPosition().x; }

    float y() const noexcept override { return m_sprite.getPosition().y; }

    float radius() const noexcept override { return m_radius; }

    float left() const noexcept override { return x() - radius(); }

    float right() const noexcept override { return x() + radius(); }

    float top() const noexcept override { return y() - radius(); }

    float bottom() const noexcept override { return y() + radius(); }

    void set_up_texture(Resource_manager &resource_manager) override;

    void set_velocity_x(float x) { velocity.x = x; }

    void set_velocity_y(float y) { velocity.y = y; }

    bool is_destroyed() const { return destroyed; }

    void set_isSpecial1(bool b) { isSpecial1 = b; }

    bool is_special1() const { return isSpecial1; }

    void set_isSpecial2(bool b) { isSpecial2 = b; }

    bool is_special2() const { return isSpecial2; }

    void set_destroy_flag(bool b) { destroyed = b; }

    sf::FloatRect getGlobalBounds() const;

    bool isSpecial1 = false;
    bool isSpecial2 = false;
    static constexpr float default_velocity = 4.f;

private:
    void solve_bound_collisions(int win_width, int win_height) noexcept;
    sf::Vector2f velocity = sf::Vector2f{0, default_velocity};
    bool destroyed;
    float m_radius;
};

class BonusBall : public Bonus
{
public:
    BonusBall(float x, float y, Resource_manager &resource_manager);
};

class Bonushealth : public Bonus
{
public:
    Bonushealth(float x, float y, Resource_manager &resource_manager);
};