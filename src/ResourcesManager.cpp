#include "ResourcesManager.hpp"

namespace feg
{
    ResourcesManager::ResourcesManager()
        : _allTextures(), _allFonts()
    { }

    const sf::Font &ResourcesManager::GetFont(std::string &&fileName)
    {
        return (GetResource(std::move(fileName), _allFonts));
    }

    const sf::Texture &ResourcesManager::GetTexture(std::string &&fileName)
    {
        return (GetResource(std::move(fileName), _allTextures));
    }
}