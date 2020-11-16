#include <string>
#include <vector>
class utils
{
    public:
        static int getColorCode(std::string s);
        static std::vector<std::string> split(const std::string& str, const std::string& delim);
};
