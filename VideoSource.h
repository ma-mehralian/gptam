#ifndef VIDEO_SOURCE_H
#define VIDEO_SOURCE_H

#include <opencv2/core.hpp>

class VideoSource
{
public:
    virtual void GetAndFillFrameBWandRGB(cv::Mat1b &img_gray, cv::Mat3b &img_bgr) = 0;

    virtual cv::Size getSize()=0;
};

#endif //VIDEO_SOURCE_H
