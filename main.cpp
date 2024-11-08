//   _____ _____  ___ _____      _____ _____  _____      ______ _____ _____ _____ _____ _____ 
//  /  ___|  ___|/ _ \_   _|    |  _  /  __ \/  __ \     |  _  \  ___|_   _|  ___/  __ \_   _|
//  \ `--.| |__ / /_\ \| |______| | | | /  \/| /  \/_____| | | | |__   | | | |__ | /  \/ | |  
//   `--. \  __||  _  || |______| | | | |    | |  |______| | | |  __|  | | |  __|| |     | |  
//  /\__/ / |___| | | || |      \ \_/ / \__/\| \__/\     | |/ /| |___  | | | |___| \__/\ | |  
//  \____/\____/\_| |_/\_/       \___/ \____/ \____/     |___/ \____/  \_/ \____/ \____/ \_/ 

/**
 * @file    main.cpp
 * @brief   app entry point
 * @version     1.0   
 * @author  Tom Aston
 */

#include <iostream>
#include <app.hpp>
#include <chrono>
#include <thread>
#include <string> 

/**
 * @param	[in] 	argc	Count of arguments
 * @param 	[in]	argv	Array of arguments
 * @return	Exit code.
 */
int main(int argc, char **argv)
{
    Log::create(); //create singleton instance of Log
    Log::log_info("Initialising Seat Occupancy Detection...", "Main");
    Log::log_info("Entering app loop..", "Main");
    
    int i = 0;
    while (i++ < 10) {
        //TODO app logic goes here
        Log::log_info("Info...", "Loop");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}