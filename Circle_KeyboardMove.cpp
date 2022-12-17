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
	int thickness;			 //�r��ʲ� 
	/*-------��r�ܼ�--------*/
	CvPoint TextPosition; //CvPoint��Ƶ��c��r�y��
	CvFont Font;          //�ŧiCvFont��Ƶ��c
	double fontSize;		   //�r���j�p���
	
	printf("�п�J�_�lø�϶�Τ�x,y�y�лP�b�|\n");
    scanf("%d,%d,%d", &x, &y, &radius);
    printf("�_�lø�϶�Τ�x�y��=%d, y�y��=%d, �b�|=%d", x, y, radius); 
    
    /*-------ø�ϵ��������]�w--------*/
	CvSize ImageSize = cvSize(1000,700);       //�����j�p(1000,700) 
    Image = cvCreateImage(ImageSize,IPL_DEPTH_8U,3);	//ø�ϵ������� 
   	cvNamedWindow("Ball Move Example",1);     	//ø�ϵ����R�W
    Color=CV_RGB(255,255,255);					//ø�Ϥ����C��(�զ�)�]�w 
    thickness=1;								//ø�Ϥ���u���ʲӳ]�w						 
    fontSize=1.5;									//�r���j�p�]�w 
    
	do
	{
    	/*-------�ϧΰѼ�--------*/
		CircleCenter=cvPoint(x,y);	//�]��߬�(x,y) 
    	cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);	//ø�X���
    	/*-------�r���Ѽ�--------*/
		Font=cvFont(fontSize,thickness);  	//cvFont(�r���j�p���,�r��ʲ�)
   		TextPosition=cvPoint(50,50);  		//�r�ήy�� 
    	cvPutText(Image,"8:Move Up; 2:Move Down; 4:Move Left; 6:Move Right; Control+q:Exit",TextPosition,&Font,Color);	//�r������� 			
    	cvShowImage("Ball Move Example",Image); 
		cvWaitKey(1);	//���w0.001��Y�S�����U����ץ󩹤U���� 
		
		/*========================�H�U�{������L�����β���====================================*/
		while(kbhit()) 							//�P�_��L�O�_���Q���U (�p�G�S����While�j��|�o�ͬƻ�Ʊ��O?) 
		{
			directKey =getch();				//Ū���L���J�r��
			cvZero(Image);					//�M���e�� 
			switch(directKey)
			{
				case 52:					//�V������;��L��J4 
					x-=10;					//x�b-10�N��V������ 			
					break;
				case 54:					//�V�k����;��L��J6 
					x+=10;					//x�b+10�N��V�k����
					break;
				case 56:					//�V�W����;��L��J8 
					y-=10;					//y�b-10�N��V�W����
					break;
				case 50: 					//�V�U����;��L��J2 	
					y+=10;					//y�b+10�N��V�W����
				break;
				
				default:
				break;			
			}	
		}
	}while(directKey!=17);								 
} 

