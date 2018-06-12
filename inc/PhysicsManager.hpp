#ifndef PHYSICSMANAGER_HPP_
# define PHYSICSMANAGER_HPP_

# include <vector>

namespace feg
{
    class PhysicsManager
    {
    public:
        enum PhysicsLayer
        {
            NONE,
            PLAYER
        };

        ~PhysicsManager() noexcept = default;
        PhysicsManager();
        void AddLayer(PhysicsLayer layer1, PhysicsLayer layer2) noexcept;
        bool DoesLayersCollide(PhysicsLayer layer1, PhysicsLayer layer2) const noexcept;

    private:
        std::vector<std::pair<PhysicsLayer, PhysicsLayer> > _layers;
    };
}

#endif // !PHYSICSMANAGER_HPP_