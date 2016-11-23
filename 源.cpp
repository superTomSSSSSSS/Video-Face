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

//�ο�����  ���ڷ�ɫ������ʶ������۶�λ

void main()
{
    Face model;
	Mat img;
	img = imread("D:\\fan1.jpg");
	model.ReadFile(img);
    imshow("facechange", model.out);
    waitKey(0);

    //�����㷨  ���ĸ��������� �û�����һ�� ����������λ�á�
    int save[1000] = { 0 };	
	Searchalogrith Search;

	//������ǵݹ�ʵ��
	Search.searchstack(model.out, save);
	Search.isface(save, go);
		for (int count = 0; count < go; count++){         //countdouble
			rectangle(img, Point(save[count * 4 + 0], save[count * 4 + 2]), Point(save[count * 4 + 1], save[count * 4 + 3]), Scalar(201, 102, 62), 3, 4, 0);
		}
    imshow("finallpic" ,img);
    waitKey(0);
}