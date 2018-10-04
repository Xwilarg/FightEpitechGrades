#include <fstream>
#include "MarkFile.hpp"
#include "ParsingError.hpp"

namespace feg
{
    MarkFile::MarkFile(const std::string &path)
        : _marks()
    {
        int indexMark = -1;
        int indexUnit = -1;
        int indexTitle = -1;

        std::ifstream file(path, std::ios::in);
        if (!file)
            throw std::invalid_argument("Can't open " + path);
        std::string line;
        getline(file, line);

        // Get categories positions
        int index = 0;
        for (const std::string &s : GetArgs(line))
        {
            if (s == "Title")
                indexTitle = index;
            else if (s == "Unit")
                indexUnit = index;
            else if (s == "Final mark")
                indexMark = index;
            index++;
        }
        if (indexMark == -1)
            throw ParsingError("File don't have a Final Mark field.");
        else if (indexTitle == -1)
            throw ParsingError("File don't have a Title field.");
        else if (indexUnit == -1)
            throw ParsingError("File don't have a Unit field.");

        // Create marks
        while (getline(file, line))
        {
            std::vector<std::string> newLine = GetArgs(line);
            _marks.push_back({newLine[static_cast<unsigned int>(indexTitle)], newLine[static_cast<unsigned int>(indexUnit)], std::stoi(newLine[static_cast<unsigned int>(indexMark)])});
        }
    }

    std::vector<std::string> MarkFile::GetArgs(const std::string &line) noexcept
    {
        std::string curr = "";
        std::vector<std::string> res;
        for (const char &c : line)
        {
            if (c == '"' || c < 32 || c == 127)
            { }
            else if (c == ';')
            {
                res.push_back(curr);
                curr = "";
            }
            else
                curr += c;
        }
        res.push_back(curr);
        return (res);
    }
}