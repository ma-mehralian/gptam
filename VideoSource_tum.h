#ifndef VIDEO_SOURCE_TUM_H
#define VIDEO_SOURCE_TUM_H

#include "VideoSource.h"
#include <fstream>

class VideoSourceTUM : public VideoSource
{
 public:
  VideoSourceTUM(std::string rgbd_dataset_dir);
  
  void GetAndFillFrameBWandRGB(cv::Mat1b &img_gray, cv::Mat3b &img_bgr) override;
  
  cv::Size getSize() override;

private:
  std::ifstream rgb_file_;
  std::string rgbd_dataset_dir_;
};

#endif //VIDEO_SOURCE_TUM_H
