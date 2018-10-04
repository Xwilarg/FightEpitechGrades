#ifndef PARSINGERROR_HPP_
# define PARSINGERROR_HPP_

# include <stdexcept>

namespace feg
{
    class ParsingError final : public std::runtime_error
    {
    public:
        ParsingError(std::string &&msg) noexcept;
    };
}

#endif // !PARSINGERROR_HPP_