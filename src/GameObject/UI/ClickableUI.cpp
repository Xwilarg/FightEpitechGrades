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
        if (scene.GetMousePressed() && mousePos.x >= GetPosition().x + GetSize().x * 2.5f && mousePos.x <= GetPosition().x + GetSize().x * 3.5f
        && mousePos.y >= GetPosition().y + GetSize().y && mousePos.y <= GetPosition().y + GetSize().y * 2.f)
            Click();
        GameObject::Update(scene, window);
    }
}