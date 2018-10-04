#include "ParsingError.hpp"

namespace feg
{
    ParsingError::ParsingError(std::string &&msg) noexcept
        : std::runtime_error(std::move(msg))
    { }
}