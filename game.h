#pragma once
#include<iostream>
#include<vector>
#include<easyx.h>

//ͼƬ��Ե͸����
void putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

class Widget;//��Ϸ����


//��Ϸ�ܿ��
class game
{
public:
	
	//��Ϸ����
	static bool is_running;

	static int current_widget;

	static int widget_num;

	//��������
	int width_game;

	int height_game;


	//�ı����
	static void Change_widget(int idx)
	{
		if (idx >= 0 && idx < game::widget_num)game::current_widget = idx;
		else game::current_widget = 0;
	}

	static void Change_running(bool one)
	{
		game::is_running = one;
	}

	//�������
	std::vector<Widget*> m_widgets;

	//�����캯����Ϊ��ʼ����
	game(int width,int height,int widget_num):width_game(width),height_game(height)
	{
		init_game(width,height,widget_num);
	}

	//������Ϸ
	void running_game();

	//�ر���Ϸ���Է�������������
	~game()
	{
		close_game();
	}

private:
	//��ʼ��
	void init_game(int width,int height,int widget_num);


	//�ر���Ϸ
	void close_game();


};
