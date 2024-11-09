//   _____ _____  ___ _____      _____ _____  _____      ______ _____ _____ _____ _____ _____ 
//  /  ___|  ___|/ _ \_   _|    |  _  /  __ \/  __ \     |  _  \  ___|_   _|  ___/  __ \_   _|
//  \ `--.| |__ / /_\ \| |______| | | | /  \/| /  \/_____| | | | |__   | | | |__ | /  \/ | |  
//   `--. \  __||  _  || |______| | | | |    | |  |______| | | |  __|  | | |  __|| |     | |  
//  /\__/ / |___| | | || |      \ \_/ / \__/\| \__/\     | |/ /| |___  | | | |___| \__/\ | |  
//  \____/\____/\_| |_/\_/       \___/ \____/ \____/     |___/ \____/  \_/ \____/ \____/ \_/ 

/**
 * @file    Log.cpp
 * @brief   logger singleton class
 * @version     1.0   
 * @author  Tom Aston
 */
#include <assert.h>
#include <string>
#include <ctime>
#include <chrono>
#include <iostream>
#include <format>
#include <stdio.h>
#include <time.h>
#include <cstring>

#include "Log.hpp"

Log *Log::mp_instance = NULL;

Log::Log(){};

Log::~Log(){};

Log *Log::create() 
{
    assert(mp_instance == NULL);

    mp_instance = new Log();

    if (mp_instance == NULL) {
        printf("Failed to create instance...\n");
        exit(100);
    }

    return mp_instance;
}

void Log::get_timestamp_ms(char* buf)
{
    time_t now = time(0);
    struct tm tstruct;

    localtime_s(&tstruct, &now);

    strftime(buf, 80, "%Y-%m-%d.%X", &tstruct);
}

void Log::log_info(const char* p_message, const char* p_class_name)
{
    assert(mp_instance != NULL);

    char buf[80];
    get_timestamp_ms(buf);

    printf("[%s][INFO] %s: %s\n", buf, p_class_name, p_message);

    fflush(stdout);
}
