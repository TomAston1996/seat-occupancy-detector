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

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

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
    cv::VideoCapture video(0); // <- web cam for test purposes
    cv::Mat image;

    std::string path_to_haarcascade = "../../../../resource/haarcascade_frontalface_default.xml";

    cv::CascadeClassifier face_cascade;
    face_cascade.load(path_to_haarcascade);


    bool run_loop = true;
    if (face_cascade.empty()) {
        Log::log_info("XML file not loaded", "Application");
        run_loop = false;
    }

    while (run_loop) {
        video.read(image);

        std::vector<cv::Rect> faces;
        face_cascade.detectMultiScale(image, faces, 1.3, 5);

        for (int i = 0; i < faces.size(); i++) {
            //drawing rectangle around faces found in the output window (color: red, thickness: 3)
            cv::rectangle(image, faces[i].tl(), faces[i].br(), cv::Scalar(50, 50, 255), 3);

            //display count of faces found in top left corner of output window - testing purposes
            cv::putText(image, std::to_string(faces.size()), cv::Point(10, 40), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 1);
        }

        cv::imshow("Frame", image);
        cv::waitKey(1);
    }
}

void Application::end()
{
    //TODO cleanup
    Log::log_info("Exit application", "Application");
};