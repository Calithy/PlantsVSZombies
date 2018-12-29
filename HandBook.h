#pragma once
#include "TinyEngine\T_Graph.h"
#include "TinyEngine\T_Menu.h"
#include"TinyEngine\T_Engine.h"
#include "BookMenu.h"
#include"GraphPlus.h"
#include <codecvt>
typedef struct {
	int count; //˳���
	wstring tip; //ʹ��С����
	wstring sunNum; //��������
	wstring coolTime; //��ȴʱ��
	wstring name; //����
	wstring info; //��ϸ��Ϣ����
	wstring bigPath; //��ͼ��ĵ�ַ
	wstring smallPath; //Сͼ���ַ
}PZ;
enum HANDBOOK {
	BOOK_ZOM,  //��ʬͼ��
	BOOK_SUN,  //ֲ��ͼ��
};  //0 -1
class HandBook : public BookMenu
{
public:
	HandBook();
	~HandBook();
private:
	T_Graph *back; //����
	T_Menu  *button; //��ʬ��ť
	T_Graph *zombie; //��ʬ
	T_Graph *sunflower; //ֲ��
	BookMenu zom; //�鿴��ʬ
	BookMenu sun; //�鿴ֲ��
	BookMenu r_button; //���ذ�ť
	BookMenu shut; //�ر�
	BookMenu p_return; //���ذ�ť
	T_Graph *sun_back;  //ֲ����Ϣҳ�汳��
	T_Graph *zomb_back;  //��ʬ��Ϣҳ�汳��
	T_Graph *info_frame;  //��ϸ��Ϣ��
	T_Graph * grass;
	vector<PZ> plants;   //ֲ������
	vector<PZ> zombies;   //��ʬ����
	float ratio;
	int count;
	int width;
	int height;
	wstring smallPath;
	wstring bigPath;
public:
	int HandBookState;  //ͼ���ڲ�״̬�仯
	
public:
	void Init(); //��ʼ����Դ
	int GetMenuIndex(int x, int y); /*��ò˵�������*/
	void Draw(HDC hdc);

	//void GameMouseAction(int x, int y, int ActionType);
	int MenuMouseClick(int x, int y);
	void MenuMouseMove(int x, int y);

	void DrawSunInfo(HDC hdc);
	void DrawZomInfo(HDC hdc);
	void GetTxtMapValue(wstring str, wstring keywords, wstring & value);
	void GetTxtMapValue(wstring str, wstring keywords, int & value);
	void DrawPlants(HDC hdc);
	void DrawZombies(HDC hdc);
	bool LoadTxt(const char * filepath, vector<PZ>& pz);

	int GetPZindex(int x, int y); //�������

	void  PZMouseMove(int x, int y);  //����ƶ�
	int PZMouseClick(int x,int y); //�����

	void DrawPlantFrameInfo(HDC hdc, int index);

	void DrawZomFrameInfo(HDC hdc,int index);

	

};

