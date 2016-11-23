#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include"facechange.h"
using namespace cv;
using namespace std;

Face::Face(){
	arrayone = nullptr;
    arraytwo = nullptr;
	arraythree = nullptr;
	arrayone = (double**)malloc(sizeof(double *)* 800);    //图片超过800要修改
	for (int k = 0; k<800; k++)
		arrayone[k] = (double *)malloc(sizeof(double)* 800);

	arraytwo = (double**)malloc(sizeof(double *)* 800);
	for (int k = 0; k<800; k++)
		arraytwo[k] = (double *)malloc(sizeof(double)* 800);

	arraythree = (double**)malloc(sizeof(double *)* 800);
	for (int k = 0; k<800; k++)
		arraythree[k] = (double *)malloc(sizeof(double)* 800);
}

Face::~Face(){
	free(arrayone);
	arrayone = NULL;
	free(arraytwo);
	arraytwo = NULL;
	free(arraythree);
	arraythree = NULL;
}

void Face::ReadFile(Mat img){
		int a = img.rows;
		int b = img.cols;
		operationpicture.create(a, b, CV_8UC(1));
		vector<Mat>channels;
		cvtColor(img, YCrBrone, CV_RGB2YCrCb);
		split(YCrBrone, channels);
		YCrchannel = channels.at(1);
		YCbchannel = channels.at(2);
		int i, j;
		double x1, x2, t;

		for (i = 0; i < img.rows; i++)
		{
			uchar * data = YCrchannel.ptr<uchar>(i);
			for (j = 0; j < img.cols; j++)
			{
				arrayone[i][j] = data[j];
			}
		}

		for (i = 0; i < img.rows; i++)
		{
			uchar * data = YCbchannel.ptr<uchar>(i);
			for (j = 0; j < img.cols; j++)
			{
				arraytwo[i][j] = data[j];
			}
		}

		//肤色相似度的计算
		for (i = 0; i < img.rows; i++)
		{
			for (j = 0; j < img.cols; j++)
			{
				x1 = arraytwo[i][j] - 156.5599;
				x2 = arrayone[i][j] - 117.4361;
				t = x1*(x1*299.4574 - x2*12.1430) + x2*(-x1*12.1430 + x2*160.1301);
				t /= (160.1301*299.4574 - 12.1430*12.1430);
				t /= (-2);
				arraythree[i][j] = exp(t);
			}
		}

		double max = 0.0;

		for (i = 0; i < img.rows; i++)
		{
			for (j = 0; j < img.cols; j++)
			{
				if (arraythree[i][j]>max)
					max = arraythree[i][j];
			}
		}
		for (i = 0; i < img.rows; i++)
		{
			for (j = 0; j < img.cols; j++)
			{
				arraythree[i][j] = (arraythree[i][j] / max) * 255;
			}
		}

		///////////////////////////////////////////////////////////////////////////

		for (i = 0; i < operationpicture.rows; i++)
		{
			uchar * data = operationpicture.ptr<uchar>(i);
			for (j = 0; j < operationpicture.cols; j++)
			{

				data[j] = arraythree[i][j];
			}
		}
		int count = 0;
		//medianBlur(operationpicture, out, 3);     //中值滤波
		GaussianBlur(operationpicture, out, Size(3, 3), 0, 0);
		for (i = 0; i < out.rows; i++)
		{
			uchar * data = out.ptr<uchar>(i);
			for (j = 0; j < out.cols; j++)
			{

				if (data[j] >= 140.25)        //阈值分割的参数  140.25   这个随着图片的修改要改
					data[j] = 255;                                 //255是白色
				else
					data[j] = 0;
			}
		}
}
