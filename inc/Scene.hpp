#ifndef SCENE_HPP_
# define SCENE_HPP_

# include "GameObject.hpp"

namespace feg
{
    class Scene final
    {
    public:
        Scene() noexcept;
        ~Scene() noexcept = default;
        void Update(sf::RenderWindow &window) noexcept;

        template<typename T, typename... Args>
        std::unique_ptr<T> &AddGameObject(Args &&... args)
        {
            _allGameObjects.push_back(std::make_unique<T>(*this, args...));
            return (_allGameObjects[_allGameObjects.size() - 1]);
        }

    private:
        std::vector<std::unique_ptr<GameObject> > _allGameObjects;
    };
}

#endif // !SCENE