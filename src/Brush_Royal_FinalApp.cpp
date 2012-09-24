#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Brush_Royal_FinalApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Brush_Royal_FinalApp::setup()
{
}

void Brush_Royal_FinalApp::mouseDown( MouseEvent event )
{
}

void Brush_Royal_FinalApp::update()
{
}

void Brush_Royal_FinalApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( Brush_Royal_FinalApp, RendererGl )
