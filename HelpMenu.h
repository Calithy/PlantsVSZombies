#pragma once
#include "TinyEngine\\T_Menu.h"

class HelpMenu :public T_Menu
{
public:
	AudioDXBuffer mousedown_buffer;
	void Init();
	void MenuMouseClick();					// �˵�������¼�����
	void AudioInit(AudioDX &ds);
	void DrawMenu(HDC hdc, int bkgX, int bkgY, BYTE btnTrans = 255, bool startState = true);
};