# Dev-cpp-opencv

1. 下載 opencv 2.4.9 的版本比較穩定

https://sourceforge.net/projects/opencvlibrary/files/opencv-win/2.4.9/opencv-2.4.9.exe/download 	
2. 選擇C槽

3. 選擇 32-bit 
   下方輸入  -static-libgcc -lopencv_core249 -lopencv_highgui249 -lopencv_imgproc249

4. 選擇Directories -> Binaries 

5. 選擇Directories -> Libraries

6. 選擇Directories -> C Includes

7. 選擇Directories -> C++ Includes

8.若出現且照著講義的步驟做還是無法成功，就到C:\Windows\SysWOW64，把 opencv_core249.dll、opencv_core249d.dll、opencv_highgui249.dll、opencv_highgui249d.dll放進去
