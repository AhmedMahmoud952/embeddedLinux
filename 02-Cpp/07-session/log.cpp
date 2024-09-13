#include <iostream>
#include <string>
#include <vector>

enum class level : unsigned char {
    Info,
    Warning,
    Error
};

class Log{
    private:
        level lv;
        static std::vector<std::string> buffer;

    public:
        Log(level lv) : lv(lv) {};

        static Log Level(level lv){
            return Log(lv);
        }

        void operator<<(std::string msg){
            std::string temp = "[" +to_string(this->lv)+ "] " + msg;
            buffer.emplace_back(temp);
        }

        static void dump(){
            for(const auto& s : buffer){
                std::cout << s << std::endl;
            }
        }

        static void clear(){
            buffer.clear();
            std::cout << "Log buffer cleared." << std::endl;
        }

    private:
        std::string to_string(level level) {
            switch (level) {
                case level::Info:
                    return "Info";
                case level::Warning:
                    return "Warning";
                case level::Error:
                    return "Error";
                default:
                    return "Unknown";
            }
        }
};
 
std::vector<std::string> Log::buffer;

int main()
{
    Log::Level(level::Error) << "forget to close file";
    Log::Level(level::Info) << "file was open tuesday";
    Log::dump();
    Log::clear();

  return 0;
}