
#include "main.h"
#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "wx/wx.h"

USING_NS_CC;
class MyApp : public wxApp
{
public:
	virtual bool OnInit();
	void OnBtnClick(wxCommandEvent & WXUNUSED(event));
};

DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	wxFrame* frame = new wxFrame(NULL, wxID_ANY, wxT("Hello World"));
	wxPanel *panel = new wxPanel(frame, wxID_ANY);
	wxButton *button = new wxButton(panel, wxID_EXIT, wxT("Test"),
		wxPoint(20, 20));
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MyApp::OnBtnClick));
	button->SetFocus();
	//Centre();

	frame->Show();
	//return true;
	AppDelegate app;
	return Application::getInstance()->run();
}

void MyApp::OnBtnClick(wxCommandEvent & WXUNUSED(event))
{
	auto label = Label::createWithSystemFont("aaa", "arial", 18);
	Vec2 pos = Vec2(CCRANDOM_0_1() * 200, CCRANDOM_0_1() * 200);
	label->setPosition(pos);
	//HelloWorld::getInstance()->addChild(label);
	HelloWorld::getInstance()->testAdd();

	
}

/*
int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
    return Application::getInstance()->run();
}
*/