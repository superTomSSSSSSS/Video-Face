#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<stdio.h>
#include<stack>
#include"searchalogrithm.h"

using namespace cv;
using namespace std;

//��������
int go = 0;
int pbFlag[nHeight][nWidth];
int pbFlagdouble[nHeight][nWidth];
stack<int>mystack;

/////////////////////////////////////////��ֱˮƽ�㷨/////////////////////////////////////////////////////////
//int counterx = 0;
//int countery = 0;
//int xpro1[nWidth];
//int ypro1[nHeight];
//int xkeypriont[nWidth];
//int ykeypriont[nHeight];
//int xkeypriontone[nWidth];
//int ykeypriontone[nHeight];

//typedef struct _XYPOSITION{                             //typedef�Ƕ���һ�����ͣ�struct�ǽṹ��
//    int xPos;
//    int yPos;
//}XYPOSITION, *PXYPOSITION ;           //XYPOSITION,*PXYPOSITION�ǽṹ������ �൱��struct _XYPOSITION
//
//XYPOSITION *pPosBottom, *pPosTop;

//XYPOSITION *pXYPos = (XYPOSITION *)malloc(240000 * sizeof(XYPOSITION));   //������
//XYPOSITION *EyePosition = (XYPOSITION *)malloc(240 * sizeof(XYPOSITION));

//void xpro(Mat src);
//void ypro(Mat src);

//�ð�����ˮƽ��ֱͶӰ������ȡ
//void search(Mat src, int *save){         //Mat src,
//
//
//    int i, j;
//    int countx = 0;
//    int county = 0;
//    //����С��400�ľ���Ϊ������
//    int judge = 0;
//    int judge_a = 0;
//
//
//    for (i = 0; i < nHeight; i++)
//    {
//        uchar * data = src.ptr<uchar>(i);
//        for (j = 0; j < nWidth; j++)
//        {
//            if (data[j] == 255)
//            {
//                pbFlag[i][j] = 1;                          //��ɫpbFlag����true
//                pbFlagdouble[i][j] = 0;
//            }
//            else
//            {
//                pbFlag[i][j] = 0;
//                pbFlagdouble[i][j] = 1;
//            }
//        }
//    }
//
////ˮƽ��ֱͶӰ�㷨
//    ypro(src);
//
//    xpro(src);
//  
//    for (county = 0; county < countery;county++){
//        for (countx = 0; countx < counterx;countx++){
//
//            xmin[county * counterx + countx] = 1000;               //������ֵҪ��ͼƬ��С�仯 ����   Ҫ��ͼ�����صĸ��Ӵ�
//            xmax[county * counterx + countx] = 0;
//            ymin[county * counterx + countx] = 1000;
//            ymax[county * counterx + countx] = 0;
//
//            for (int i = ykeypriontone[county]; i < ykeypriont[county]; i++)
//            {
//                for (int j = xkeypriontone[countx]; j < xkeypriont[countx]; j++)
//
//                {
//                    if (pbFlag[i][j])
//                    {
//                        xStart = j;
//                        xEnd = j;
//                        yStart = i;
//                        yEnd = i;
//
//                        pPosBottom = pXYPos;               
//                        pPosTop = pXYPos + 1;
//
//                        //��¼��ɫ�������
//                        (*pPosBottom).xPos = j;            //(*pPosBottom)������ĵ�һ�����ݵ�X����
//                        (*pPosBottom).yPos = i;
//
//                        pbFlag[i][j] = false;
//
//                        while (pPosBottom != pPosTop)     //�����и�pPosBottom���Լ�
//                        {
//                            //��ȡ�������б��е����ص�
//                            int X = (*pPosBottom).xPos;
//                            int Y = (*pPosBottom++).yPos;      //(*pPosBottom++).yPos==(*pPosBottom).yPos   ��pPosBottom�����Լ� ���ǣ�*pPosBottom�����ֵ����ġ�pPosBottomֵ���
//                            //�����������
//                            //�����һ�е����
//
//                            if (Y > 0)
//                            {
//                                int Y1 = Y - 1;
//
//                                //�������Ͻǵĵ�
//                                if (X > 0)
//                                {
//                                    if (pbFlag[Y1][X - 1])
//                                    {
//                                        int X1 = X - 1;
//                                        (*pPosTop).xPos = X1;
//                                        (*pPosTop).yPos = Y1;
//
//                                        //��¼����Ĵ�С
//                                        xStart = min(xStart, X1);
//                                        yStart = min(yStart, Y1);
//
//                                        pbFlag[Y1][X1] = false;
//                                    }
//                                }
//                                //���������ϵĵ�
//                                if (pbFlag[Y1][X])
//                                {
//                                    (*pPosTop).xPos = X;
//                                    (*pPosTop).yPos = Y1;
//                                    yStart = min(yStart, Y1);
//                                    pbFlag[Y1][X] = false;
//                                }
//                                //�������Ͻǵĵ�
//                                int X1 = X + 1;
//                                if (X1 < nWidth)
//                                {
//                                    if (pbFlag[Y1][X1])
//                                    {
//                                        (*pPosTop).xPos = X1;
//                                        (*pPosTop).yPos = Y1;
//                                        //��¼����Ĵ�С
//                                        xEnd = max(xEnd, X1);
//                                        yStart = min(yStart, Y1);
//                                        //��ʶΪ�Ѿ��Ѳ��
//                                        pbFlag[Y1][X1] = false;
//                                    }
//                                }
//                            }
//
//                            //����ڶ��е����
//
//                            //��������ߵĵ�
//                            if (X > 0)
//                            {
//                                if (pbFlag[Y][X - 1])
//                                {
//                                    int X1 = X - 1;
//                                    (*pPosTop).xPos = X1;
//                                    (*pPosTop).yPos = Y;
//                                    //��¼����Ĵ�С
//                                    xStart = min(xStart, X1);
//                                    pbFlag[Y][X1] = false;
//                                }
//                            }
//                            //�������ұߵĵ�
//                            int X1 = X + 1;
//                            if (X1 < nWidth)
//                            {
//                                if (pbFlag[Y][X1])
//                                {
//                                    (*pPosTop).xPos = X1;
//                                    (*pPosTop).yPos = Y;
//                                    //��¼����Ĵ�С
//                                    xEnd = max(xEnd, X1);
//                                    pbFlag[Y][X1] = false;
//                                }
//                            }
//                            //��������е����
//
//                            if ((Y + 1) < nHeight)
//                            {
//                                int Y1 = Y + 1;
//                                if (X > 0)
//                                {
//                                    if (pbFlag[Y1][X - 1])
//                                    {
//                                        X1 = X - 1;
//                                        (*pPosTop).xPos = X1;
//                                        (*pPosTop).yPos = Y1;
//                                        // ��¼����Ĵ�С 
//                                        xStart = min(xStart, X1);
//                                        yEnd = max(yEnd, Y1);
//                                        // ��ʶΪ�Ѿ������� 
//                                        pbFlag[Y1][X1] = false;
//                                    }
//                                }
//                                //  �������±ߵĵ� 
//                                if (pbFlag[Y1][X])
//                                {
//                                    (*pPosTop).xPos = X;
//                                    (*pPosTop).yPos = Y1;
//                                    // ��¼����Ĵ�С 
//                                    yEnd = max(yEnd, Y1);
//                                    // ��ʶΪ�Ѿ������� 
//                                    pbFlag[Y1][X] = false;
//                                }
//                                //  �������½ǵĵ� 
//                                X1 = (X + 1);
//                                if (X1 < nWidth)
//                                {
//                                    if (pbFlag[Y1][X + 1])
//                                    {
//                                        (*pPosTop).xPos = X1;
//                                        (*pPosTop).yPos = Y1;
//                                        // ��¼����Ĵ�С 
//                                        xEnd = max(xEnd, X1);
//                                        yEnd = max(yEnd, Y1);
//                                        // ��ʶΪ�Ѿ������� 
//                                        pbFlag[Y1][X1] = false;
//                                    }
//                                }
//                            }
//                        }
//
//                        //������������������
//
//                        if (xStart != 0 && xEnd != (nWidth - 1) && yStart != 0 && yEnd != (nHeight - 1))
//                        {
//                            pPosBottom = pXYPos;
//                            while (pPosBottom != pPosTop)
//                            {
//                                //���ͼ�����а�ɫ�������
//                                int  X = (*pPosBottom).xPos;
//                                xmin[county * counterx + countx] = min(X, xmin[county * counterx + countx]);                 //xmin=500,xmax=0,ymin=480,ymax=0;
//                                xmax[county * counterx + countx] = max(X, xmax[county * counterx + countx]);
//                                int  Y = (*pPosBottom++).yPos;
//                                ymin[county * counterx + countx] = min(Y, ymin[county * counterx + countx]);
//                                ymax[county * counterx + countx] = max(Y, ymax[county * counterx + countx]);
//                               // judge++;
//                            }
//                        }
//                    }
//                }
//            } 
//            //����1.�����Ҫ����1 ����ҲҪС��2
//            if (((ymax[county * counterx + countx] - ymin[county * counterx + countx]) <= (xmax[county * counterx + countx] - xmin[county * counterx + countx])) || ((ymax[county * counterx + countx] - ymin[county * counterx + countx]) >= (2 * (xmax[county * counterx + countx] - xmin[county * counterx + countx]))))
//            {
//                judge_a = 1;
//            }
//            //����2.judge<400Ϊ��������һ���ж���׼
//            if ((xmin[county * counterx + countx] == 1000 && xmax[county * counterx + countx] == 0 && ymin[county * counterx + countx] == 1000 && ymax[county * counterx + countx] == 0) || judge_a == 1 )
//            {
//                xmin[county * counterx + countx] = 0;
//                xmax[county * counterx + countx] = 0;
//                ymin[county * counterx + countx] = 0;
//                ymax[county * counterx + countx] = 0;
//                judge_a = 0;
//            }
//        }
//    }
//        for (int a = 0; a < county*countx; a++){
//
//            //ѡ������С��400ʱ   �Զ�ʡȥ
//            if ((xmax[a] - xmin[a])*(ymax[a] - ymin[a]) < (nWidth*nHeight/600))
//            {
//                 xmin[a]=0;
//                 xmax[a]=0;
//                 ymin[a]=0;
//                 ymax[a]=0;
//            }
//            //ͼƬ����
//            if ((ymax[a] - ymin[a]) > 1.2*(xmax[a] - xmin[a]))
//            {
//                ymax[a] = ymin[a] + 1.2*(xmax[a] - xmin[a]);
//            }
//            save[a * 4 + 0] = xmin[a];
//            save[a * 4 + 1] = xmax[a];
//            save[a * 4 + 2] = ymin[a];
//            save[a * 4 + 3] = ymax[a];
//    }
//}

//��ֱͶӰ�㷨
//void xpro(Mat src)
//{
//    int i, j, count = 0, countone = 0;
//
//    xpro1[nWidth] = { 0 };
//
//    for ( i = 0; i < nWidth; i++)
//    {
//
//        for ( j = 0; j < nHeight; j++)
//        {
//            if (pbFlag[j][i] == 1)
//                xpro1[i]++;
//
//        }
//
//        //�ж������ų�һЩ��ϸ�����ĸ���
//        if (xpro1[i] < 30)
//        {
//            xpro1[i] = 0;
//        }
//
//        if ((xpro1[i] == 0 && xpro1[i - 1] != 0 && i >0) || (i == (nWidth-1) && xpro1[i] != 0))               //�Ȱ׺��
//        {
//            xkeypriont[count] = i;
//            count++;
//        }
//        if ((xpro1[i] != 0 && xpro1[i - 1] == 0 && i >0) ||((i == 0 && xpro1[i]!=0)))
//        {
//            xkeypriontone[count] = i;
//            countone++;
//        }
//    }
//    counterx = max(count, countone);
//}

//ˮƽͶӰ�㷨
//void ypro(Mat src)
//{
//    int i, j, count = 0, countone = 0;
//
//    ypro1[nHeight] = { 0 };
//
//   for ( i = 0; i < nHeight; i++)
//    {
//
//        for ( j = 0; j < nWidth; j++)
//        {
//            if (pbFlag[i][j] == 1)
//                ypro1[i]++;
//
//        }
//
//        //�ж�����
//
//        if (ypro1[i] <= 30)
//        {
//            ypro1[i] = 0;
//        }
//        /////////////////////
//
//        if ((ypro1[i] == 0 && ypro1[i - 1] != 0 && i >0)||(i == (nHeight - 1) && ypro1[i] != 0))
//        {
//            ykeypriont[count] = i;
//            count++;
//        }
//        if ((ypro1[i] != 0 && ypro1[i - 1] == 0 && i > 0) || (i == 0 && ypro1[i] != 0))
//        {
//            ykeypriontone[count] = i;
//            countone++;
//        }
//    }
//   countery = max(count,countone);
//}

//�����������
//void fourneighbourhood(int x, int y)       //y��H  x��W
//{
//    //��ȡ�������б��е����ص�
//    //int X = x;
//    //int Y = y;
//    //�����������
//
//    if (pbFlagdouble[y][x] == 0)
//    {
//        //��ʶ���Ѿ�����������
//        pbFlagdouble[y][x] = 1;
//
//        //��������ߵĵ�
//
//        if (((x > 0) && pbFlagdouble[y][x - 1] == 0) && recursionlimit<800)
//        {
//            //��¼����Ĵ�С
//            xStart = min(xStart, (x - 1));
//            yStart = min(yStart, y);
//            recursionlimit++;
//            fourneighbourhood(x - 1, y);
//        }
//
//		//��ջ����ʾ
//
//        //�������ұߵĵ�
//
//        if ((x < (nWidth - 1)) && pbFlagdouble[y][x + 1] == 0 && recursionlimit<800)
//        {
//            //��¼����Ĵ�С
//            xEnd = max(xEnd, (x + 1));
//            yStart = min(yStart, y);
//            recursionlimit++;
//            fourneighbourhood(x + 1, y);
//        }
//
//        //���������ϵĵ�
//
//        if (y > 0 && pbFlagdouble[y - 1][x] == 0 && recursionlimit<800)
//        {
//            //��¼����Ĵ�С
//            yStart = min(yStart, (y - 1));
//            recursionlimit++;
//            fourneighbourhood(x, (y - 1));
//        }
//
//        // �������±ߵĵ� 
//
//        if ((y < (nHeight - 1)) && pbFlagdouble[y + 1][x] == 0 && recursionlimit<800)
//        {
//            // ��¼����Ĵ�С 
//            yEnd = max(yEnd, (y + 1));
//            recursionlimit++;
//            fourneighbourhood(x, y + 1);
//        }
//    }
//    else{
//        pbFlagdouble[y][x] = 2;
//    }
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//��ʼ�� Searchalogrith

Searchalogrith::Searchalogrith()
{
	xStart = 1000;
	xEnd = 0;
	yStart = 1000;
	yEnd = 0;
	xmin[1000] = { 0 };
	xmax[1000] = { 0 };
	ymin[1000] = { 0 };
	ymax[1000] = { 0 };
	xminblack[1000] = { 0 };
	xmaxblack[1000] = { 0 };
	yminblack[1000] = { 0 };
	ymaxblack[1000] = { 0 };
	countdouble = 0;
	countblack = 0;
}

Searchalogrith::~Searchalogrith(){

}

//������ݹ��ѵ㷨 ��ջ����ʾ 
void Searchalogrith::searchstack(Mat src, int *save)
{
	for (int i = 0; i < nHeight; i++)
	{
		uchar * data = src.ptr<uchar>(i);
		for (int j = 0; j < nWidth; j++)
		{
			if (data[j] == 255)
			{
				pbFlag[i][j] = 1;                          //��ɫpbFlag����true
				pbFlagdouble[i][j] = 0;
			}
			else
			{
				pbFlag[i][j] = 0;
				pbFlagdouble[i][j] = 1;
			}
		}
	}
	for (int a = 0; a < nHeight; a++){
		for (int b = 0; b < nWidth; b++){

			xStart = 1000;               //������ֵҪ��ͼƬ��С�仯 ����   Ҫ��ͼ�����صĸ��Ӵ�
			xEnd = 0;
			yStart = 1000;
			yEnd = 0;
			if (pbFlag[a][b] == 1)
			{
				fourneighbourhood(b, a);

				//��������������ж���Щ������ ��Χ��û����ͨ�׵�������
				if (xStart == 1000 && xEnd == 0 && yStart == 1000 && yEnd == 0)
				{
					xStart = 0;              
					xEnd = 0;
					yStart = 0;
					yEnd = 0;
				}
				/////////////////////////////////////////////////////////////

				xmin[countdouble] = xStart;
				xmax[countdouble] = xEnd;
				ymin[countdouble] = yStart;
				ymax[countdouble] = yEnd;
				countdouble++;
			}
		}
	}

	for (int a = 0; a < countdouble; a++){

		//ѡ������С��400ʱ   �Զ�ʡȥ  �����Ҫ����1 ����ҲҪС��2
		if (((xmax[a] - xmin[a])*(ymax[a] - ymin[a]) < (nWidth*nHeight / 600)))      // || ((ymax[a] - ymin[a])<(xmax[a] - xmin[a])) || ((ymax[a] - ymin[a])>2 * (xmax[a] - xmin[a]))
		{
			xmin[a] = 20000;
			xmax[a] = 20000;
			ymin[a] = 20000;
			ymax[a] = 20000;
		}
		if ((xmin[a] != 20000) && (xmax[a] != 20000) && (ymin[a] != 20000) && (ymax[a] != 20000)){
			save[go * 4 + 0] = xmin[a];
			save[go * 4 + 1] = xmax[a];
			save[go * 4 + 2] = ymin[a];
			save[go * 4 + 3] = ymax[a];
			go++;
		}
	}
}

void Searchalogrith::isface(int *save, int next)
{
	for (int a = 0; a < next; a++)
	{
		countblack = 0;
		for (int i = save[a * 4 + 2]; i < save[a * 4 + 3]; i++)
		{
			for (int j = save[a * 4 + 0]; j < save[a * 4 + 1]; j++)
			{
				xStart = 1000;
				xEnd = 0;
				yStart = 1000;
				yEnd = 0;
				if (pbFlagdouble[i][j] == 1)
				{
					searchblack(save[a * 4 + 0], save[a * 4 + 1], save[a * 4 + 2], save[a * 4 + 3], j, i);
					if (xStart == 1000 || xEnd == 0 || yStart == 1000 || yEnd == 0)
					{
						xStart = 0;
						xEnd = 0;
						yStart = 0;
						yEnd = 0;
					}
					xminblack[countblack] = xStart;
					xmaxblack[countblack] = xEnd;
					yminblack[countblack] = yStart;
					ymaxblack[countblack] = yEnd;

					if (((xEnd - xStart)*(yEnd - yStart) <= 80) && ((xEnd - xStart)*(yEnd - yStart) >= 2) && (xEnd - xStart) > 0)     //((xEnd - xStart)*(yEnd - yStart) <= 200) &&
					{
						countblack++;
					}
				}
			}
		}
		if (countblack < 4)
		{
			save[a * 4 + 0] = 0;
			save[a * 4 + 1] = 0;
			save[a * 4 + 2] = 0;
			save[a * 4 + 3] = 0;
		}
	}
}

void Searchalogrith::fourneighbourhood(int x, int y)
{
	if (pbFlag[y][x] == 1)
		pbFlag[y][x] = 0;
	while (((x > 0) && pbFlag[y][x - 1] == 1) || (x < (nWidth-1) && pbFlag[y][x + 1] == 1) || (y>0 && pbFlag[y - 1][x] == 1) || (y< (nHeight-1) && pbFlag[y + 1][x] == 1))
	{
		if (((x > 0) && pbFlag[y][x - 1] == 1))
		{
			//��¼����Ĵ�С
			xStart = min(xStart, (x - 1));
			yStart = min(yStart, y);
			mystack.push(x - 1);
			mystack.push(y);
			x = x - 1;
			pbFlag[y][x] = 0;
		}

		//��ջ����ʾ

		//�������ұߵĵ�

		else if ((x < (nWidth-1)) && pbFlag[y][x + 1] == 1)
		{
			//��¼����Ĵ�С
			xEnd = max(xEnd, (x + 1));
			yStart = min(yStart, y);
			mystack.push(x + 1);
			mystack.push(y);
			x = x + 1;
			pbFlag[y][x] = 0;
		}

		//���������ϵĵ�

		else if (y > 0 && pbFlag[y - 1][x] == 1)
		{
			//��¼����Ĵ�С
			yStart = min(yStart, (y - 1));
			mystack.push(x);
			mystack.push(y - 1);
			y = y - 1;
			pbFlag[y][x] = 0;
		}

		// �������±ߵĵ� 

		else if (y < (nHeight-1) && pbFlag[y + 1][x] == 1)
		{
			// ��¼����Ĵ�С 
			yEnd = max(yEnd, (y + 1));
			mystack.push(x);
			mystack.push(y + 1);
			y = y + 1;
			pbFlag[y][x] = 0;
		}
		else{
			pbFlag[y][x] = 0;
		}
	}
	while (!mystack.empty())
	{
		int y = mystack.top();
		mystack.pop();
		int x = mystack.top();
		mystack.pop();
		while (((x > 0) && pbFlag[y][x - 1] == 1) || (x < (nWidth-1) && pbFlag[y][x + 1] == 1) || (y>0 && pbFlag[y - 1][x] == 1) || (y< (nHeight-1) && pbFlag[y + 1][x] == 1))
		{
			if (pbFlag[y][x] == 1)
				pbFlag[y][x] = 0;

			//��������ߵĵ�
			if (((x > 0) && pbFlag[y][x - 1] == 1))
			{
				//��¼����Ĵ�С
				xStart = min(xStart, (x - 1));
				yStart = min(yStart, y);
				mystack.push(x - 1);
				mystack.push(y);
				x = x - 1;
				pbFlag[y][x] = 0;

			}

			//�������ұߵĵ�

			else if ((x < (nWidth-1)) && pbFlag[y][x + 1] == 1)
			{
				//��¼����Ĵ�С
				xEnd = max(xEnd, (x + 1));
				yStart = min(yStart, y);
				mystack.push(x + 1);
				mystack.push(y);
				x = x + 1;
				pbFlag[y][x] = 0;
			}

			//���������ϵĵ�

			else if (y > 0 && pbFlag[y - 1][x] == 1)
			{
				//��¼����Ĵ�С
				yStart = min(yStart, (y - 1));
				mystack.push(x);
				mystack.push(y - 1);
				y = y - 1;
				pbFlag[y][x] = 0;
			}

			// �������±ߵĵ� 

			else if (y < (nHeight-1) && pbFlag[y + 1][x] == 1)
			{
				// ��¼����Ĵ�С 
				yEnd = max(yEnd, (y + 1));
				mystack.push(x);
				mystack.push(y + 1);
				y = y + 1;
				pbFlag[y][x] = 0;
			}
			else{
				pbFlag[y][x] = 0;
			}
		}
	}
}

void Searchalogrith::searchblack(int x1, int x2, int y1, int y2, int x, int y)
{

	if (pbFlagdouble[y][x] == 1)
		pbFlagdouble[y][x] = 0;
	while (((x > x1) && pbFlagdouble[y][x - 1] == 1) || (x < x2 && pbFlagdouble[y][x + 1] == 1) || (y>y1 && pbFlagdouble[y - 1][x] == 1) || (y< y2 && pbFlagdouble[y + 1][x] == 1))
	{
		if (((x > x1) && pbFlagdouble[y][x - 1] == 1))
		{
			//��¼����Ĵ�С
			xStart = min(xStart, (x - 1));
			yStart = min(yStart, y);
			mystack.push(x - 1);
			mystack.push(y);
			x = x - 1;
			pbFlagdouble[y][x] = 0;
		}

		//��ջ����ʾ

		//�������ұߵĵ�

		else if ((x < x2) && pbFlagdouble[y][x + 1] == 1)
		{
			//��¼����Ĵ�С
			xEnd = max(xEnd, (x + 1));
			yStart = min(yStart, y);
			mystack.push(x + 1);
			mystack.push(y);
			x = x + 1;
			pbFlagdouble[y][x] = 0;
		}

		//���������ϵĵ�

		else if (y > y1 && pbFlagdouble[y - 1][x] == 1)
		{
			//��¼����Ĵ�С
			yStart = min(yStart, (y - 1));
			mystack.push(x);
			mystack.push(y - 1);
			y = y - 1;
			pbFlagdouble[y][x] = 0;
		}

		// �������±ߵĵ� 

		else if (y < y2 && pbFlagdouble[y + 1][x] == 1)
		{
			// ��¼����Ĵ�С 
			yEnd = max(yEnd, (y + 1));
			mystack.push(x);
			mystack.push(y + 1);
			y = y + 1;
			pbFlagdouble[y][x] = 0;
		}
		else{
			pbFlagdouble[y][x] = 0;
		}
	}
	while (!mystack.empty())
	{
		int y = mystack.top();
		mystack.pop();
		int x = mystack.top();
		mystack.pop();
		while (((x > x1) && pbFlagdouble[y][x - 1] == 1) || (x < x2 && pbFlagdouble[y][x + 1] == 1) || (y>y1 && pbFlagdouble[y - 1][x] == 1) || (y< y2 && pbFlagdouble[y + 1][x] == 1))
		{
			if (pbFlagdouble[y][x] == 1)
				pbFlagdouble[y][x] = 0;

			//��������ߵĵ�
			if (((x > x1) && pbFlagdouble[y][x - 1] == 1))
			{
				//��¼����Ĵ�С
				xStart = min(xStart, (x - 1));
				yStart = min(yStart, y);
				mystack.push(x - 1);
				mystack.push(y);
				x = x - 1;
				pbFlagdouble[y][x] = 0;

			}

			//�������ұߵĵ�

			else if ((x < x2) && pbFlagdouble[y][x + 1] == 1)
			{
				//��¼����Ĵ�С
				xEnd = max(xEnd, (x + 1));
				yStart = min(yStart, y);
				mystack.push(x + 1);
				mystack.push(y);
				x = x + 1;
				pbFlagdouble[y][x] = 0;
			}

			//���������ϵĵ�

			else if (y > y1 && pbFlagdouble[y - 1][x] == 1)
			{
				//��¼����Ĵ�С
				yStart = min(yStart, (y - 1));
				mystack.push(x);
				mystack.push(y - 1);
				y = y - 1;
				pbFlagdouble[y][x] = 0;
			}

			// �������±ߵĵ� 

			else if (y < y2 && pbFlagdouble[y + 1][x] == 1)
			{
				// ��¼����Ĵ�С 
				yEnd = max(yEnd, (y + 1));
				mystack.push(x);
				mystack.push(y + 1);
				y = y + 1;
				pbFlagdouble[y][x] = 0;
			}
			else{
				pbFlagdouble[y][x] = 0;
			}
		}
	}
}