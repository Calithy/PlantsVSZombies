#pragma once
#include "TinyEngine\\T_Scene.h"
#include "TinyEngine\\T_Audio.h"

typedef struct
{
	int destX;			//����Ŀ��X			
	int destY;			//����Ŀ��Y
	int srcX;			//����ԴͼƬX
	int srcY;			//����ԴͼƬY
	int regionWidth;	//���ƾ��ο�
	int regionHeight;	//���ƾ��θ�
	float ratio;		//���ű���
	int rotType;
	BYTE alpha;
}PAINTREGION_INFO;
typedef struct
{
	int x;				//����Ŀ��x����
	int y;				//����Ŀ��y����
	int time;			//��ȴʱ��,��֡�ʼ�ʱ
	int sunlight;		//��ֲ��������
}CARD_INFO;
typedef struct
{
	T_Graph* card;		//ͼƬ
	CARD_INFO info;		
	int nowTime;		//������ȴ�˶��
	bool state;			//״̬
}CARD;
typedef struct
{
	T_Graph* car;
	int row;			//�ڼ���
	bool state;			//״̬ false->�Ѿ�û�г���
}CAR_INFO;
typedef struct
{
	T_Sprite* sprite;	//ֲ�ﾫ��
	Point position;		//��������
}PLANT_INFO;
class GameLevel : public T_Scene
{
public:
	void Init();					//��ʼ��
	void CutsceneInit();			//��ʼ����������
	void PlantInit();
	void ProgressBarInit();			//��ʼ��������
	void CardInit();				//��ʼ��ֲ�￨
	void CarInit();					//��ʼ��С�Ƴ�
	void AudioInit(AudioDX &dx);	//��Ƶ��ʼ��

	void DrawCutscene(HDC hdc);		//���ƹ�������
	void DrawProgressBar(HDC hdc);	//���ƽ�����
	void DrawCard(HDC hdc);			//����ֲ�￨
	void DrawCar(HDC hdc);			//����С�Ƴ�
	void DrawClickPlant(HDC hdc,int x,int y);
	void Draw(HDC hdc);				//��������

	void Logic();					//�߼�����
	void CardLogic();				//��Ƭ�߼�

	void MouseClick(int x,int y);		//�����Ӧ
	int CardMouseClick(int x, int y);	//�����û��ֲ�ﰴ��ֲ�￨
	void PlantMouseClick(int x, int y);	//��ֲֲ��
	void MouseMove(int x,int y);

	void TestDraw(HDC hdc);			//����
private:
	int mousex;
	int mousey;
	wstring levelName;				//�ؿ���
	T_Graph bg_img;					//����ͼƬ
	T_Graph shadow_img;				//��ӰͼƬ

	//������������
	bool cutsceneFlag = false;		//����������־
	T_Graph cutscene_img;			//������������
	T_Graph cutsceneZombies_img[2];	//������ʬͼƬ
	int cutsceneZombies_FrameCount = 0;//������ʬ֡��������
	int cutsceneFrame = 250;		//����������֡��
	int moveLength;					//���������ƶ�����

	//��Ϸ����
	//T_Graph Zombies_img;				//��ʬͼƬ
	static const int MAXPLANTNUM = 2;	//���ֲ����������
	static const int MAXCARNUM = 1;		//����Ƴ�����
	static const int CarXSpace = 50;	//�Ƴ�x�߾�
	static const int YSpace = 80;		//Y�߾�
	static const int CarWidth = 75;		//�Ƴ����
	static const int PlantWidth = 81;	//ֲ����
	static const int PlantHeight = 100;	//ֲ��߶�

	static const int MAXROW = 1;		//���5��
	static const int MAXCOLUMN = 9;		//���9��
	bool pointState = false;		//ָ��״̬,false->û��ѡ��ֲ�true->ѡ��ֲ�ﵫû����

	Point PlantPosition;			//û���µ�ѡ��ʱֲ��λ��

	vector<PLANT_INFO> plantvector;	//ֲ������
	CARD plantCard[MAXPLANTNUM];	//ֲ�￨
	T_Graph* plant[MAXPLANTNUM];	//��ֲ̬��ͼ·��
	T_Graph* spritePlant[MAXPLANTNUM];//ֲ�ﾫ��ͼ·��
	int pointPlant;					//ѡ�е�ͼƬ���

	T_Graph progress_bar[5];		//������ͼƬ0->�ս�������1->����������2->������logo��3->��ʬͷ��4->���һ��
	double progress_bar_length;		//����������

	int sunlight = 0;				//������

	CAR_INFO car[MAXCARNUM];		//С�Ƴ�
	
	int frameCount = 0;				//֡������
	int MaxFrameCount = 10000;		//��Ϸ����������֡��,���ڼ�����Ϸ���ȣ�������Ϸ����

	AudioDXBuffer bg_buffer;		//��������
	AudioDXBuffer cutscene_buffer;	//������������


};