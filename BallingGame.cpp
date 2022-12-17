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
#include <time.h>
#include <cv.h>			//Open CV�[���w 
#include <highgui.h>	//Open CV�[���w


int main()
{
	/*---------------------------------------------�ܼƫŧi-------------------------------------------------*/ 
	IplImage *Image;						//�ŧiIplImage��Ƶ��c
	char directKey,space1[100],space2[100];//��L��J�r���ܼ�
	int x=0,y=0,radius=30;//�b�|=30
	int down,c=0,p=0;//�U���M�p���ܼ�
	/*-------����ܼ�--------*/
	CvPoint CircleCenter;    //�ŧi��� 
	CvScalar Color;          //�ŧi�C�� 
	int thickness;			 //�r��ʲ�
	/*-------�h��Χ��ܼ�--------*/
	CvPoint PointArray1[4];//�]4�ӳ��I�y��  
	int PolyVertexNumber;//�h��γ��I�ƥ� 
	int a=425,b=575;
	/*-------��r�ܼ�--------*/
	CvPoint TextPosition1,TextPosition2,TextPosition3,TextPosition4; //CvPoint��Ƶ��c��r�y��
	CvFont Font;          //�ŧiCvFont��Ƶ��c
	double fontSize;		   //�r���j�p���
	
	/*-------ø�ϵ��������]�w--------*/
	CvSize ImageSize1 = cvSize(1000,800);//�ŧiCvSize��Ƶ��c,�]�����j�p(1000,800)
	Image = cvCreateImage(ImageSize1,IPL_DEPTH_8U,3);//�гy�@�ӥ��ª��򥻹Ϥ�,�ݭn�����]�w�Ŷ�CvSize��Ƶ��c
   	cvNamedWindow("Circle_KeyboardMove",1);     	//ø�ϵ����R�W
    Color=CV_RGB(255,0,255);					//ø�Ϥ����C��(����)�]�w 
    thickness=1;								//ø�Ϥ���u���ʲӳ]�w						 
    fontSize=2;									//�r���j�p�]�w	
	/*-------�ü��ܼ�--------*/
	srand(time(NULL));
	x= (rand()%770+30);//�H���X�{�y����l 
 	/*-------�h��Χ��ܼ�--------*/
	PointArray1[0]=cvPoint(a,770);	 
	PointArray1[1]=cvPoint(a,780);
	PointArray1[2]=cvPoint(b,780);
	PointArray1[3]=cvPoint(b,770);
	PolyVertexNumber=4; 	
	/*-------��r�ܼ�--------*/ 
	Font=cvFont(fontSize,thickness);
	TextPosition1=cvPoint(200,50);
	TextPosition2=cvPoint(200,75);
	TextPosition3=cvPoint(500,75);
	TextPosition4=cvPoint(200,100);

	do
	{
		/*========================�H�U�{������L����x�β���====================================*/
		while(kbhit())	//�P�_��L�O�_���Q���U (�p�G�S����While�j��|�o�ͬƻ�Ʊ��O?) 
		{
			directKey =getch(); //Ū���L���J�r�� 
			cvZero(Image); 	//�M���e�� 
			switch(directKey)
			{
				case 52: //�V������;��L��J4 
				if(a>=0)
				{
					a-=20;
					b-=20;
				}
				break;
				case 54: //�V�k����;��L��J6 
				if(b<=1000)
				{
					a+=20;
					b+=20;
				}
				break;
			}
		}
		
		/*===============�H�U�{���Ͷ�Ψé��U����===============*/
		if(y<=800)
		{	
			down=(rand()%15);//�U�����ü�
			y+=down;		//���Y�y�в֥[�N���U���� 
			cvZero(Image);	//�M���e�� 
			CircleCenter=cvPoint(x,y);//Ū����߬�(x,y) 
    		cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);//�ꪺ���
			if((x>=a && x<=b) && y>=740)		//��y�b�O�l���d��+�I��O�l���ɭ� 
			{	
				y=0;			//y�y�Ъ�l��		
				x= (rand()%770+30);//�H���X�{�y����l  
				c++; //����y����+1 
			} 
			else if((x<a || x>b) && y>=770)		//��y���A�O�l���d��+��O�l���׮� 
			{
				y=0;		//y�y�Ъ�l��
				x= (rand()%770+30);	//�H���X�{�y����l  
				p++;	//�S����y����+1 
			}
		}
		
		PointArray1[0]=cvPoint(a,770);
		PointArray1[1]=cvPoint(a,780);	
		PointArray1[2]=cvPoint(b,780);
		PointArray1[3]=cvPoint(b,770);	
		cvFillConvexPoly(Image,PointArray1,PolyVertexNumber,Color,CV_AA,0);	
		
		cvPutText(Image,"****************************",TextPosition1,&Font,Color);
		sprintf(space1,"catch the ball %d",c);//����ܼ��ܦ��Ʀr�ܼ�
		cvPutText(Image,space1,TextPosition2,&Font,Color);
		sprintf(space2,"miss the ball %d",p);//����ܼ��ܦ��Ʀr�ܼ�
		cvPutText(Image,space2,TextPosition3,&Font,Color);
		cvPutText(Image,"****************************",TextPosition4,&Font,Color);
		
		cvShowImage("Circle_KeyboardMove",Image);//��ܹϤ� 
		cvWaitKey(1);//���w0.001��Y�S�����U����ץ󩹤U����  

	}while(directKey!=17);	
}






