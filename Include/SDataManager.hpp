#pragma once

#include <fstream>
#include <cstdlib>
#include <sstream>
#include <variant>


//                  use INFILE for word seperation, checking first line for type on loading

namespace utils
{
    class SDManager
    {
        public:
            union types {
                int _int;
                float _float;
                double _double;
                bool _bool;
            };

            static SDManager& Instance();

            SDManager(const SDManager&) = delete;
            SDManager &operator=(const SDManager&) = delete;

            void SetSaveFile(std::string path);
            void SetSaveFile(const char* path);

            void SaveData(double var);

            void SaveData(std::string var);
            void SaveData(const char* var);

            void SaveData(bool var);

            types LoadData(std::string data_type, std::string data_name);

        private:
            SDManager();
            int save_index;
            std::string file_path;
    };

    #define GET_VARIABLE_NAME(var) (#var)
}