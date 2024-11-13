//   _____ _____  ___ _____      _____ _____  _____      ______ _____ _____ _____ _____ _____ 
//  /  ___|  ___|/ _ \_   _|    |  _  /  __ \/  __ \     |  _  \  ___|_   _|  ___/  __ \_   _|
//  \ `--.| |__ / /_\ \| |______| | | | /  \/| /  \/_____| | | | |__   | | | |__ | /  \/ | |  
//   `--. \  __||  _  || |______| | | | |    | |  |______| | | |  __|  | | |  __|| |     | |  
//  /\__/ / |___| | | || |      \ \_/ / \__/\| \__/\     | |/ /| |___  | | | |___| \__/\ | |  
//  \____/\____/\_| |_/\_/       \___/ \____/ \____/     |___/ \____/  \_/ \____/ \____/ \_/ 

/**
 * @file    FaceDetect.hpp
 * @brief   face detection class header file
 * @version	    1.0
 * @author  Tom Aston
 */
#ifndef FACE_DETECT_H_
#define FACE_DETECT_H_

#include <opencv2/opencv.hpp>

class FaceDetect
{
    public:
        /**
         * @brief constructor method for setting and loading haar cascade frontal face default xml
         * @return
         */
        FaceDetect();


        /**
         * @brief return status of haar cascade load
         * @return true if setup was successful, false if not
         */
        bool get_setup_status();

        /**
         * @brief gets the number of faces detected in the image frame from a video
         * @param current_frame the current video stream frame
         * @param video VideoCapture object passed by reference
         * @return number of faces detetcted in the image frame
         */
        int get_number_of_faces_detected(cv::Mat& current_frame, cv::VideoCapture& video);

        /**
         * @brief calculate the number of faces retect in an image frame
         * @param image image frame
         * @return number faces detected
         */
        int detect_faces_in_image(cv::Mat& image);


         /**
         * @brief processes the image for better face detection by adding gaussian blur, grescale and normalising the image to fix issues with brightness
         * @param image image frame
         * @return 
         */
        void preprocess_image(cv::Mat& image);

    protected:

        std::string path_to_haarcascade_frontal_xml; //frontal profile
        std::string path_to_haarcascade_profile_xml; //side profile
        
        cv::CascadeClassifier face_cascade_frontal; 
        cv::CascadeClassifier face_cascade_profile; 
        
        bool is_setup;

        /**
         * @brief draws the outline rectangles to the current frame
         * @param current_frame the current video stream frame
         * @param faces vector of faces detected
         * @return
         */
        void draw_face_detect_outlines_to_image(cv::Mat& current_frame, std::vector<cv::Rect>& faces);
};

#endif //FACE_DETECT_H_