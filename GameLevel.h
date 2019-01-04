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
	SPRITEINFO info;	//������Ϣ
	int pointNum;       //ֲ��ı�ʶ
}PLANT_INFO;

typedef struct
{
	int frame;			//�ڵڼ�֡����
	int zombiesindex;	//�ǵڼ��ֽ�ʬ
}ZOMBIES_ARRAY;
typedef struct
{
	int row;			//�ڵڼ���
	int x;				//x����
	T_Sprite* sprite;	//��ʬ����
	SPRITEINFO info;     ///������Ϣ
	int count;           //��ʬ�����д���
	bool isChanged;         //�Ƿ�ı�ͼƬ
}ZOMBIES_INFO;
typedef struct
{
	ZOMBIES_INFO info; 
	int	paintTimes;
}ZOM_HEADER;
typedef struct
{
	bool hit = false;			//�ӵ��Ƿ��Ѿ����н�ʬ
	Point position;		//�ӵ�λ�ã�x->x���꣬y->�ڼ���
	int frame = 10;		//�ӵ����к󲥷�֡��
}BULLET_INFO;
class GameLevel : public T_Scene
{
public:
	static const int MAXPLANTNUM = 2;	//���ֲ����������
	static const int MAXZOMBIESNUM = 2;	//���ʬ��������
	static const int MAXCARNUM = 1;		//����Ƴ�����
	static const int CarXSpace = 50;	//�Ƴ�x�߾�
	static const int YSpace = 80;		//Y�߾�
	static const int CarWidth = 75;		//�Ƴ����
	static const int PlantWidth = 81;	//ֲ����
	static const int PlantHeight = 100;	//ֲ��߶�

	static const int MAXROW = 1;		//���5��
	static const int MAXCOLUMN = 9;		//���9��
	static const int INDEXROW = 2;		//�ӵڼ��п�ʼ

	static const int BULLET_LENGTH = 2;	//�ӵ�����
	static int sequence[15];

	void Init();					//��ʼ��
	void CutsceneInit();			//��ʼ����������
	void PlantInit();				//��ʼ��ֲ��
	void ZombiesInit();				//��ʼ����ʬ
	void ProgressBarInit();			//��ʼ��������
	void CardInit();				//��ʼ��ֲ�￨
	void CarInit();					//��ʼ��С�Ƴ�
	void AudioInit(AudioDX &dx);	//��Ƶ��ʼ��
	void BullentInit();				//�ӵ���ʼ��

	void DrawBullet(HDC hdc);        //�����ӵ�
	void DrawPlant(HDC hdc);		//����ֲ��
	void DrawZombies(HDC hdc);		//���ƽ�ʬ
	void DrawCutscene(HDC hdc);		//���ƹ�������
	void DrawProgressBar(HDC hdc);	//���ƽ�����
	void DrawCard(HDC hdc);			//����ֲ�￨
	void DrawCar(HDC hdc);			//����С�Ƴ�
	void DrawSunLight(HDC hdc);		//��������
	void DrawClickPlant(HDC hdc,int x,int y);
	void Draw(HDC hdc);				//��������

	void Logic();					//�߼�����
	void CardLogic();				//��Ƭ�߼�
	void carLogic();				//С�Ƴ��߼�
	void attackPlantLogic();		//��ʬ����ֲ������ײ,����˺�
	void attackZombieLogic();		//ֲ�﹥����ʬ,�����ӵ�
	void bulletLogic();				//�����ײ�������ӵ�λ�ã�����˺�


	void MouseClick(int x,int y);		//�����Ӧ
	int CardMouseClick(int x, int y);	//�����û��ֲ�ﰴ��ֲ�￨
	void PlantMouseClick(int x, int y);	//��ֲֲ��
	void sunlightMouseClick(int x, int y);//�ռ�����
	void MouseMove(int x,int y);		//����ƶ��¼�

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
	T_Graph Sunlight_img;			//����ͼƬ
	
	bool pointState = false;		//ָ��״̬,false->û��ѡ��ֲ�true->ѡ��ֲ�ﵫû����

	Point PlantPosition;			//û���µ�ѡ��ʱֲ��λ��

	vector<PLANT_INFO> plantVector;	//ֲ������
	CARD plantCard[MAXPLANTNUM];	//ֲ�￨
	T_Graph* plant[MAXPLANTNUM];	//��ֲ̬��ͼ
	T_Sprite* spritePlant[MAXPLANTNUM];//ֲ�ﾫ��ͼ

	vector<ZOMBIES_INFO> zombiesVector;//��ʬ����
	T_Sprite* spriteZombie[MAXZOMBIESNUM];//��ʬ����ͼ
	vector<ZOMBIES_ARRAY> zombiesArray;   //��ʬ����
	T_Sprite* attackedZombies[4];  //�����еĽ�ʬ����
	vector<ZOM_HEADER> zoms_header;

	vector<POINT> sunlightVector;		//δ�ռ�������
	vector<BULLET_INFO> bulletVector;	//�ӵ�����
	T_Graph bullet;					//�ӵ�ͼ
	T_Graph bulletHit;				//����Ч��
	
	int pointPlant;					//ѡ�е�ͼƬ���

	T_Graph progress_bar[5];		//������ͼƬ0->�ս�������1->����������2->������logo��3->��ʬͷ��4->���һ��
	double progress_bar_length;		//����������

	int sunlight = 0;				//������

	CAR_INFO car[MAXCARNUM];		//С�Ƴ�
	
	int frameCount = 0;				//֡������
	int trueFrame = 0;				//���˶���֡
	int MaxFrameCount = 10000;		//��Ϸ����������֡��,���ڼ�����Ϸ���ȣ�������Ϸ����

	AudioDXBuffer bg_buffer;		//��������
	AudioDXBuffer cutscene_buffer;	//������������


};