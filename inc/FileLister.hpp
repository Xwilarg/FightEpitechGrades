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
        FileLister(std::string &&folderName) noexcept;
        ~FileLister() noexcept = default;
        void Update();
        void Next() noexcept;
        void Previous() noexcept;
        const std::string *GetCurrent() const noexcept;

    private:
        std::vector<std::string> _files;
        unsigned int _index;
        const std::string _folderName;
    };
}

#endif // !FILELISTER_HPP_