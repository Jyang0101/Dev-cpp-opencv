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
	int x=0,y=0,radius=0;   //x座標=0  y座標=0  半徑=0 
	IplImage *Image;       //宣告IplImage資料結構 
	/*-------圓形變數--------*/
	CvPoint CircleCenter;    //宣告圓心 
	CvScalar Color;          //宣告顏色 
	int thickness;			 //字體粗細 
	/*-------文字變數--------*/
	CvPoint TextPosition; //CvPoint資料結構文字座標
	CvFont Font;          //宣告CvFont資料結構
	double fontSize;		   //字型大小比例
	
	printf("請輸入起始繪圖圓形之x,y座標與半徑\n");
    scanf("%d,%d,%d", &x, &y, &radius);
    printf("起始繪圖圓形之x座標=%d, y座標=%d, 半徑=%d", x, y, radius); 
    
    /*-------繪圖視窗相關設定--------*/
	CvSize ImageSize = cvSize(1000,700);       //視窗大小(1000,700) 
    Image = cvCreateImage(ImageSize,IPL_DEPTH_8U,3);	//繪圖視窗底色 
   	cvNamedWindow("Ball Move Example",1);     	//繪圖視窗命名
    Color=CV_RGB(255,255,255);					//繪圖元件顏色(白色)設定 
    thickness=1;								//繪圖元件線條粗細設定						 
    fontSize=1.5;									//字型大小設定 
    
	do
	{
    	/*-------圖形參數--------*/
		CircleCenter=cvPoint(x,y);	//設圓心為(x,y) 
    	cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);	//繪出圓形
    	/*-------字型參數--------*/
		Font=cvFont(fontSize,thickness);  	//cvFont(字型大小比例,字體粗細)
   		TextPosition=cvPoint(50,50);  		//字形座標 
    	cvPutText(Image,"8:Move Up; 2:Move Down; 4:Move Left; 6:Move Right; Control+q:Exit",TextPosition,&Font,Color);	//字型的函示 			
    	cvShowImage("Ball Move Example",Image); 
		cvWaitKey(1);	//延緩0.001秒若沒有按下任何案件往下執行 
		
		/*========================以下程式由鍵盤控制圓形移動====================================*/
		while(kbhit()) 							//判斷鍵盤是否有被按下 (如果沒有用While迴圈會發生甚麼事情呢?) 
		{
			directKey =getch();				//讀取盤輸輸入字元
			cvZero(Image);					//清除畫面 
			switch(directKey)
			{
				case 52:					//向左移動;鍵盤輸入4 
					x-=10;					//x軸-10代表向左移動 			
					break;
				case 54:					//向右移動;鍵盤輸入6 
					x+=10;					//x軸+10代表向右移動
					break;
				case 56:					//向上移動;鍵盤輸入8 
					y-=10;					//y軸-10代表向上移動
					break;
				case 50: 					//向下移動;鍵盤輸入2 	
					y+=10;					//y軸+10代表向上移動
				break;
				
				default:
				break;			
			}	
		}
	}while(directKey!=17);								 
} 

