#include "ClickableUI.hpp"
#include "Scene.hpp"

namespace feg
{
    ClickableUI::ClickableUI(const sf::Texture &texture) noexcept
        : GameObject(texture)
    {
        SetColor(sf::Color::Red);
    }

    void ClickableUI::Update(Scene &scene, sf::RenderWindow &window) noexcept
    {
        sf::Vector2i mousePos = scene.GetMousePosition();
        if (scene.GetMousePressed() && mousePos.x >= GetPosition().x + GetSize().x && mousePos.x <= GetPosition().x + GetSize().x * 2.f
        && mousePos.y >= GetPosition().y + GetSize().y * 2.f && mousePos.y <= GetPosition().y + GetSize().y * 3.f)
            Click();
        GameObject::Update(scene, window);
    }
}