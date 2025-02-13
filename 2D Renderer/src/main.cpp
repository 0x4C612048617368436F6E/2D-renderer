#include"../header/common.hpp"
#include"../header/Window.hpp"
int main() { 
	Window mainWindow;
  mainWindow.setWindowColor();
  //try make sure values of setRenderDisplay is 
  //same as CreateWindow or below that
  mainWindow.setRenderDisplay(0,0,800,800);
  mainWindow.CreateWindow();
	return 0;
}