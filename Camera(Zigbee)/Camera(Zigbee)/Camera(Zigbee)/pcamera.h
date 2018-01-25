#ifndef PCAMERA_H
#define PCAMERA_H
#include<iostream>
#include "opencv.hpp"
#include "fstream"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "FlyCapture2.h"
using namespace std;
using namespace FlyCapture2;
class PCamera
{
public:
    PCamera();
	FlyCapture2::Error m_Error;
	//定义相机对象
    Camera m_Cam;
    TriggerMode m_TriggerMode;

public:
	//连接相机函数，输入0连接第一个相机，输入1连接第二个相机
	bool ConnectToCamera(unsigned int camFlag);
	//断开相机的连接
    bool DisconnectCamera();
	//显示错误
	void PrintError(FlyCapture2::Error error);
	//输出相机信息
    void PrintCameraInfo( CameraInfo* pCamInfo );
	//发射拍摄信号
    bool FireSoftwareTrigger( Camera* pCam );
	//拍摄图片
    void GrabAPicture(Image& pgImage);
	//设置曝光时间
	bool SetExposureTime(float ms);
};

#endif // PCAMERA_H
