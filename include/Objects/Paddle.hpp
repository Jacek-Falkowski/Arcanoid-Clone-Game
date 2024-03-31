#pragma once
#include "SFML/Graphics.hpp"
#include "Objects/Shape.hpp"
#include "Sprite_object.hpp"

class Paddle : public Rectangle, public Sprite_object
{
public:
    Paddle(float x, float y, Resource_manager &resource_manager);

    void update(int win_width);

    float x() const noexcept override { return m_sprite.getPosition().x; }

    float y() const noexcept override { return m_sprite.getPosition().y; }

    float width() const noexcept override { return m_sprite.getLocalBounds().width; }

    float height() const noexcept override { return m_sprite.getLocalBounds().height; }

    float left() const noexcept override { return x() - width() / 2.f; }

    float right() const noexcept override { return x() + width() / 2.f; }

    float top() const noexcept override { return y() - height() / 2.f; }

    float bottom() const noexcept override { return y() + height() / 2.f; }
    sf::Sprite &get_shape() { return m_sprite; }

    void draw(sf::RenderWindow &window) { window.draw(m_sprite); }

    sf::FloatRect getGlobalBounds() const;

    void set_up_texture(Resource_manager &resource_manager) override;

    static constexpr float m_width{160.f};
    static constexpr float m_height{30.f};
    static constexpr float default_velocity{18.f};

private:
    sf::Vector2f m_velocity;
    void process_player_input(int win_width);
};
