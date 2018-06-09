#ifndef SCENE_HPP_
# define SCENE_HPP_

# include <memory>
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
        std::shared_ptr<GameObject> AddGameObject(Args &&... args)
        {
            _allGameObjects.push_back(std::make_shared<T>(args...));
            return (_allGameObjects[_allGameObjects.size() - 1]);
        }

    private:
        std::vector<std::shared_ptr<GameObject> > _allGameObjects;
    };
}

#endif // !SCENE