#ifndef CHRONO_HPP_
# define CHRONO_HPP_

# include <chrono>

namespace feg
{
    class Chrono
    {
    public:
        Chrono(int duration) noexcept;
        ~Chrono() noexcept = default;
        bool IsEnded() const noexcept;
        void Reset() noexcept;

    private:
        std::chrono::time_point<std::chrono::system_clock> ref;
        std::chrono::time_point<std::chrono::system_clock> _duration;
        int _durationMs;
    };
}

#endif /* !CHRONO_HPP_ */