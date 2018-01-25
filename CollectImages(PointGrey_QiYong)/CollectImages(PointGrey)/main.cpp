#include "pcamera.h"


#include <opencv2/opencv.hpp>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
using namespace cv;


IplImage	*img;
IplImage	*dst;


//���������������
void main01()
{
	//////��ϵͳ��Ӽ�ʱ��
	//////��������Ⱥ�����ͼƬ
	///��һ�����������
	char left[500];
	char right[500];
	PCamera  PGreyCamL, PGreyCamR;////�����������
	unsigned int camFlagL = 0;
	unsigned int camFlagR = 1;
	_sleep(200);
	bool CamL = PGreyCamL.ConnectToCamera(camFlagL);///�������
	bool CamR = PGreyCamR.ConnectToCamera(camFlagR);
	for (int num = 1; num <500; num++)
	{
		//_sleep(1000);
		float msL = 3;
		float msR = 3;
		bool CamExposureL = PGreyCamL.SetExposureTime(msL);
		bool CamExposureR = PGreyCamR.SetExposureTime(msR);
		Image imgL, imgR;
		PGreyCamL.GrabAPicture(imgL);
		PGreyCamR.GrabAPicture(imgR);
		////��PointGrey��������ͼƬ��ʽת��Ϊopencv�е�Mat����
		cv::Mat imgL1 = cv::Mat(imgL.GetRows(), imgL.GetCols(), CV_8UC1, (void*)imgL.GetData());
		cv::Mat imgR1 = cv::Mat(imgR.GetRows(), imgR.GetCols(), CV_8UC1, (void*)imgR.GetData());
		cv::namedWindow("leftImg", 2);
		cv::namedWindow("rightImg", 2);
		imshow("leftImg", imgL1);
		imshow("rightImg", imgR1);
		cv::waitKey(5);

	
		sprintf(left, "E:/LAb/20170820/Left/%d.bmp", num);//����ͼƬ
		sprintf(right, "E:/LAb/20170820/Right/%d.bmp", num);//����ͼƬ
		imgL.Save(left);
		imgR.Save(right);
	
	}
	bool Cam0outL = PGreyCamL.DisconnectCamera();////�˴�Ҫ�Ͽ��������Ϊ����ֻ֧��ͬʱ����һ�������
	bool Cam0outR = PGreyCamR.DisconnectCamera();
}


//ֻ��һ���������
void main()
{
	//////��ϵͳ��Ӽ�ʱ��
	//////��������Ⱥ�����ͼƬ
	///��һ�����������
	char left[500];
	PCamera  PGreyCamL;////�����������
	unsigned int camFlagL = 0;
	_sleep(600);
	bool CamL = PGreyCamL.ConnectToCamera(camFlagL);///�������
	for (int num = 1; num < 100; num++)
	{
		//_sleep(1000);
		float msL = 120;
		//float msR= 1.8;
		bool CamExposureL = PGreyCamL.SetExposureTime(msL);
		Image imgL;
		while (1)
		{
			PGreyCamL.GrabAPicture(imgL);
			////��PointGrey��������ͼƬ��ʽת��Ϊopencv�е�Mat����
			cv::Mat imgL1 = cv::Mat(imgL.GetRows(), imgL.GetCols(), CV_8UC1, (void*)imgL.GetData());
			cv::namedWindow("leftImg", 2);
			imshow("leftImg", imgL1);
			if (cv::waitKey(30)>=0)
				break;
		}
		sprintf(left, "F:/PicsForRT/L/%d.bmp", num);//����ͼƬ
		imgL.Save(left);
	}
	bool Cam0outL = PGreyCamL.DisconnectCamera();////�˴�Ҫ�Ͽ��������Ϊ����ֻ֧��ͬʱ����һ�������
}



//�������ͬʱ���㣬����ͨ���ո������������

void main04()
{
	//////��ϵͳ��Ӽ�ʱ��
	//////��������Ⱥ�����ͼƬ
	///��һ�����������
	char left[500];
	char right[500];
	PCamera  PGreyCamL, PGreyCamR;////�����������
	unsigned int camFlagL = 0;
	unsigned int camFlagR = 1;
	_sleep(200);
	bool CamL = PGreyCamL.ConnectToCamera(camFlagL);///�������
	bool CamR = PGreyCamR.ConnectToCamera(camFlagR);

	for (int num = 1; num < 100; num++)
	{
		//_sleep(1000);
		float msL = 100;
		float msR = 50;
		bool CamExposureL = PGreyCamL.SetExposureTime(msL);
		bool CamExposureR = PGreyCamR.SetExposureTime(msR);
		Image imgL, imgR;
		while (1)
		{
			PGreyCamL.GrabAPicture(imgL);
			PGreyCamR.GrabAPicture(imgR);
			////��PointGrey��������ͼƬ��ʽת��Ϊopencv�е�Mat����
			cv::Mat imgL1 = cv::Mat(imgL.GetRows(), imgL.GetCols(), CV_8UC1, (void*)imgL.GetData());
			cv::Mat imgR1 = cv::Mat(imgR.GetRows(), imgR.GetCols(), CV_8UC1, (void*)imgR.GetData());
			cv::namedWindow("leftImg", 2);
			cv::namedWindow("rightImg", 2);
			imshow("leftImg", imgL1);
			imshow("rightImg", imgR1);
		

			if (cv::waitKey(30) >= 0)
				break;

	}
		sprintf(left, "F:/PicsForRT/L/%d.bmp", num);//����ͼƬ
		sprintf(right, "F:/PicsForRT/R/%d.bmp", num);//����ͼƬ
		imgL.Save(left);
		imgR.Save(right);
	}

	bool Cam0outL = PGreyCamL.DisconnectCamera();////�˴�Ҫ�Ͽ��������Ϊ����ֻ֧��ͬʱ����һ�������
	bool Cam0outR = PGreyCamR.DisconnectCamera();
}