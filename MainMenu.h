#pragma once
#include "TinyEngine\\T_Menu.h"
#include "TinyEngine\\T_Util.h"
typedef struct
{
	POINT	pos;				// �˵�λ��
	int		width;				// �˵����
	int		height;				// �˵��߶�
}MENU_BTNWH_INFO;

class MainMenu:public T_Menu
{
public:
	MainMenu();
	~MainMenu();
	void InitBtn();
	void SetMenuBkg(LPCTSTR img_path, LPCTSTR img_path1, int alphaLevel=255, COLORREF backColor = RGB(0,0,0));
	void DrawMenu(HDC hdc, int bkgX = 0, int bkgY = 0, BYTE btnTrans = 255, bool startState = true);
	int GetMenuIndex(int x, int y);
	void MenuMouseMove(int x, int y);
	int MenuMouseClick(int x, int y);
private:
	int BtnNUM = 9;
	wstring BtnPath[6];
	T_Graph menuBkg;
	MENU_BTNWH_INFO BtnDIBWHInfo[9];		//�˵�����
};


