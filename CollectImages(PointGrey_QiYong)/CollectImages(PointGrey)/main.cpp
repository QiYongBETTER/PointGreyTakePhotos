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


//两个相机软触发拍摄
void main01()
{
	//////给系统添加计时器
	//////两个相机先后拍摄图片
	///第一个相机先拍摄
	char left[500];
	char right[500];
	PCamera  PGreyCamL, PGreyCamR;////定义相机对象
	unsigned int camFlagL = 0;
	unsigned int camFlagR = 1;
	_sleep(200);
	bool CamL = PGreyCamL.ConnectToCamera(camFlagL);///连接相机
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
		////将PointGrey相机拍摄的图片格式转换为opencv中的Mat类型
		cv::Mat imgL1 = cv::Mat(imgL.GetRows(), imgL.GetCols(), CV_8UC1, (void*)imgL.GetData());
		cv::Mat imgR1 = cv::Mat(imgR.GetRows(), imgR.GetCols(), CV_8UC1, (void*)imgR.GetData());
		cv::namedWindow("leftImg", 2);
		cv::namedWindow("rightImg", 2);
		imshow("leftImg", imgL1);
		imshow("rightImg", imgR1);
		cv::waitKey(5);

	
		sprintf(left, "E:/LAb/20170820/Left/%d.bmp", num);//保存图片
		sprintf(right, "E:/LAb/20170820/Right/%d.bmp", num);//保存图片
		imgL.Save(left);
		imgR.Save(right);
	
	}
	bool Cam0outL = PGreyCamL.DisconnectCamera();////此处要断开相机，因为程序只支持同时连接一个相机。
	bool Cam0outR = PGreyCamR.DisconnectCamera();
}


//只有一个相机拍照
void main()
{
	//////给系统添加计时器
	//////两个相机先后拍摄图片
	///第一个相机先拍摄
	char left[500];
	PCamera  PGreyCamL;////定义相机对象
	unsigned int camFlagL = 0;
	_sleep(600);
	bool CamL = PGreyCamL.ConnectToCamera(camFlagL);///连接相机
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
			////将PointGrey相机拍摄的图片格式转换为opencv中的Mat类型
			cv::Mat imgL1 = cv::Mat(imgL.GetRows(), imgL.GetCols(), CV_8UC1, (void*)imgL.GetData());
			cv::namedWindow("leftImg", 2);
			imshow("leftImg", imgL1);
			if (cv::waitKey(30)>=0)
				break;
		}
		sprintf(left, "F:/PicsForRT/L/%d.bmp", num);//保存图片
		imgL.Save(left);
	}
	bool Cam0outL = PGreyCamL.DisconnectCamera();////此处要断开相机，因为程序只支持同时连接一个相机。
}



//两个相机同时拍摄，可以通过空格键来控制拍摄

void main04()
{
	//////给系统添加计时器
	//////两个相机先后拍摄图片
	///第一个相机先拍摄
	char left[500];
	char right[500];
	PCamera  PGreyCamL, PGreyCamR;////定义相机对象
	unsigned int camFlagL = 0;
	unsigned int camFlagR = 1;
	_sleep(200);
	bool CamL = PGreyCamL.ConnectToCamera(camFlagL);///连接相机
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
			////将PointGrey相机拍摄的图片格式转换为opencv中的Mat类型
			cv::Mat imgL1 = cv::Mat(imgL.GetRows(), imgL.GetCols(), CV_8UC1, (void*)imgL.GetData());
			cv::Mat imgR1 = cv::Mat(imgR.GetRows(), imgR.GetCols(), CV_8UC1, (void*)imgR.GetData());
			cv::namedWindow("leftImg", 2);
			cv::namedWindow("rightImg", 2);
			imshow("leftImg", imgL1);
			imshow("rightImg", imgR1);
		

			if (cv::waitKey(30) >= 0)
				break;

	}
		sprintf(left, "F:/PicsForRT/L/%d.bmp", num);//保存图片
		sprintf(right, "F:/PicsForRT/R/%d.bmp", num);//保存图片
		imgL.Save(left);
		imgR.Save(right);
	}

	bool Cam0outL = PGreyCamL.DisconnectCamera();////此处要断开相机，因为程序只支持同时连接一个相机。
	bool Cam0outR = PGreyCamR.DisconnectCamera();
}