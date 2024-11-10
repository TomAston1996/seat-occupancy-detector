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
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

#include "Log.hpp"
#include "Application.hpp"
#include "FaceDetect.hpp"

void Application::start()
{
    Log::create(); //create singleton instance of Log
    Log::log_info("Initialising Seat Occupancy Detection...", "Application");
    Log::log_info("Entering app loop..", "Application");
}

void Application::loop()
{
    cv::VideoCapture video(0); // <- web cam for test purposes
    cv::Mat image;

    FaceDetect face_detect;

    bool run_loop = true;
    if (!face_detect.get_setup_status()) {
        run_loop = false;
        Log::log_info("Load config error...", "Application");
    }

    while (run_loop) {
        int number_of_faces = face_detect.get_number_of_faces_detected(image, video);
        cv::imshow("Frame", image);
        cv::waitKey(1);
    }
}

void Application::end()
{
    //TODO cleanup
    Log::log_info("Exit application", "Application");
};