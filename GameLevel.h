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
class GameLevel : public T_Scene
{
public:
	void Init();					//��ʼ��
	void AudioInit(AudioDX &dx);	//��Ƶ��ʼ��
	void DrawCutscene(HDC hdc);		//���ƹ�������
	void DrawProgressBar(HDC hdc);
	void Draw(HDC hdc);				//��������
private:
	wstring levelName;				//�ؿ���
	T_Graph bg_img;					//����ͼƬ

	bool cutsceneFlag = false;		//����������־
	T_Graph cutscene_img;			//������������
	T_Graph cutsceneZombies_img[2];	//������ʬͼƬ
	int cutsceneZombies_FrameCount = 0;//������ʬ֡��������
	int cutsceneFrame = 250;		//����������֡��
	int moveLength;					//���������ƶ�����

	//T_Graph Zombies_img;			//��ʬͼƬ

	T_Graph progress_bar[5];		//������ͼƬ0->�ս�������1->����������2->������logo��3->��ʬͷ��4->���һ��
	double progress_bar_length;		//����������
	
	int frameCount = 0;				//֡������
	int MaxFrameCount = 500;		//��Ϸ����������֡��,���ڼ�����Ϸ���ȣ�������Ϸ����

	AudioDXBuffer bg_buffer;		//��������
	AudioDXBuffer cutscene_buffer;	//������������


};