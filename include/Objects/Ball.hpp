#pragma once
#include <SFML/Graphics.hpp>
#include "Objects/Shape.hpp"

class Ball : public Circle
{

public:
    static const sf::Color m_color;
    static constexpr float m_Radius{7.f};
    static constexpr float m_Velocity{9.f};

    sf::CircleShape shape;
    sf::Vector2f velocity{-m_Velocity, -m_Velocity};

    Ball(float X, float Y);

    float x() const noexcept override { return shape.getPosition().x; }

    float y() const noexcept override { return shape.getPosition().y; }

    float radius() const noexcept override { return shape.getRadius(); }

    float left() const noexcept override { return x() - shape.getRadius(); }

    float right() const noexcept override { return x() + shape.getRadius(); }

    float top() const noexcept override { return y() - shape.getRadius(); }

    float bottom() const noexcept override { return y() - shape.getRadius(); }

    void set_velocity_x(float x) { velocity.x = x; }

    void set_velocity_y(float y) { velocity.y = y; }

    static constexpr float get_velocity() { return m_Velocity; }

    sf::CircleShape &get_shape() { return shape; }

    void update(int wndWidth, int wndHeight);

    void draw(sf::RenderWindow &mTarget);

    void solve_bound_collisions(int win_width, int win_height) noexcept;

    sf::FloatRect getGlobalBounds() const;
};

class ExtraBall : public Ball
{
public:
    ExtraBall(float X, float Y);
    bool get_extr_status(bool a) { return extr_status; };
    void set_extr_status(bool a) { extr_status = a; };
    bool extr_status;
    bool is_destroyed() const { return isDestroyed; };
    void set_is_destroyed(bool a) { isDestroyed = a; };
    bool isDestroyed = false;
};