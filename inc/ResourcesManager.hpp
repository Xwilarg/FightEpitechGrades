#ifndef RESOURCESMANAGER_HPP_
# define RESOURCESMANAGER_HPP_

# include <SFML/Graphics.hpp>
# include <unordered_map>

namespace feg
{
    class ResourcesManager final
    {
    public:
        ResourcesManager();
        ~ResourcesManager() noexcept = default;
        const sf::Texture &GetTexture(std::string &&fileName);
        const sf::Font &GetFont(std::string &&fileName);

    private:
        template<typename T>
        const T &GetResource(std::string &&fileName, std::unordered_map<std::string, T> &_allResources)
        {
            auto elem = _allResources.find(fileName);
            if (elem == _allResources.end())
            {
                T t;
                if (!t.loadFromFile(fileName))
                    throw std::invalid_argument("Can't open " + fileName);
                _allResources.insert(std::make_pair(fileName, std::move(t)));
                return (_allResources.find(std::move(fileName))->second);
            }
            else
                return (elem->second);
        }
        std::unordered_map<std::string, sf::Texture> _allTextures;
        std::unordered_map<std::string, sf::Font> _allFonts;
    };
}

#endif // !RESOURCESMANAGER_HPP_