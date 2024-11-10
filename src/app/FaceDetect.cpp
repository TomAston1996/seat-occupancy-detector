//   _____ _____  ___ _____      _____ _____  _____      ______ _____ _____ _____ _____ _____ 
//  /  ___|  ___|/ _ \_   _|    |  _  /  __ \/  __ \     |  _  \  ___|_   _|  ___/  __ \_   _|
//  \ `--.| |__ / /_\ \| |______| | | | /  \/| /  \/_____| | | | |__   | | | |__ | /  \/ | |  
//   `--. \  __||  _  || |______| | | | |    | |  |______| | | |  __|  | | |  __|| |     | |  
//  /\__/ / |___| | | || |      \ \_/ / \__/\| \__/\     | |/ /| |___  | | | |___| \__/\ | |  
//  \____/\____/\_| |_/\_/       \___/ \____/ \____/     |___/ \____/  \_/ \____/ \____/ \_/ 

/**
 * @file    FaceDetect.cpp
 * @brief   OpenCV face detection logic
 * @version	    1.0
 * @author  Tom Aston
 */

#include <assert.h>

#include "FaceDetect.hpp"
#include "Log.hpp"


FaceDetect::FaceDetect() 
{
    FaceDetect::path_to_haarcascade = "../../../../resource/haarcascade_frontalface_default.xml";
    FaceDetect::face_cascade.load(path_to_haarcascade);

    FaceDetect::is_setup = true;
    if (face_cascade.empty()) {
        Log::log_info("XML file not loaded", "Application");
        FaceDetect::is_setup = false;
    }
}

bool FaceDetect::get_setup_status() 
{
    return FaceDetect::is_setup;
}

void FaceDetect::draw_face_detect_outlines_to_image(cv::Mat& current_frame, std::vector<cv::Rect>& faces) 
{
    for (int i = 0; i < faces.size(); i++) {
        //drawing rectangle around faces found in the output window (color: red, thickness: 3)
        cv::rectangle(current_frame, faces[i].tl(), faces[i].br(), cv::Scalar(50, 50, 255), 3);

        //display count of faces found in top left corner of output window - testing purposes
        cv::putText(current_frame, std::to_string(faces.size()), cv::Point(10, 40), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 1);
    }
}

int FaceDetect::get_number_of_faces_detected(cv::Mat& current_frame, cv::VideoCapture& video) 
{
    assert(FaceDetect::is_setup);
    
    video.read(current_frame);

    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale(current_frame, faces, 1.3, 5);

    FaceDetect::draw_face_detect_outlines_to_image(current_frame, faces);

    return faces.size();
}
