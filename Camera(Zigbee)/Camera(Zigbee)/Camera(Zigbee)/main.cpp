
#include "pcamera.h"
#include <cassert>  
#include "Com.h"


////////CameraZigBee  

//void main01()
//{
//
//	CSerialPort mySerialPort;
//	//Ҳ����ֻ��������������
//	/*mySerialPort.InitPort(5);
//	mySerialPort.OpenListenThread();*/
//
//	if (!mySerialPort.InitPort(4))//�˴�д�봮�ں�
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
//			//��һ�����������
//			PCamera  PGreyCamL, PGreyCamR;////�����������
//			unsigned int camFlagL = 0;
//			unsigned int camFlagR = 1;
//			bool CamL = PGreyCamL.ConnectToCamera(camFlagL);///�������
//			bool CamR = PGreyCamR.ConnectToCamera(camFlagR);
//			float ms = 3;/////�����ع�ʱ��
//			bool CamExposureL = PGreyCamL.SetExposureTime(ms);
//			bool CamExposureR = PGreyCamR.SetExposureTime(ms);
//			Image imgL, imgR;
//		/*	PGreyCamL.GrabAPicture(imgL);
//			PGreyCamR.GrabAPicture(imgR);*/
//			PGreyCamL.m_Cam.RetrieveBuffer(&imgL);
//			PGreyCamR.m_Cam.RetrieveBuffer(&imgR);
//			////��PointGrey��������ͼƬ��ʽת��Ϊopencv�е�Mat����
//			cv::Mat imgL1 = cv::Mat(imgL.GetRows(), imgL.GetCols(), CV_8UC1, (void*)imgL.GetData());
//			cv::Mat imgR1 = cv::Mat(imgR.GetRows(), imgR.GetCols(), CV_8UC1, (void*)imgR.GetData());
//			cv::namedWindow("leftImg", 2);
//			cv::namedWindow("rightImg", 2);
//			imshow("leftImg", imgL1);
//			imshow("rightImg", imgR1);
//			cv::waitKey(600);
//			imgL.Save("D:/CameraPics/Left/1.bmp");////����ͼ��	//imwrite("D:/CameraImgs/calibration_images/left/2.5m/BiaoBa0133.bmp", img00);
//			imgR.Save("D:/CameraPics/Right/2.bmp");
//			bool Cam0outL = PGreyCamL.DisconnectCamera();////�˴�Ҫ�Ͽ��������Ϊ����ֻ֧��ͬʱ����һ�������
//			bool Cam0out01 = PGreyCamR.DisconnectCamera();
//			img0.Save("F:/1.bmp");////����ͼ��	//imwrite("D:/CameraImgs/calibration_images/left/2.5m/BiaoBa0133.bmp", img00);
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
//	std::cin >> temp;//����Ϊ��ʹmain��������
//	//cout << "�ֽ��� = " << mySerialPort.GetBytesInCOM() << endl;
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
	//Ҳ����ֻ��������������
	/*mySerialPort.InitPort(5);
	mySerialPort.OpenListenThread();*/

	if (!mySerialPort.InitPort(4))//�˴�д�봮�ں�
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
			//��һ�����������
			char left[500];
			char right[500];
			int num = 300;
			PCamera  PGreyCamL, PGreyCamR;////�����������
			unsigned int camFlagL = 0;
			unsigned int camFlagR = 1;
			bool CamL = PGreyCamL.ConnectToCamera(camFlagL);  ///���������
			bool CamR = PGreyCamR.ConnectToCamera(camFlagR);  ///���������

			float ms_Left = 0.2;/////�����ع�ʱ��	
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
				////��PointGrey��������ͼƬ��ʽת��Ϊopencv�е�Mat����
				cv::Mat imgL1 = cv::Mat(imgL.GetRows(), imgL.GetCols(), CV_8UC1, (void*)imgL.GetData());
				cv::Mat imgR1 = cv::Mat(imgR.GetRows(), imgR.GetCols(), CV_8UC1, (void*)imgR.GetData());
			    cv::namedWindow("leftImg", 2);
				cv::namedWindow("rightImg", 2);
				imshow("leftImg", imgL1);
				imshow("rightImg", imgR1);
				cv::waitKey(5);
				sprintf(left, "F:/Lab/30Frames_s/ThreeCodesWithLightPen/Some_out/Left/%d.bmp", k);//����ͼƬ
				sprintf(right, "F:/Lab/30Frames_s/ThreeCodesWithLightPen/Some_out/Right/%d.bmp", k);//����ͼƬ
				imgL.Save(left);
				imgR.Save(right);
			}
			
			bool Cam0outL = PGreyCamL.DisconnectCamera();////�˴�Ҫ�Ͽ��������Ϊ����ֻ֧��ͬʱ����һ�������
			bool Cam0out01 = PGreyCamR.DisconnectCamera();
			
			cout << "button1" << endl;
			mySerialPort.button1 = !mySerialPort.button1;
		}


	}
	int temp;
	std::cin >> temp;//����Ϊ��ʹmain��������


	if (!mySerialPort.CloseListenTread())
	{
		std::cout << "OpenListenThread fail !" << std::endl;
	}
	else
	{
		std::cout << "OpenListenThread success !" << std::endl;
	}
}