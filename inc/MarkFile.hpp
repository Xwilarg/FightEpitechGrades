#ifndef MARKFILE_HPP_
# define MARKFILE_HPP_

# include <string>
# include <vector>

namespace feg
{
    class MarkFile final
    {
    public:
        MarkFile(const std::string &path);
        ~MarkFile() noexcept = default;

    private:
        struct Mark
        {
            std::string title;
            std::string unit;
            int finalMark;
        };
        std::vector<std::string> GetArgs(const std::string &line) noexcept;
        std::vector<Mark> _marks;
    };
}

#endif // !MARKFILE_HPP_