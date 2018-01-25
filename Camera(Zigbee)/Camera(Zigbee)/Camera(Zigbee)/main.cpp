
#include "pcamera.h"
#include <cassert>  
#include "Com.h"


////////CameraZigBee  

//void main01()
//{
//
//	CSerialPort mySerialPort;
//	//也可以只调用这两个函数
//	/*mySerialPort.InitPort(5);
//	mySerialPort.OpenListenThread();*/
//
//	if (!mySerialPort.InitPort(4))//此处写入串口号
//	{
//		std::cout << "initPort fail !" << std::endl;
//	}
//	else
//	{
//		std::cout << "initPort success !" << std::endl;
//	}
//
//	if (!mySerialPort.OpenListenThread())
//	{
//		std::cout << "OpenListenThread fail !" << std::endl;
//	}
//	else
//	{
//		std::cout << "OpenListenThread success !" << std::endl;
//	}
//
//	while (1)
//	{
//
//		if (mySerialPort.button1)
//		{
//			////
//			//第一个相机先拍摄
//			PCamera  PGreyCamL, PGreyCamR;////定义相机对象
//			unsigned int camFlagL = 0;
//			unsigned int camFlagR = 1;
//			bool CamL = PGreyCamL.ConnectToCamera(camFlagL);///连接相机
//			bool CamR = PGreyCamR.ConnectToCamera(camFlagR);
//			float ms = 3;/////定义曝光时间
//			bool CamExposureL = PGreyCamL.SetExposureTime(ms);
//			bool CamExposureR = PGreyCamR.SetExposureTime(ms);
//			Image imgL, imgR;
//		/*	PGreyCamL.GrabAPicture(imgL);
//			PGreyCamR.GrabAPicture(imgR);*/
//			PGreyCamL.m_Cam.RetrieveBuffer(&imgL);
//			PGreyCamR.m_Cam.RetrieveBuffer(&imgR);
//			////将PointGrey相机拍摄的图片格式转换为opencv中的Mat类型
//			cv::Mat imgL1 = cv::Mat(imgL.GetRows(), imgL.GetCols(), CV_8UC1, (void*)imgL.GetData());
//			cv::Mat imgR1 = cv::Mat(imgR.GetRows(), imgR.GetCols(), CV_8UC1, (void*)imgR.GetData());
//			cv::namedWindow("leftImg", 2);
//			cv::namedWindow("rightImg", 2);
//			imshow("leftImg", imgL1);
//			imshow("rightImg", imgR1);
//			cv::waitKey(600);
//			imgL.Save("D:/CameraPics/Left/1.bmp");////保存图像	//imwrite("D:/CameraImgs/calibration_images/left/2.5m/BiaoBa0133.bmp", img00);
//			imgR.Save("D:/CameraPics/Right/2.bmp");
//			bool Cam0outL = PGreyCamL.DisconnectCamera();////此处要断开相机，因为程序只支持同时连接一个相机。
//			bool Cam0out01 = PGreyCamR.DisconnectCamera();
//			img0.Save("F:/1.bmp");////保存图像	//imwrite("D:/CameraImgs/calibration_images/left/2.5m/BiaoBa0133.bmp", img00);
//
//			cout << "button1" << endl;
//			mySerialPort.button1 = !mySerialPort.button1;
//		}
//
//		if (mySerialPort.button2)
//		{
//			cout << "button2" << endl;
//			mySerialPort.button2 = !mySerialPort.button2;
//		}
//
//		if (mySerialPort.button3)
//		{
//			cout << "button3" << endl;
//			mySerialPort.button3 = !mySerialPort.button3;
//		}
//
//		if (mySerialPort.button4)
//		{
//			cout << "button4" << endl;
//			mySerialPort.button4 = !mySerialPort.button4;
//		}
//
//		if (mySerialPort.button5)
//		{
//			cout << "button5" << endl;
//			mySerialPort.button5 = !mySerialPort.button5;
//		}
//	}
//	int temp;
//	std::cin >> temp;//作用为不使main函数结束
//	//cout << "字节数 = " << mySerialPort.GetBytesInCOM() << endl;
//	//char data;
//	//cout << mySerialPort.ReadChar(data)<<endl;
//
//	if (!mySerialPort.CloseListenTread())
//	{
//		std::cout << "OpenListenThread fail !" << std::endl;
//	}
//	else
//	{
//		std::cout << "OpenListenThread success !" << std::endl;
//	}
//}


void main()
{

	CSerialPort mySerialPort;
	//也可以只调用这两个函数
	/*mySerialPort.InitPort(5);
	mySerialPort.OpenListenThread();*/

	if (!mySerialPort.InitPort(4))//此处写入串口号
	{
		std::cout << "initPort fail !" << std::endl;
	}
	else
	{
		std::cout << "initPort success !" << std::endl;
	}

	if (!mySerialPort.OpenListenThread())
	{
		std::cout << "OpenListenThread fail !" << std::endl;
	}
	else
	{
		std::cout << "OpenListenThread success !" << std::endl;
	}

	while (1)
	{

		_sleep(1000);
		if (mySerialPort.button1)
		{
			////
			//第一个相机先拍摄
			char left[500];
			char right[500];
			int num = 300;
			PCamera  PGreyCamL, PGreyCamR;////定义相机对象
			unsigned int camFlagL = 0;
			unsigned int camFlagR = 1;
			bool CamL = PGreyCamL.ConnectToCamera(camFlagL);  ///连接左相机
			bool CamR = PGreyCamR.ConnectToCamera(camFlagR);  ///连接右相机

			float ms_Left = 0.2;/////定义曝光时间	
			float ms_Right = 1;
			bool CamExposureL = PGreyCamL.SetExposureTime(ms_Left);
			bool CamExposureR = PGreyCamR.SetExposureTime(ms_Right);
			for (size_t k = 0; k < num; k++)
			{
				Image imgL, imgR;
				/*	PGreyCamL.GrabAPicture(imgL);
				PGreyCamR.GrabAPicture(imgR);*/
				PGreyCamL.m_Cam.RetrieveBuffer(&imgL);
				PGreyCamR.m_Cam.RetrieveBuffer(&imgR);
				////将PointGrey相机拍摄的图片格式转换为opencv中的Mat类型
				cv::Mat imgL1 = cv::Mat(imgL.GetRows(), imgL.GetCols(), CV_8UC1, (void*)imgL.GetData());
				cv::Mat imgR1 = cv::Mat(imgR.GetRows(), imgR.GetCols(), CV_8UC1, (void*)imgR.GetData());
			    cv::namedWindow("leftImg", 2);
				cv::namedWindow("rightImg", 2);
				imshow("leftImg", imgL1);
				imshow("rightImg", imgR1);
				cv::waitKey(5);
				sprintf(left, "F:/Lab/30Frames_s/ThreeCodesWithLightPen/Some_out/Left/%d.bmp", k);//保存图片
				sprintf(right, "F:/Lab/30Frames_s/ThreeCodesWithLightPen/Some_out/Right/%d.bmp", k);//保存图片
				imgL.Save(left);
				imgR.Save(right);
			}
			
			bool Cam0outL = PGreyCamL.DisconnectCamera();////此处要断开相机，因为程序只支持同时连接一个相机。
			bool Cam0out01 = PGreyCamR.DisconnectCamera();
			
			cout << "button1" << endl;
			mySerialPort.button1 = !mySerialPort.button1;
		}


	}
	int temp;
	std::cin >> temp;//作用为不使main函数结束


	if (!mySerialPort.CloseListenTread())
	{
		std::cout << "OpenListenThread fail !" << std::endl;
	}
	else
	{
		std::cout << "OpenListenThread success !" << std::endl;
	}
}