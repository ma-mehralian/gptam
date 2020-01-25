#ifndef VIDEO_SOURCE_CAM_H
#define VIDEO_SOURCE_CAM_H

#include "VideoSource.h"
#include <opencv2/highgui.hpp>

class VideoSourceCam: public VideoSource
{
 public:
  VideoSourceCam();
  
  void GetAndFillFrameBWandRGB(cv::Mat1b &img_gray, cv::Mat3b &img_bgr) override;

  cv::Size getSize() override;
  
 private:
  cv::VideoCapture *pcap;
  cv::Size mirSize;
};

#endif //VIDEO_SOURCE_CAM_H
