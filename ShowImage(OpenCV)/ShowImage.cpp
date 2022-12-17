#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cv.h>			//Open CV�[���w 
#include <highgui.h>	//Open CV�[���w

int main(void)
{
	/*---------------------------------------------�ܼƫŧi-------------------------------------------------*/ 
	char directKey;         	
	IplImage *ImageRoad,*ImageCar,*ImageMaskCar;      //�ŧi�D��,�T���P�T��mask�Ϥ�IplImage����Ƶ��c
	int car_Xaxis=240,car_Yaxis=600;	//�ŧi�T����x, y�y�� 
    
	do
	{
		ImageRoad=cvLoadImage("road.jpg");	//���J�D���Ϥ� 
		ImageCar=cvLoadImage("car.png");	//���J�T���Ϥ�
		ImageMaskCar=cvLoadImage("car.png",0);	//���J�T��mask�Ϥ� 
		cvThreshold(ImageMaskCar,ImageMaskCar,254,255,CV_THRESH_BINARY_INV);	//�G�Ȥ�	(��J��,��X��,�H��,�̤j��,�ާ@���A(�W�L�H�Ȫ������]��0�A�p���H�Ȫ��]���̤j��) 
		/*========================�H�U�{������L����l����====================================*/		
		while(kbhit())			//�P�_��L�O�_���Q���U(�p�G�S����While�j��|�o�ͬƻ�Ʊ��O?) 
	    {
		               
	    	directKey=getch();		//Ū����L��J�r��  
			switch(directKey)
	        {
	        	case 52:   //��L��J4�T��x�y�л���10; 
					car_Xaxis-=10;	
	            break;
	            
	            case 54:   //��L��J6�T��x�y�л��W10	
					car_Xaxis+=10;
				break;
				
	        }
	
		}
		cvSetImageROI(ImageRoad,cvRect(car_Xaxis,car_Yaxis,ImageCar->width,ImageCar->height));	//�]�m�P���ϰ� (�P���ϰ쬰��1���@����,(�_�lX�y��,�_�ly����,��2�e��,��2����)) 
		cvCopy(ImageCar,ImageRoad,ImageMaskCar);	//�N�T���Ϥ��ƻs��P���ϰ� 	�զ�255����������ܥX�Ӫ��ϰ�,�¦⬰0������������ܥX�Ӫ��ϰ�,�զ⪺�����٭즨�Ϥ�
		cvResetImageROI(ImageRoad);	//����P���ϰ� 
		cvShowImage("CarMove",ImageRoad); //���ø�Ϥ������� 	
		cvWaitKey(1);	//���w0.001��Y�S�����U����ץ󩹤U���� 		
		cvReleaseImage(&ImageRoad); //����T��IplImage�ϧθ�Ƶ��c�ҥe�Ϊ��O����
		 
	}while(directKey!=17);
}
							
	
	
