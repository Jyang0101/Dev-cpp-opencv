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
	int x=0,y=0,radius=0;   //x�y��=0  y�y��=0  �b�|=0 
	IplImage *Image;       //�ŧiIplImage��Ƶ��c 
	/*-------����ܼ�--------*/
	CvPoint CircleCenter;    //�ŧi��� 
	CvScalar Color;          //�ŧi�C�� 
	int thickness;			 //�u���ʲ� 

	printf("�п�J�_�lø�϶�Τ�x,y�y�лP�b�|\n");
    scanf("%d,%d,%d", &x, &y, &radius);
    printf("�_�lø�϶�Τ�x�y��=%d, y�y��=%d, �b�|=%d", x, y, radius); 
    
    /*-------ø�ϵ��������]�w--------*/
	CvSize ImageSize = cvSize(1000,700);       //�����j�p(1000,700) 
    Image = cvCreateImage(ImageSize,IPL_DEPTH_8U,3);	//ø�ϵ������� 
   	cvNamedWindow("Draw a Circle",1);     	//ø�ϵ����R�W
    Color=CV_RGB(255,255,255);					//ø�Ϥ����C��(�զ�)�]�w 
    thickness=1;								//ø�Ϥ���u���ʲӳ]�w						 
    
	/*-------�ϧΰѼ�--------*/
	CircleCenter=cvPoint(x,y);	//�]��߬�(x,y) 
    cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);	//ø�X���
    
	cvShowImage("Draw a Circle",Image); 	//���ø�ϵ�����Ϊ��� 
    cvWaitKey(0);							//ø�ϵ������ݫ����~�򩹤U���� 
    
	return 0;							 
} 

