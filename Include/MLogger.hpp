#pragma once
#include "./General/Enums.hpp"

#include <string>
#include <vector>

namespace utils 
{
    class Logger 
    {
        public:
            struct LogEntry {
                int timestamp;
                std::string message;
                LFlags log_flag;
            };


            static Logger& Instance();

            Logger(const Logger&) = delete;
            Logger &operator=(const Logger&) = delete;

            void Log(std::string& message, LFlags logger_flag);

            void Log(const char* message, LFlags logger_flag);

            std::vector<LogEntry> entries();

        private:
            Logger();

    };

    #define LOG(message, logger_flag) \
        Logger::Instance().Log(message, logger_flag)
}