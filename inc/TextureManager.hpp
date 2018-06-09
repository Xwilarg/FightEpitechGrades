#ifndef TEXTUREMANAGER_HPP_
# define TEXTUREMANAGER_HPP_

# include <SFML/Graphics.hpp>
# include <unordered_map>

namespace feg
{
    class TextureManager final
    {
    public:
        TextureManager();
        ~TextureManager() noexcept = default;
        const sf::Texture &GetTexture(std::string &&fileName);

    private:
        std::unordered_map<std::string, sf::Texture> _allTextures;
    };
}

#endif // !TEXTUREMANAGER_HPP_