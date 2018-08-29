#include "FileLister.hpp"

namespace feg
{
    FileLister::FileLister(std::string &&folderName) noexcept
        : _files(), _current(nullptr), _index(0), _folderName(std::move(folderName))
    {
        Update();
    }

    void FileLister::Update()
    {
        _files.clear();
        for (const auto &s : std::experimental::filesystem::directory_iterator(_folderName))
        {
            if (s.path().filename() != "README.md")
                _files.push_back(s.path());
        }
        _index = 0;
        if (_files.size() == 0)
            _current = nullptr;
        else
            _current = &_files[0];
    }

    void FileLister::Next() noexcept
    {
        if (_files.size() == 0)
            return;
        if (_index == _files.size() - 1)
            _index = 0;
        else
            _index++;
        _current = &_files[_index];
    }

    void FileLister::Previous() noexcept
    {
        if (_files.size() == 0)
            return;
        if (_index == 0)
            _index = _files.size() - 1;
        else
            _index--;
        _current = &_files[_index];
    }

    const std::string *FileLister::GetCurrent() const noexcept
    {
        return (_current);
    }
}