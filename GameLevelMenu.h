#pragma once
#include"TinyEngine\\T_Graph.h"
typedef struct {
	POINT pt;
	T_Graph buttonImg;
	wstring name;
}BUTTON;
class GameLevelMenu 
{
public:
	GameLevelMenu();
	~GameLevelMenu();
	void InitButtton();  //��ť��ʼ��
	void Draw(HDC hdc);  
	int MouseClick(int x , int y); //����������İ�ť
private:
	BUTTON pauseButton;  //ռͣ��ť
	BUTTON returnMainButtton;  //�������˵���ť
	int buttonWidth;
	int buttonHeight; //��ť���
	int XSpace;  //��߿����
	int buttonSpace;  //��ť���
	int YSpace;
};

