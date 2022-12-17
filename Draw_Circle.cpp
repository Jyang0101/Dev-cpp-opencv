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
	int thickness;			 //線條粗細 

	printf("請輸入起始繪圖圓形之x,y座標與半徑\n");
    scanf("%d,%d,%d", &x, &y, &radius);
    printf("起始繪圖圓形之x座標=%d, y座標=%d, 半徑=%d", x, y, radius); 
    
    /*-------繪圖視窗相關設定--------*/
	CvSize ImageSize = cvSize(1000,700);       //視窗大小(1000,700) 
    Image = cvCreateImage(ImageSize,IPL_DEPTH_8U,3);	//繪圖視窗底色 
   	cvNamedWindow("Draw a Circle",1);     	//繪圖視窗命名
    Color=CV_RGB(255,255,255);					//繪圖元件顏色(白色)設定 
    thickness=1;								//繪圖元件線條粗細設定						 
    
	/*-------圖形參數--------*/
	CircleCenter=cvPoint(x,y);	//設圓心為(x,y) 
    cvCircle(Image,CircleCenter,radius,Color,thickness,CV_AA,0);	//繪出圓形
    
	cvShowImage("Draw a Circle",Image); 	//顯示繪圖視窗圓形物件 
    cvWaitKey(0);							//繪圖視窗等待按鍵繼續往下執行 
    
	return 0;							 
} 

