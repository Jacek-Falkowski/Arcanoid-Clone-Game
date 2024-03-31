#include "Objects/Ball.hpp"

Ball::Ball(float X, float Y)
{
    shape.setPosition(X, Y);
    shape.setRadius(m_Radius);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(m_Radius, m_Radius);
}

void Ball::update(int wndWidth, int wndHeight)
{
    shape.move(velocity);
}

void Ball::draw(sf::RenderWindow &mTarget)
{
    mTarget.draw(shape);
}

void Ball::solve_bound_collisions(int wndWidth, int wndHeight) noexcept
{
    if (left() < 0)
        velocity.x = m_Velocity;
    else if (right() > wndWidth)
        velocity.x = -m_Velocity;

    if (top() < 50)
        velocity.y = m_Velocity;
    else if (bottom() > wndHeight)
        velocity.y = m_Velocity;
}

sf::FloatRect Ball::getGlobalBounds() const
{
    return shape.getGlobalBounds();
}

ExtraBall::ExtraBall(float X, float Y)
:Ball(X, Y)
{
shape.setFillColor(sf::Color::Green);
set_velocity_y(m_Velocity);
set_extr_status(true);
}
