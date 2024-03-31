#pragma once
#include "SFML/Graphics.hpp"
#include "Objects/Shape.hpp"
#include "Sprite_object.hpp"

class Brick : public Rectangle, public Sprite_object
{
public:
    Brick(float x, float y, Resource_manager &resource_manager);

    void update();

    void draw(sf::RenderWindow &window);

    float x() const noexcept override { return m_sprite.getPosition().x; }

    float y() const noexcept override { return m_sprite.getPosition().y; }

    float width() const noexcept override { return m_sprite.getLocalBounds().width; }

    float height() const noexcept override { return m_sprite.getLocalBounds().height; }

    float left() const noexcept override { return x() - width() / 2.f; }

    float right() const noexcept override { return x() + width() / 2.f; }

    float top() const noexcept override { return y() - height() / 2.f; }

    float bottom() const noexcept override { return y() + height() / 2.f; }

    bool is_destroyed() const { return destroyed; }

    void set_destroy_flag(bool b) { destroyed = b; }

    void set_isSpecial1(bool b) { isSpecial1 = b; }

    bool is_special1() const { return isSpecial1; }

    void set_isSpecial2(bool b) { isSpecial2 = b; }

    bool is_special2() const { return isSpecial2; }

    int get_score_value() const { return score_value; }

    sf::FloatRect getGlobalBounds() const;

    void set_up_texture(Resource_manager &resource_manager) override;

    void dmg();

    void set_health(int x) { brick_health = x; }

    void set_score_value(int x) { score_value = x; }

    int get_health() { return brick_health; }

    bool destroyed = false;
    int brick_health;
    int dmg_taken;
    int score_value;
    bool isSpecial1 = false;
    bool isSpecial2 = false;
    static constexpr float m_width{1920 / 13};
    static constexpr float m_height{40.f};
    static constexpr float default_velocity{8.f};
};

bool operator==(const Brick &a, const Brick &b);
bool operator!=(const Brick &a, const Brick &b);

class BronzeBrick : public Brick
{
public:
    BronzeBrick(float x, float y, Resource_manager &resource_manager);

private:
};

class SilverBrick : public Brick
{
public:
    SilverBrick(float x, float y, Resource_manager &resource_manager);

private:
};

class GoldBrick : public Brick
{
public:
    GoldBrick(float x, float y, Resource_manager &resource_manager);

private:
};

class SpecialBrickball : public Brick
{
public:
    SpecialBrickball(float x, float y, Resource_manager &resource_manager);

private:
};

class SpecialBrickhealth : public Brick
{
public:
    SpecialBrickhealth(float x, float y, Resource_manager &resource_manager);

private:
};