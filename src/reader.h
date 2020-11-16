#include <string>

class reader
{
    private:
        FILE* pipe;
    public:
        reader(const char* cmd);
        ~reader();
        std::string readLine();
};
