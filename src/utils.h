#include <string>
#include <vector>
class utils
{
    public:
        static int getColorCode(char c);
        static std::vector<std::string> split(const std::string& str, const std::string& delim);
        static int stringToMsgType(char s);

        enum MessageType {
            VERBOSE,
            DEBUG,
            INFO,
            WARNING,
            ERROR,
            FATAL
        };
};
