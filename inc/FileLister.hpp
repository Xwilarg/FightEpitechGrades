#ifndef FILELISTER_HPP_
# define FILELISTER_HPP_

# include <vector>
# include <string>
# include <experimental/filesystem>

namespace feg
{
    class FileLister final
    {
    public:
        FileLister() noexcept;
        ~FileLister() noexcept = default;
        void Update();
        void Next() noexcept;
        void Previous() noexcept;
        const std::string *GetCurrent() const noexcept;

    private:
        std::vector<std::string> _files;
        std::string *_current;
        unsigned int _index;
    };
}

#endif // !FILELISTER_HPP_