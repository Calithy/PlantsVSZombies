#include "ChoiceMenu.h"



ChoiceMenu::ChoiceMenu()
{
}


ChoiceMenu::~ChoiceMenu()
{
}

void ChoiceMenu::Init()
{
	SetMenuBkg(L"res\\images\\interface\\menu\\choicemenu\\OptionsMenuback8.png");
	int x = 0, y = 0;
	int btn_width = 0, btn_height = 0;
	Color normalClr, focusClr;
	wstring menuItems[] = { L"��Ϸѡ��",L"��Ϸ����",L"�鿴ͼ��",L"���¿�ʼ",L"���ز˵�" };
	btn_width = 360;
	btn_height = 100;
	normalClr = Color::Yellow;
	focusClr = Color::White;
	SetBtnBmp(L"res\\images\\interface\\menu\\choicemenu\\OptionsBackButton8.png", btn_width, btn_height);

	//���ò˵���Ϣ
	MENU_INFO menuInfo;
	menuInfo.align = 1;   //���뷽ʽ����
	menuInfo.space = 5; //�˵���֮��ļ������
	menuInfo.width = btn_width; //�˵����
	menuInfo.height = btn_height; //�˵����
	menuInfo.fontName = L"����"; //�˵�������
	menuInfo.isBold = true; //�Ƿ����
	menuInfo.normalTextColor = normalClr; //����״̬����
	menuInfo.focusTextColor = focusClr;  //ѡ��״̬����
	SetMenuInfo(menuInfo);
	for (int i = 0; i < 5; i++)
	{
		//��ֱ���в�������
		x = (WIN_WIDTH - 412) / 2 + (412 - btn_width * 0.5) / 2;
		//y =  10 + i * (btn_height + MENU_SPACE) + (wnd_height - 6* btn_height - 5* MENU_SPACE) / 6;
		y =  (WIN_HEIGHT - 483)/2 + 104 + i * (btn_height * 0.5 + 5);
		MENUITEM mItem;
		mItem.pos.x = x;
		mItem.pos.y = y;
		mItem.ItemName = menuItems[i];   //��ǰ�˵�������
		AddMenuItem(mItem);
	}
}

void ChoiceMenu::returnMenuInit()
{
	int x = 0, y = 0;
	int btn_width = 0, btn_height = 0;
	Color normalClr, focusClr;
	wstring menuItems = { L"������Ϸ" };
	btn_width = 360;
	btn_height = 100;
	normalClr = Color::Yellow;
	focusClr = Color::White;
	SetBtnBmp(L"res\\images\\interface\\menu\\choicemenu\\OptionsBackButton8.png", btn_width, btn_height);
	//���ò˵���Ϣ
	MENU_INFO menuInfo;
	menuInfo.align = 1;   //���뷽ʽ����
	menuInfo.space = MENU_SPACE; //�˵���֮��ļ������
	menuInfo.width = btn_width; //�˵����
	menuInfo.height = btn_height; //�˵����
	menuInfo.fontName = L"����"; //�˵�������
	menuInfo.isBold = true; //�Ƿ����
	menuInfo.normalTextColor = normalClr; //����״̬����
	menuInfo.focusTextColor = focusClr;  //ѡ��״̬����
	SetMenuInfo(menuInfo);

	//��ֱ���в�������
	x =(WIN_WIDTH - 412) / 2+ (412 - btn_width)/2 ;
	//y =  10 + i * (btn_height + MENU_SPACE) + (wnd_height - 6* btn_height - 5* MENU_SPACE) / 6;
	y = (WIN_HEIGHT - 483) / 2 + 483 - btn_height ;
	MENUITEM mItem;
	mItem.pos.x = x;
	mItem.pos.y = y;
	mItem.ItemName = menuItems;   //��ǰ�˵�������
	AddMenuItem(mItem);
}

void ChoiceMenu::DrawMenu(HDC hdc, BYTE btnTrans, bool startState,float ratio)
{
	if (&gm_menuBkg != NULL && startState == true)
	{
		gm_menuBkg.PaintImage(hdc, (WIN_WIDTH - gm_menuBkg.GetImageWidth()) / 2, (WIN_HEIGHT - gm_menuBkg.GetImageHeight()) / 2,gm_menuBkg.GetImageWidth(),gm_menuBkg.GetImageHeight(), bkImageAlpha);
	}
	
	int w = menu_info.width;
	int h = menu_info.height;

	float FontHeight;
	int px = 0;
	int w_px = w / (MaxMenuItemLen + 1);	//����ÿ������ռ������
	int h_px = (int)((float)(h / 2.5));
	if (w_px > h_px)
	{
		px = h_px;
	}
	else
	{
		px = w_px;
	}
	FontHeight = ratio*(px * 72) / 96;		//����ÿ���ֵ����ؼ����ֺ�

	if (isItemFocused == FALSE)
	{
		Gdiplus::RectF Rec;
		vector<MENUITEM>::iterator iter;
		for (iter = gm_menuItems.begin(); iter != gm_menuItems.end(); iter++)
		{
			int x = iter->pos.x;
			int y = iter->pos.y;

			// ���ư�ťͼ��
			if (&BtnDIB != NULL)
			{
				BtnDIB.PaintRegion(BtnDIB.GetBmpHandle(), hdc, x, y, 0, 0, w, h, ratio, 0, btnTrans);
			}
			Rec.X = (float)x ;
			Rec.Y = (float)y;
			Rec.Width = (float)w * ratio;
			Rec.Height = (float)h * ratio;

			// ���ư�ť����
			wstring item = iter->ItemName.c_str();
			T_Graph::PaintText(hdc, Rec, item, (REAL)FontHeight, menu_info.fontName,
				menu_info.normalTextColor, GetFontStyle(), GetAlignment());
		}
	}

	if (isItemFocused == TRUE)
	{
		int mIndex = 0;
		Gdiplus::RectF Rec;
		vector<MENUITEM>::iterator iter;
		for (iter = gm_menuItems.begin(); iter != gm_menuItems.end(); iter++)
		{
			int x = iter->pos.x;
			int y = iter->pos.y;

			Rec.X = (float)x ;
			Rec.Y = (float)y;
			Rec.Width = (float)w * ratio;
			Rec.Height = (float)h * ratio;

			if (mIndex != m_index)
			{
				if (&BtnDIB != NULL)
				{
					BtnDIB.PaintRegion(BtnDIB.GetBmpHandle(), hdc, x, y, 0, 0, w, h, ratio, 0, btnTrans);
				}

				wstring item = iter->ItemName.c_str();
				T_Graph::PaintText(hdc, Rec, item, (REAL)FontHeight, menu_info.fontName,
					menu_info.normalTextColor, GetFontStyle(), GetAlignment());
			}

			if (mIndex == m_index)
			{
				if (&BtnDIB != NULL)
				{
					BtnDIB.PaintRegion(BtnDIB.GetBmpHandle(), hdc, x, y, 0, h, w, h, ratio, 0, btnTrans);
				}

				wstring item = iter->ItemName.c_str();
				T_Graph::PaintText(hdc, Rec, item, (REAL)FontHeight, menu_info.fontName,
					menu_info.focusTextColor, GetFontStyle(), GetAlignment());
			}

			mIndex = mIndex + 1;
		}
	}
}

//���ݵ�ǰ����������˵���������
int ChoiceMenu::GetMenuIndex(int x, int y,float ratio)
{
	int Index = -1;
	POINT pt;
	pt.x = x;
	pt.y = y;
	float w = menu_info.width * ratio;
	float h = menu_info.height * ratio;
	RECT rec;

	int iCount = 0;
	vector<MENUITEM>::iterator iter;
	for (iter = gm_menuItems.begin(); iter != gm_menuItems.end(); iter++)
	{
		rec.left = iter->pos.x;
		rec.top = iter->pos.y;
		rec.right = rec.left + w;
		rec.bottom = rec.top + h;

		if (PtInRect(&rec, pt))
		{
			return iCount;
		}
		iCount++;
	}
	return Index;
}
//�˵�������¼�����
int ChoiceMenu::MenuMouseClick(int x, int y,float ratio)
{
	m_index = GetMenuIndex(x, y,ratio);
	if (m_index >= 0)
	{
		if (m_MoveSound && m_ClickSound)
		{
			m_MoveSound->Restore();
			m_ClickSound->Restore();
			m_ClickSound->Play(false);
		}
	}
	return m_index;
}
void ChoiceMenu::MenuMouseMove(int x, int y,float ratio)
{
	lastIndex = m_index;//��¼ǰһ�ε�����ֵ
	m_index = GetMenuIndex(x, y,ratio);
	if (m_index >= 0)
	{
		isItemFocused = true;
		//��֤����ƹ���ťֻ����һ������
		if (lastIndex != m_index)
		{
			if (m_MoveSound && m_ClickSound)
			{
				m_ClickSound->Restore();
				m_MoveSound->Restore();
				m_MoveSound->Play(false);
			}
		}
	}
	else
	{
		isItemFocused = false;
	}
}
