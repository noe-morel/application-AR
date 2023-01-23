//
//  ArUco-OpenGL.h
//
//  Created by Jean-Marie Normand on 04/01/21.
//  Copyright (c) 2021 Centrale Nantes. All rights reserved.
//

#ifndef UserPerspectiveAR_ArUco_OpenGL_h
#define UserPerspectiveAR_ArUco_OpenGL_h

#include <Windows.h>

#ifdef __APPLE__
#include <OPENGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <iostream>

#include <fstream>
#include <sstream>

#include "C:/Dev/aruco3.1/include/aruco/aruco.h"
#include "ObjLoader.h"


using namespace cv;
using namespace aruco;
using namespace std;

class ArUco {
// Attributes
protected:
   // Intrinsics file for the camera
   string            m_IntrinsicFile;
   
   // Size of the marker (in meters)
   float             m_MarkerSize;
   
   // The Marker Detector
   MarkerDetector    m_PPDetector;
   
   // Vector of detected markers in the image
   vector<Marker>    m_Markers;
   
   // OpenCV matrices storing the images
   // Input Image
   Mat               m_InputImage;
   
   // Undistorted image
   Mat               m_UndInputImage;
   
   // Resized image
   Mat               m_ResizedImage;

   // Camera parameters
   CameraParameters  m_CameraParams;
   
   // Size of the OpenGL window size
   Size              m_GlWindowSize;
   
// Methods
public:
   // Constructor
   ArUco(string intrinFileName, float markerSize);
   // Destructor
   ~ArUco();
   
   void	drawBox(GLfloat size, GLenum type);

   // Detect marker and draw things
   void  doWork(Mat inputImg);
   
   // Draw axis function
   void  drawAxis(float axisSize);
   
   // Draw axis function
   void  drawWireCube(GLdouble size);


   // GLUT functionnalities
   
   // Drawing function
   void  drawScene();

   // Idle function
   void  idle(Mat newImage);
   
   // Resize function
   void  resize(GLsizei iWidth, GLsizei iHeight);
   void  resizeCameraParams(cv::Size newSize);
   
   // Test using ArUco to display a 3D cube in OpenCV
   void  draw3DCube(cv::Mat img, int markerInd=0);
   void  draw3DAxis(cv::Mat img, int markerInd=0);

   // OBJ
   Model_OBJ cle;
   Model_OBJ coffre;
   Model_OBJ coffre_open;
   Model_OBJ ile;
   Model_OBJ mer;
   Point2f center;
   float radius;
   bool cle_affiche=false;

   bool is_open(Point2f, float);

   void drawObject(Marker);
};


#endif
