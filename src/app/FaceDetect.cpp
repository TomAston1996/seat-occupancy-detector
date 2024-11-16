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
    FaceDetect::path_to_haarcascade_frontal_xml = "../../../resource/haarcascade_frontalface_default.xml";
    FaceDetect::path_to_haarcascade_profile_xml = "../../../resource/haarcascade_profileface.xml";
    
    FaceDetect::face_cascade_frontal.load(path_to_haarcascade_frontal_xml);
    FaceDetect::face_cascade_profile.load(path_to_haarcascade_profile_xml);
    

    FaceDetect::is_setup = true;
    if (face_cascade_frontal.empty() || face_cascade_profile.empty()) {
        Log::log_info("XML haar cascade profiles not loaded", "Application");
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

        //draw image label
        cv::rectangle(current_frame, cv::Point(faces[i].tl().x, faces[i].tl().y + 20), cv::Point(faces[i].br().x, faces[i].tl().y), cv::Scalar(50, 50, 255), cv::FILLED);
        cv::putText(current_frame, "Face Detected [no. " + std::to_string(i + 1) + "]", cv::Point(faces[i].tl().x, faces[i].tl().y + 15), cv::FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(0, 0, 0), 1);
    }
}

void FaceDetect::preprocess_image(cv::Mat& image) 
{
    //add gaussian blur to smoothe uneven pixel values in an image by cutting out the extreme outliers
    cv::GaussianBlur(image, image, cv::Size(7, 7), 5, 0);

    //add grayscale filter to elimiate color data
    // cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

    //normalise to fix issues with brightness
    cv::normalize(image, image, 0, 255, cv::NORM_MINMAX);
}

int FaceDetect::detect_faces_in_image(cv::Mat& image)
{
    assert(FaceDetect::is_setup);

    std::vector<cv::Rect> frontal_faces;
    std::vector<cv::Rect> profile_faces;
    
    //detect front profiles
    face_cascade_frontal.detectMultiScale(image, frontal_faces, 1.1, 5);
    FaceDetect::draw_face_detect_outlines_to_image(image, frontal_faces);
    
    //detect side profiles
    face_cascade_profile.detectMultiScale(image, profile_faces, 1.3, 5);
    FaceDetect::draw_face_detect_outlines_to_image(image, profile_faces);

    int number_faces_found = profile_faces.size() + frontal_faces.size();

    //display count of faces found in top left corner of output window - testing purposes
    cv::putText(image, std::to_string(number_faces_found), cv::Point(10, 40), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 1);

    return number_faces_found;
}


int FaceDetect::get_number_of_faces_detected(cv::Mat& current_frame, cv::VideoCapture& video) 
{
    assert(FaceDetect::is_setup);
    
    video.read(current_frame);

    //image pre-proccessing
    FaceDetect::preprocess_image(current_frame);

    return detect_faces_in_image(current_frame);
}
