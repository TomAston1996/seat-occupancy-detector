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
#include <chrono>
#include <thread>
#include <string> 

#include <AppHeaders.hpp>

/**
 * @param	[in] 	argc	Count of arguments
 * @param 	[in]	argv	Array of arguments
 * @return	Exit code.
 */
int main(int argc, char **argv)
{
    //app initialisation
    Application::start();

    //app main loop
    Application::loop();

    //app cleanup
    Application::end();

    return 0;
}