#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include"facechange.h"
#include"searchalogrithm.h"

using namespace cv;
using namespace std;

extern int go;
//extern int counterx;
//extern int countery;

//参考的是  基于肤色的人脸识别和人眼定位

void main()
{
    Face model;
	Mat img;
	img = imread("D:\\fan1.jpg");
	model.ReadFile(img);
    imshow("facechange", model.out);
    waitKey(0);

    //处理算法  将四个极致坐标 用画矩形一样 画出人脸的位置。
    int save[1000] = { 0 };	
	Searchalogrith Search;

	//四邻域非递归实现
	Search.searchstack(model.out, save);
	Search.isface(save, go);
		for (int count = 0; count < go; count++){         //countdouble
			rectangle(img, Point(save[count * 4 + 0], save[count * 4 + 2]), Point(save[count * 4 + 1], save[count * 4 + 3]), Scalar(201, 102, 62), 3, 4, 0);
		}
    imshow("finallpic" ,img);
    waitKey(0);
}