#pragma once
#include "GameLevel.h"
class GameLevel2 :
	public GameLevel
{
public:
	GameLevel2();
	~GameLevel2();
	void Init();
	void PlantChang();
	void AddZombies();
	void ZomArrayInit();
	void BullentInit();
	void PlantInit();
	void CardInit();
	void DrawCar(HDC hdc);
	void DrawCard(HDC hdc);
	void DrawBullet(HDC hdc);
	void Draw(HDC hdc);
	void CardLogic();
	void Logic();
	void attackZombieLogic();
	void PlantMouseClick(int x, int y);
	void attackPlantLogic();
	void bulletLogic();
	int CardMouseClick(int x, int y);
	void MouseClick(int x, int y);


	static const int MAXPLANTNUM = 5;	//���ֲ����������
	static const int MAXCARNUM = 3;		//����Ƴ�����
	static const int MAXZOMBIESNUM = 15;	//���ʬ����
	static const int INDEXROW = 1;		//�ӵڼ��п�ʼ
protected:

	T_Sprite* CherryBomb;
	T_Sprite* WallNutAte;
};

