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
*/

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "Resources.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "LinkedList.h"
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"

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
	void keyDown(KeyEvent event);
	void render();
	gl::Texture mTextTexture;
	Vec2f mSize;
	Font mFont;
private:
	static const int kWinWidth = 600;
	static const int kWinHeight = 600;
	static const int kSurfaceSize=1024;
	Surface* mySurface_;
	LinkedList* list;
	bool help;
};

/*
* Initializes all of the necessary variables and objects needed for
* our text box and drawing methods
* 
*/
void Brush_Royal_Final::setup()
{
	mySurface_ = new Surface(kWinWidth,kWinHeight,false);
	help = true;
	list = new LinkedList();
	list->addNode(1);
	list->addNode(2);
	list->addNode(3);
	list->addNode(4);

	mFont = Font( "Courier New", 40 );
	mSize = Vec2f( 600, 600 );
	render();
}

void Brush_Royal_Final::prepareSettings(Settings *settings){
	(*settings).setWindowSize(kWinHeight, kWinWidth);
	(*settings).setResizable(false);
	//(*settings).setFullScreen(false);
}

/* 
* This method handles keyboard clicks.  Clicking 'r' will reverse the order of the list, 
* clicking '?' will close or open the help textbox, and clicking 'c' will cycle the list.
* 
*/
void Brush_Royal_Final::keyDown(KeyEvent event){
	if(event.getChar() == 'r'){
		list->reverse();
	}
	else if(event.getChar() == 'c'){
		list->cycle();
	}
	else if(event.getChar() == '?'){
		if(help == false)
		help = true;
		else help = false;
	}
}
void Brush_Royal_Final::mouseDown( MouseEvent event )
{

}

/*
* Adds a textbox help screen to the program which can be turned off and on by clicking '?'
* 
* This codes was based heavily on the sample code that Cinder provides to show how to use
* a TextBox()
*/
void Brush_Royal_Final::render(){
	string txt = "WELCOME\n TO THE ROYAL SOCIETY\nFOR PUTTING THINGS\n ON TOP OF \nOTHER THINGS!!\n\nPress ? to show/hide the help screen\nPress r to reverse the order of the shapes\nPress c to cycle the shapes";
	TextBox tbox = TextBox().alignment(TextBox::CENTER).font(mFont).size(Vec2i( mSize.x, mSize.y ) ).text( txt );
	tbox.setBackgroundColor( ColorA( 0.0f, 0.0f, 0.0f ) );
	mTextTexture = gl::Texture( tbox.render() );
}

void Brush_Royal_Final::update()
{

}

void Brush_Royal_Final::draw()
{
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) );
	gl::draw(*mySurface_);
	int data;
	for(int i = 0; i < 5; i++){
		//can't get getData() to work!!!
		data = list->getData(i);
		if(data == 1){
			gl::color(Color(0,0,1));
			gl::drawSolidRect(Rectf(380,300,580,500),false);
			gl::color(Color(1,0,0));
			gl::drawSolidRect(Rectf(400,320,600,520),false);
		}
		else if(data == 2){
			gl::color(Color8u(0,50,0));
			gl::drawColorCube(Vec3f(500,300,100), Vec3f(100,100,100));
		}
		else if(data == 3){
			gl::color(Color(0,1,0));
			gl::drawSolidRect(Rectf(300,300,400,500),false);
			//gl::color(Color(0,1,0));
			//gl::drawCube(Vec3f(300,300,300), Vec3f(300,300,300));
		}
		else if(data == 4){
			gl::color(Color(Color((float) rand()/RAND_MAX,(float) rand()/RAND_MAX,(float) rand()/RAND_MAX)));
			gl::drawSolidCircle(Vec2f(300,300),200);
			gl::color(Color(0,1,0));
			gl::drawSolidCircle(Vec2f(300,300),150);
			gl::color(Color(Color((float) rand()/RAND_MAX,(float) rand()/RAND_MAX,(float) rand()/RAND_MAX)));
			gl::drawSolidCircle(Vec2f(300,300),100);
			gl::color(Color(0,1,0));
			gl::drawSolidCircle(Vec2f(300,300),50);
		}
		else{
			// do nothing
		}
	}

	// tells gl whether or not user wants to see the help textbox
	if(help == true && mTextTexture){
		gl::color(Color(0,1,0));
		gl::draw(mTextTexture);
	}
	
}

CINDER_APP_BASIC( Brush_Royal_Final, RendererGl )
