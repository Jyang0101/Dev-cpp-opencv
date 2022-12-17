#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cv.h>			//Open CV涵式庫 
#include <highgui.h>	//Open CV涵式庫

int main(void)
{
	/*---------------------------------------------變數宣告-------------------------------------------------*/ 
	char directKey;         	
	IplImage *ImageRoad,*ImageCar,*ImageMaskCar;      //宣告道路,汽車與汽車mask圖片IplImage的資料結構
	int car_Xaxis=240,car_Yaxis=600;	//宣告汽車的x, y座標 
    
	do
	{
		ImageRoad=cvLoadImage("road.jpg");	//載入道路圖片 
		ImageCar=cvLoadImage("car.png");	//載入汽車圖片
		ImageMaskCar=cvLoadImage("car.png",0);	//載入汽車mask圖片 
		cvThreshold(ImageMaskCar,ImageMaskCar,254,255,CV_THRESH_BINARY_INV);	//二值化	(輸入圖,輸出圖,閾直,最大值,操作型態(超過閾值的像素設為0，小於閾值的設為最大值) 
		/*========================以下程式由鍵盤控制車子移動====================================*/		
		while(kbhit())			//判斷鍵盤是否有被按下(如果沒有用While迴圈會發生甚麼事情呢?) 
	    {
		               
	    	directKey=getch();		//讀取鍵盤輸入字元  
			switch(directKey)
	        {
	        	case 52:   //鍵盤輸入4汽車x座標遞減10; 
					car_Xaxis-=10;	
	            break;
	            
	            case 54:   //鍵盤輸入6汽車x座標遞增10	
					car_Xaxis+=10;
				break;
				
	        }
	
		}
		cvSetImageROI(ImageRoad,cvRect(car_Xaxis,car_Yaxis,ImageCar->width,ImageCar->height));	//設置感興區域 (感興區域為圖1的一部份,(起始X座標,起始y做標,圖2寬度,圖2高度)) 
		cvCopy(ImageCar,ImageRoad,ImageMaskCar);	//將汽車圖片複製到感興區域 	白色255的部份為顯示出來的區域,黑色為0的部份為不顯示出來的區域,白色的部份還原成圖片
		cvResetImageROI(ImageRoad);	//釋放感興區域 
		cvShowImage("CarMove",ImageRoad); //顯示繪圖介面物件 	
		cvWaitKey(1);	//延緩0.001秒若沒有按下任何案件往下執行 		
		cvReleaseImage(&ImageRoad); //釋放汽車IplImage圖形資料結構所占用的記憶體
		 
	}while(directKey!=17);
}
							
	
	
