#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<stdio.h>

using namespace cv;
#define nHeight 480                                   //这个写图片的实际尺寸
#define nWidth 500

class  Searchalogrith {
	public:
		void searchstack(Mat src, int *save);
		void isface(int *save, int next);
		void searchblack(int x1, int x2, int y1, int y2, int x, int y);
		void fourneighbourhood(int x, int y);

		int xStart, xEnd, yStart, yEnd;
		int xmin[1000], xmax[1000], ymin[1000], ymax[1000];
		int xminblack[1000], xmaxblack[1000], yminblack[1000], ymaxblack[1000];
		int countdouble;
		int countblack;

		Searchalogrith();
		virtual ~Searchalogrith();
};