//   _____ _____  ___ _____      _____ _____  _____      ______ _____ _____ _____ _____ _____ 
//  /  ___|  ___|/ _ \_   _|    |  _  /  __ \/  __ \     |  _  \  ___|_   _|  ___/  __ \_   _|
//  \ `--.| |__ / /_\ \| |______| | | | /  \/| /  \/_____| | | | |__   | | | |__ | /  \/ | |  
//   `--. \  __||  _  || |______| | | | |    | |  |______| | | |  __|  | | |  __|| |     | |  
//  /\__/ / |___| | | || |      \ \_/ / \__/\| \__/\     | |/ /| |___  | | | |___| \__/\ | |  
//  \____/\____/\_| |_/\_/       \___/ \____/ \____/     |___/ \____/  \_/ \____/ \____/ \_/ 

/**
 * @file    Application.cpp
 * @brief   application logic controller
 * @version	    1.0
 * @author  Tom Aston
 */
#include <chrono>
#include <thread>

#include "Log.hpp"
#include "Application.hpp"

void Application::start()
{
    Log::create(); //create singleton instance of Log
    Log::log_info("Initialising Seat Occupancy Detection...", "Application");
    Log::log_info("Entering app loop..", "Application");
}

void Application::loop()
{
    //TODO main application logic goes here
    int i = 0;
    while (i++ < 10) {
        //TODO app logic goes here
        Log::log_info("Info...", "Application");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void Application::end()
{
    //TODO cleanup
    Log::log_info("Exit application", "Application");
};