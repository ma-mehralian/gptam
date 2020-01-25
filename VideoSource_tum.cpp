#include "VideoSource_tum.h"
#include <iostream>
#include <fstream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


VideoSourceTUM::VideoSourceTUM(std::string rgbd_dataset_dir){
    rgbd_dataset_dir_ = rgbd_dataset_dir;
    rgb_file_.open(rgbd_dataset_dir + "/rgb.txt");
    if (!rgb_file_.is_open())
        throw std::invalid_argument(rgbd_dataset_dir + "/rgb.txt not found!");
}

cv::Size VideoSourceTUM::getSize(){
    return Size(640, 480);
}

void VideoSourceTUM::GetAndFillFrameBWandRGB(cv::Mat1b &img_gray, cv::Mat3b &img_bgr){
    std::string line;
    while (std::getline(rgb_file_, line)){
        if (line[0] == '#')
            continue;
        std::istringstream iss(line);
        double ts;
        string img_name;
        if (!(iss >> ts >> img_name)) { continue; }
        img_bgr = imread(rgbd_dataset_dir_ + "/" + img_name);
        if (img_bgr.size() == Size())
            throw invalid_argument("Cannot read " + rgbd_dataset_dir_ + "/" + img_name);
        cvtColor(img_bgr, img_gray, CV_BGR2GRAY);
        break;
    }
}


