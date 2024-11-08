//   _____ _____  ___ _____      _____ _____  _____      ______ _____ _____ _____ _____ _____ 
//  /  ___|  ___|/ _ \_   _|    |  _  /  __ \/  __ \     |  _  \  ___|_   _|  ___/  __ \_   _|
//  \ `--.| |__ / /_\ \| |______| | | | /  \/| /  \/_____| | | | |__   | | | |__ | /  \/ | |  
//   `--. \  __||  _  || |______| | | | |    | |  |______| | | |  __|  | | |  __|| |     | |  
//  /\__/ / |___| | | || |      \ \_/ / \__/\| \__/\     | |/ /| |___  | | | |___| \__/\ | |  
//  \____/\____/\_| |_/\_/       \___/ \____/ \____/     |___/ \____/  \_/ \____/ \____/ \_/ 

/**
 * @file    Log.h
 * @brief   header file for Log.cpp
 * @version     1.0   
 * @author  Tom Aston
 */

#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <iostream>
#include <ctime>

#include "Common.hpp"

class Log 
{
    public:
        /**
         * @brief create singleton instance
         * @return pointer to Log instance
         */
        static Log *create();

        /**
         * @brief log message in the terminal
         * @param p_message pointer to message string
         * @param p_class_name pointer to name of class log is being called from
         * @return
         * @todo take in inum value to determin ERROR, WARN, INFO type
         */
        static void log_info(const char* p_message, const char* p_class_name);
        
        /**
         * @brief destructor to be used if log files created
         * @return
         */
        ~Log();

    private:
        
        static Log *mp_instance; //singleton instance

        /**
         * @brief private constructor method called in create method
         * @return
         */
        Log(); //private constructor

        /**
         * @brief get the current timestamp
         * @param buf pointer to formatted datetime string
         * @return
         */
        static void get_timestamp_ms(char* buf);
};

#endif /* LOG_H_ */