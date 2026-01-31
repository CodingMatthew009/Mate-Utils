
#include "Include/Clock.hpp"
#include "Include/MLogger.hpp"
#include "Include/General/Enums.hpp"
#include "Include/Math/Vector2.hpp"
#include "Include/SDataManager.hpp"
#include <any>
#include <chrono>
#include <thread>

using namespace utils;
using namespace mathf;
int main(void)
{
    utils::Clock::Instance(); // DO NOT REMOVE, initializes class using current time

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    LOG("Initialized logging...", utils::LFlags::INFO);
    
    double myDouble = 251.2;

    utils::SDManager::Instance().SetSaveFile("/home/cmate/Documents/MateUtilities/Save_File.odt");
    //utils::SDManager::Instance().SaveData(myDouble);

    auto loaded_data = utils::SDManager::Instance().LoadData("double", "var");
    auto converted_data = std::to_string(loaded_data._double);
    LOG(converted_data, LFlags::INFO);

}