// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
//
// System.h
//
// Defines the System class
//
// This stores the main functional classes of the system, like the
// mapmaker, map, tracker etc, and spawns the working threads.
//
#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <memory>
#include "VideoSource.h"
#include "GLWindow2.h"


#include "OpenCV.h"

class ATANCamera;
class Map;
class MapMaker;
class Tracker;
class ARDriver;
class MapViewer;

class System
{
public:
  System(std::shared_ptr<VideoSource> input_video_source);
  void Run();
  
private:
  std::shared_ptr<VideoSource> mVideoSource;
  GLWindow2 mGLWindow;
  cv::Mat3b mimFrameRGB;
  cv::Mat1b mimFrameBW;
  
  Map *mpMap; 
  MapMaker *mpMapMaker; 
  Tracker *mpTracker; 
  ATANCamera *mpCamera;
  ARDriver *mpARDriver;
  MapViewer *mpMapViewer;
  
  bool mbDone;

  static void GUICommandCallBack(void* ptr, std::string sCommand, std::string sParams);
};



#endif
