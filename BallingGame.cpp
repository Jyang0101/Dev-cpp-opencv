/****************************************************************** 
程式功能: 使用graphics.h之circle(int x,int y, int radius)之繪圖函式，利用鍵盤操作控制該圓之移動方向 
說明：circle中x, y為元新座標；radius為圓形半徑 
輸入參數:  
輸出參數: 
No.   Author.      Date.           Command.
1     WJ-Chang     29/10/2016             
*******************************************************************/  
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cv.h>			//Open CV涵式庫 
#include <highgui.h>	//Open CV涵式庫


int main()
{
	/*---------------------------------------------變數宣告-------------------------------------------------*/ 
	IplImage *Image;						//宣告IplImage資料結構
	char directKey,space1[100],space2[100];//鍵盤輸入字元變數
	int x=0,y=0,radius=30;//半徑=30
	int down,c=0,p=0;//下降和計分變數
	/*-------圓形變數--------*/
	CvPoint CircleCenter;    //宣告圓心 
	CvScalar Color;          //宣告顏色 
	int thickness;			 //字體粗細
	/*-------多邊形形變數--------*/
	CvPoint PointArray1[4];//設4個頂點座標  
	int PolyVertexNumber;//多邊形頂點數目 
	int a=425,b=575;
	/*-------文字變數--------*/
	CvPoint TextPosition1,TextPosition2,TextPosition3,TextPosition4; //CvPoint資料結構文字座標
	CvFont Font;          //宣告CvFont資料結構
	double fontSize;		   //字型大小比例
	
	/*-------繪圖視窗相關設定--------*/
	CvSize ImageSize1 = cvSize(1000,800);//宣告CvSize資料結構,設視窗大小(1000,800)
	Image = cvCreateImage(ImageSize1,IPL_DEPTH_8U,3);//創造一個全黑的基本圖片,需要給它設定空間CvSize資料結構
   	cvNamedWindow("Circle_KeyboardMove",1);     	//繪圖視窗命名
    Color=CV_RGB(255,0,255);					//繪圖元件顏色(紫色)設定 
    thickness=1;								//繪圖元件線條粗細設定						 
    fontSize=2;									//字型大小設定	
	/*-------亂數變數--------*/
	srand(time(NULL));
	x= (rand()%770+30);//隨機出現球的位子 
 	/*-------多邊形形變數--------*/
	PointArray1[0]=cvPoint(a,770);	 
	PointArray1[1]=cvPoint(a,780);
	PointArray1[2]=cvPoint(b,780);
	PointArray1[3]=cvPoint(b,770);
	PolyVertexNumber=4; 	
	/*-------文字變數--------*/ 
	Font=cvFont(fontSize,thickness);
	TextPosition1=cvPoint(200,50);
	TextPosition2=cvPoint(200,75);
	TextPosition3=cvPoint(500,75);
	TextPosition4=cvPoint(200,100);

	do
	{
		/*========================以下程式由鍵盤控制矩形移動====================================*/
		while(kbhit())	//判斷鍵盤是否有被按下 (如果沒有用While迴圈會發生甚麼事情呢?) 
		{
			directKey =getch(); //讀取盤輸輸入字元 
			cvZero(Image); 	//清除畫面 
			switch(directKey)
			{
				case 52: //向左移動;鍵盤輸入4 
				if(a>=0)
				{
					a-=20;
					b-=20;
				}
				break;
				case 54: //向右移動;鍵盤輸入6 
				if(b<=1000)
				{
					a+=20;
					b+=20;
				}
				break;
			}
		}
		
		/*===============以下程式生圓形並往下移動===============*/
		if(y<=800)
		{	
			down=(rand()%15);//下降的亂數
			y+=down;		//圓形Y座標累加代表往下移動 
			cvZero(Image);	//清除畫面 
			CircleCenter=cvPoint(x,y);//讀取圓心為(x,y) 
    		cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);//圓的函示
			if((x>=a && x<=b) && y>=740)		//當球在板子的範圍內+碰到板子的時候 
			{	
				y=0;			//y座標初始化		
				x= (rand()%770+30);//隨機出現球的位子  
				c++; //接到球分數+1 
			} 
			else if((x<a || x>b) && y>=770)		//當球不再板子的範圍內+到板子高度時 
			{
				y=0;		//y座標初始化
				x= (rand()%770+30);	//隨機出現球的位子  
				p++;	//沒接到球分數+1 
			}
		}
		
		PointArray1[0]=cvPoint(a,770);
		PointArray1[1]=cvPoint(a,780);	
		PointArray1[2]=cvPoint(b,780);
		PointArray1[3]=cvPoint(b,770);	
		cvFillConvexPoly(Image,PointArray1,PolyVertexNumber,Color,CV_AA,0);	
		
		cvPutText(Image,"****************************",TextPosition1,&Font,Color);
		sprintf(space1,"catch the ball %d",c);//文自變數變成數字變數
		cvPutText(Image,space1,TextPosition2,&Font,Color);
		sprintf(space2,"miss the ball %d",p);//文自變數變成數字變數
		cvPutText(Image,space2,TextPosition3,&Font,Color);
		cvPutText(Image,"****************************",TextPosition4,&Font,Color);
		
		cvShowImage("Circle_KeyboardMove",Image);//顯示圖片 
		cvWaitKey(1);//延緩0.001秒若沒有按下任何案件往下執行  

	}while(directKey!=17);	
}






