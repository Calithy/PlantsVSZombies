#pragma once
#include "GameLevel2.h"
class GameLevel3 :
	public GameLevel2
{
public:
	GameLevel3();
	~GameLevel3();
	void Init();
	
	//void AddZombies();
	void ZomArrayInit();

	void AddZombies();
	
	void Draw(HDC hdc);
	void PlantMouseClick(int x, int y);
	void MouseClick(int x, int y);
	static const int MAXCARNUM = 5;		//����Ƴ�����
	static const int MAXZOMBIESNUM = 25;	//���ʬ����
	static const int INDEXROW = 0;		//�ӵڼ��п�ʼ
//protected:
//
//	T_Sprite* CherryBomb;
//	T_Sprite* WallNutAte;
};

