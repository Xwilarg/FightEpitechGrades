#ifndef CLICKABLEUI_HPP_
# define CLICKABLEUI_HPP_

# include "GameObject.hpp"

namespace feg
{
    class ClickableUI : GameObject
    {
    public:
        ~ClickableUI() noexcept = default;
        void Update(Scene &scene, sf::RenderWindow &window) noexcept override;
        virtual void Click() = 0;
    };
}

#endif // !CLICKABLEUI_HPP_