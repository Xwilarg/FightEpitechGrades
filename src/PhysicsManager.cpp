#include "PhysicsManager.hpp"

namespace feg
{
    PhysicsManager::PhysicsManager()
        : _layers()
    { }

    void PhysicsManager::AddLayer(PhysicsLayer layer1, PhysicsLayer layer2) noexcept
    {
        _layers.push_back(std::make_pair(layer1, layer2));
    }

    bool PhysicsManager::DoesLayersCollide(PhysicsLayer layer1, PhysicsLayer layer2) const noexcept
    {
        for (const auto &pair : _layers)
        {
            if (pair.first == layer1 && pair.second == layer2)
                return (true);
        }
        return (false);
    }
}