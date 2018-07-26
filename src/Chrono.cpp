#include "Chrono.hpp"

namespace feg
{
    Chrono::Chrono(int duration) noexcept
        : ref(std::chrono::system_clock::now() + std::chrono::milliseconds(duration)),
        _durationMs(duration)
    { }

    bool Chrono::IsEnded() const noexcept
    {
        return (std::chrono::system_clock::now() > ref);
    }

    void Chrono::Reset() noexcept
    {
        ref = std::chrono::system_clock::now() + std::chrono::milliseconds(_durationMs);
    }
}