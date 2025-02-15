#include"../header/common.hpp"
#include"../header/Window.hpp"
int main() { 
	Window mainWindow;
        mainWindow.setWindowColor();
  mainWindow.setRenderDisplay();//default value is 0,0,800,800
  mainWindow.CreateWindow();
  //specify size of triangle
  mainWindow.drawTriangle();
	return 0;
}