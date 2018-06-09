#include "TextureManager.hpp"

namespace feg
{
    TextureManager::TextureManager()
        : _allTextures()
    { }

    const sf::Texture &TextureManager::GetTexture(std::string &&fileName)
    {
        auto elem = _allTextures.find(fileName);
        if (elem == _allTextures.end())
        {
            sf::Texture t;
            if (!t.loadFromFile(fileName))
                throw std::invalid_argument("Can't open " + fileName);
            _allTextures.insert(std::make_pair(fileName, std::move(t)));
            return (_allTextures.find(std::move(fileName))->second);
        }
        else
            return (elem->second);
    }
}