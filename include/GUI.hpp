#include <SFML/Graphics.hpp>
#include <Objects/Sprite_object.hpp>

class Button : public Sprite_object
{

public:
    Button(float x, float y, Resource_manager &resource_manager, std::string texture_name);

    void update();

    void draw(sf::RenderWindow &window);

    sf::FloatRect GetPossition();

    bool MouseIntersect();

    void set_up_texture(Resource_manager &resource_manager) override;

private:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Color defColor = sf::Color(110, 110, 110, 255);
    static constexpr float m_width{250.f};
    static constexpr float m_height{100.f};
};