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
#include <cv.h>			//Open CV涵式庫 
#include <highgui.h>	//Open CV涵式庫

int main(void)
{
	/*---------------------------------------------變數宣告-------------------------------------------------*/ 
	char directKey;         //宣告變數 
	int x=300,y=300,radius=30;   //x座標=0  y座標=0  半徑=0
	int i; 
	IplImage *Image;       //宣告IplImage資料結構 
	/*-------圓形變數--------*/
	CvPoint CircleCenter;    //宣告圓心 
	CvScalar Color;          //宣告顏色 
	int thickness;			 //字體粗細 
	/*-------文字變數--------*/
	CvPoint TextPosition; //CvPoint資料結構文字座標
	CvFont Font;          //宣告CvFont資料結構
	double fontSize;		   //字型大小比例
    
    /*-------繪圖視窗相關設定--------*/
	CvSize ImageSize = cvSize(600,600);       //視窗大小(1000,700) 
    Image = cvCreateImage(ImageSize,IPL_DEPTH_8U,3);	//繪圖視窗底色 
   	cvNamedWindow("Ball Move Example",1);     	//繪圖視窗命名
    Color=CV_RGB(255,255,255);					//繪圖元件顏色(白色)設定 
    thickness=1;								//繪圖元件線條粗細設定						 
    fontSize=1.5;									//字型大小設定 
    
    /*-------圖形參數--------*/
	CircleCenter=cvPoint(x,y);	//設圓心為(x,y) 
    cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);	//繪出圓形
    /*-------字型參數--------*/
	Font=cvFont(fontSize,thickness);  	//cvFont(字型大小比例,字體粗細)
   	TextPosition=cvPoint(10,50);  		//字形座標 
    cvPutText(Image,"Press Buttom 8, Then Circle will Automove...",TextPosition,&Font,Color);	//字型的函示 			
    
	cvShowImage("Ball Move Example",Image); //顯示繪圖介面物件 
	cvWaitKey(1);	//延緩0.001秒若沒有按下任何案件往下執行 
    	
	directKey =getch();				//讀取盤輸輸入字元
	switch(directKey)
	{
		case 56:					//向上移動;鍵盤輸入8 
			i=y;
			do
			{
				if(i>=radius)
				{
					for(;i>=radius;i-=5)
					{
						cvZero(Image);
						CircleCenter=cvPoint(x,i);	//設圓心為(x,i) 
						cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);	//繪出圓形
						cvShowImage("Ball Move Example",Image);	//顯示繪圖介面物件
						cvWaitKey(100); //延緩0.01秒
					}
				}
				if (i <= (600-radius))
                {
                    for (; i<= (600-radius); i+=5)
                    {
                        cvZero(Image);
						CircleCenter=cvPoint(x,i);	//設圓心為(x,i) 
						cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);	//繪出圓形
						cvShowImage("Ball Move Example",Image);	//顯示繪圖介面物件
						cvWaitKey(100);	//延緩0.01秒
                    }
                }                        
			}while(1);
			break;
	}							 
} 

