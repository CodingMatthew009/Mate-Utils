#include "../Include/SDataManager.hpp"
#include "../Include/MLogger.hpp"
#include "../Include/General/Enums.hpp"
#include <any>
#include <string>

namespace utils
{
    SDManager& SDManager::Instance() 
    {
        static SDManager instance;
        return instance;
    }

    void SDManager::SetSaveFile(std::string path)
    {
        file_path = path;
    }

    void SDManager::SetSaveFile(const char* path)
    {
        file_path = path;
    }

    void SDManager::SaveData(double var)
    {
        std::ofstream data_stream;
        data_stream.open(file_path, std::ios::out);

        if (!data_stream)
        {
            LOG("Failed to open SaveFile", LFlags::ERROR);
        } 
        else 
        {
            data_stream << GET_VARIABLE_NAME(var);
            data_stream << " ";
            data_stream << "double";
            data_stream << " ";
            data_stream << var;

            save_index++;
            data_stream.close();
        }
    }

    SDManager::types SDManager::LoadData(std::string data_type, std::string data_name)
    {
        std::ifstream infile(file_path);
        if (!infile)
        {
            LOG("Failed to open SaveFile", LFlags::ERROR);
        } 
    
        std::string line;
        while(std::getline(infile, line))
        {
            std::istringstream iss(line);
            std::string name;
            iss >> name;

            if(name== data_name)
            {
                std::string type;
                std::string value;

                iss >> type >> value;

                auto uType = types();
                if (data_type == "double")
                {
                    uType._double = std::stod(value);
                }
                if (data_type == "int")
                {
                    uType._double = std::stoi(value);
                }
                if (data_type == "float")
                {
                    uType._double = std::stof(value);
                }
                if (data_type == "bool")
                {
                    uType._double = std::stoi(value);
                }
                return uType;
            }
        }
    }

    SDManager::SDManager() {};
}