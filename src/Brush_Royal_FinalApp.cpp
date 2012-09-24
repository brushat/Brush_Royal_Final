/** 
* @file Brush_Royal_FinalApp
* 
* @author Adam Brush
* @date 2012-09-23
* 
* @note This file is (c) 2012. It is licensed under the
* CC BY 3.0 licenses (http://creativecommons.org/licenses/by/3.0/),
* which means you are free to use, share, and remix it as long as you
* give attribution. Commercial uses are allowed.
* 
* This program satisfies the following requirements for HW02:
* 
* 
*/

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "Resources.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "LinkedList.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Brush_Royal_Final : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);
private:
	static const int kWinWidth = 600;
	static const int kWinHeight = 600;
	static const int kSurfaceSize=1024;
	Surface* mySurface_;
	LinkedList* list;
	bool help;
};

void Brush_Royal_Final::setup()
{
	mySurface_ = new Surface(kWinWidth,kWinHeight,false);
	help = true;
	list = new LinkedList();
	list->addNode(1);
	list->addNode(2);
	list->addNode(3);
	list->addNode(4);
}

void Brush_Royal_Final::prepareSettings(Settings *settings){
	(*settings).setWindowSize(kWinHeight, kWinWidth);
	(*settings).setResizable(false);
	//(*settings).setFullScreen(false);
}

void Brush_Royal_Final::mouseDown( MouseEvent event )
{

}

void Brush_Royal_Final::update()
{

}

void Brush_Royal_Final::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	gl::draw(*mySurface_);
	int data;
	for(int i = 0; i < 5; i++){
		data = list->getData(i);
		if(data == 1){
			
		}
		else if(data == 2){
			gl::color(Color8u(0,50,0));
			gl::drawColorCube(Vec3f(500,200,100), Vec3f(100,100,100));
		}
		else if(data == 3){

		}
		else if(data == 4){

		}
		else{
			// do nothing
		}
	}
	
}

CINDER_APP_BASIC( Brush_Royal_Final, RendererGl )
