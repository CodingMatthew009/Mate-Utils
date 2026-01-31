#include "../Include/MLogger.hpp"
#include "../Include/Clock.hpp"

namespace utils
{
    Logger& Logger::Instance() 
    {
        static Logger instance;
        return instance;
    }

    void Log(std::string& message, LFlags logger_flag)
    {
        std::string time = FORMATTED_TIME_SINCE_START();
    }



    Logger::Logger() {};
}

