#pragma once
#include "TinyEngine\T_Menu.h"
#include "TinyEngine\T_Config.h"
class BookMenu :
	public T_Menu
{
public:
	BookMenu();
	~BookMenu();
public:
	void InitZom();
	void InitSun();
	void InitReturn();
	void InitShut();
	void InitP_return();
	int GetMenuIndex(int x, int y); /*��ò˵�������*/
	//�˵�����: btnTrans��ť͸����, 255��͸��; startState�Ƿ���ƿ�ʼ�˵�
	void DrawMenu(HDC hdc, BYTE btnTrans = 255, bool startState = true);
};

