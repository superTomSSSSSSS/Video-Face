#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<stdio.h>

using namespace cv;

class Face{
       public:
		   void ReadFile(Mat img);
		   Face();
		   ~Face();

		   Mat YCrBrone, YCrchannel, YCbchannel, operationpicture, out;
		   //申请三个动态内存数组
		   double **arrayone;
		   double **arraytwo;
		   double **arraythree;
};