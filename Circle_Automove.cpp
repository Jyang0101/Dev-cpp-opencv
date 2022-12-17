/****************************************************************** 
�{���\��: �ϥ�graphics.h��circle(int x,int y, int radius)��ø�Ϩ禡�A�Q����L�ާ@����Ӷꤧ���ʤ�V 
�����Gcircle��x, y�����s�y�СFradius����Υb�| 
��J�Ѽ�:  
��X�Ѽ�: 
No.   Author.      Date.           Command.
1     WJ-Chang     29/10/2016             
*******************************************************************/  
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cv.h>			//Open CV�[���w 
#include <highgui.h>	//Open CV�[���w

int main(void)
{
	/*---------------------------------------------�ܼƫŧi-------------------------------------------------*/ 
	char directKey;         //�ŧi�ܼ� 
	int x=300,y=300,radius=30;   //x�y��=0  y�y��=0  �b�|=0
	int i; 
	IplImage *Image;       //�ŧiIplImage��Ƶ��c 
	/*-------����ܼ�--------*/
	CvPoint CircleCenter;    //�ŧi��� 
	CvScalar Color;          //�ŧi�C�� 
	int thickness;			 //�r��ʲ� 
	/*-------��r�ܼ�--------*/
	CvPoint TextPosition; //CvPoint��Ƶ��c��r�y��
	CvFont Font;          //�ŧiCvFont��Ƶ��c
	double fontSize;		   //�r���j�p���
    
    /*-------ø�ϵ��������]�w--------*/
	CvSize ImageSize = cvSize(600,600);       //�����j�p(1000,700) 
    Image = cvCreateImage(ImageSize,IPL_DEPTH_8U,3);	//ø�ϵ������� 
   	cvNamedWindow("Ball Move Example",1);     	//ø�ϵ����R�W
    Color=CV_RGB(255,255,255);					//ø�Ϥ����C��(�զ�)�]�w 
    thickness=1;								//ø�Ϥ���u���ʲӳ]�w						 
    fontSize=1.5;									//�r���j�p�]�w 
    
    /*-------�ϧΰѼ�--------*/
	CircleCenter=cvPoint(x,y);	//�]��߬�(x,y) 
    cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);	//ø�X���
    /*-------�r���Ѽ�--------*/
	Font=cvFont(fontSize,thickness);  	//cvFont(�r���j�p���,�r��ʲ�)
   	TextPosition=cvPoint(10,50);  		//�r�ήy�� 
    cvPutText(Image,"Press Buttom 8, Then Circle will Automove...",TextPosition,&Font,Color);	//�r������� 			
    
	cvShowImage("Ball Move Example",Image); //���ø�Ϥ������� 
	cvWaitKey(1);	//���w0.001��Y�S�����U����ץ󩹤U���� 
    	
	directKey =getch();				//Ū���L���J�r��
	switch(directKey)
	{
		case 56:					//�V�W����;��L��J8 
			i=y;
			do
			{
				if(i>=radius)
				{
					for(;i>=radius;i-=5)
					{
						cvZero(Image);
						CircleCenter=cvPoint(x,i);	//�]��߬�(x,i) 
						cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);	//ø�X���
						cvShowImage("Ball Move Example",Image);	//���ø�Ϥ�������
						cvWaitKey(100); //���w0.01��
					}
				}
				if (i <= (600-radius))
                {
                    for (; i<= (600-radius); i+=5)
                    {
                        cvZero(Image);
						CircleCenter=cvPoint(x,i);	//�]��߬�(x,i) 
						cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);	//ø�X���
						cvShowImage("Ball Move Example",Image);	//���ø�Ϥ�������
						cvWaitKey(100);	//���w0.01��
                    }
                }                        
			}while(1);
			break;
	}							 
} 

