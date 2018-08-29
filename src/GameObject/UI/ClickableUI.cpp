#include "ClickableUI.hpp"
#include "Scene.hpp"
#include <iostream>
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
        if (scene.GetMousePressed() && mousePos.x >= GetPosition().x && mousePos.x <= GetPosition().x + GetSize().x
        && mousePos.y >= GetPosition().y && mousePos.y <= GetPosition().y + GetSize().y)
            Click();
        GameObject::Update(scene, window);
    }
}