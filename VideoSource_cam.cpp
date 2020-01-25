
#include "VideoSource_cam.h"

#include "Persistence/instances.h"
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

// For the time being, I am implementing webcam live capture.... All being well, more will follow...


VideoSourceCam::VideoSourceCam(){

  std::cout << "  Initiating capture device (whatever it is)..." << std::endl;

  
  pcap = new VideoCapture(-1); // by device number
  
  
  if(!pcap->isOpened()) {
    cerr << "Cannot open default capture device. Exiting... " << endl;
    exit(-1);
  }

  std::cout << "  Now capturing...." << std::endl;
  // obtaining the capture size
  int width = (int)pcap->get(cv::CAP_PROP_FRAME_WIDTH);
  int height = (int)pcap->get(cv::CAP_PROP_FRAME_HEIGHT);
  mirSize = cv::Size2i(width, height);
  cout << " Screen size (width , height) : " << width << " , " <<height <<endl;
};

cv::Size VideoSourceCam::getSize()
{ 
  return mirSize;
};



void VideoSourceCam::GetAndFillFrameBWandRGB(cv::Mat1b &img_gray, cv::Mat3b &img_bgr)
{
  if ( !pcap->grab() ) {
    cout << " Could not even grab the first frame! exiting..." << endl;
    exit(-1);
  }
    
  cv::Mat capFrame;
  pcap->retrieve(capFrame);
  /*cv::namedWindow("framed");
  cv::imshow("framed", capFrame);
  cv::waitKey(-1);*/
  capFrame.copyTo(img_bgr);
  //imRGB = frame.clone(); // deep copy (in BGR!!!! We may need to do the conversion in the following line instead)
  //cv::cvtColor(frame, imRGB, CV_BGR2RGB); // We 'll see about this...
  img_gray.create(img_bgr.rows, img_bgr.cols);

  cv::cvtColor(img_bgr, img_gray, cv::COLOR_BGR2GRAY); // conversion from BGR (OpenCV default) to grayscale
  
}


