#pragma once
#include<iostream>
#include<vector>
#include<easyx.h>

//图片边缘透明化
void putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

class Widget;//游戏界面


//游戏总框架
class game
{
public:
	
	//游戏属性
	static bool is_running;

	static int current_widget;

	static int widget_num;

	//界面属性
	int width_game;

	int height_game;


	//改变界面
	static void Change_widget(int idx)
	{
		if (idx >= 0 && idx < game::widget_num)game::current_widget = idx;
		else game::current_widget = 0;
	}

	static void Change_running(bool one)
	{
		game::is_running = one;
	}

	//储存界面
	std::vector<Widget*> m_widgets;

	//（构造函数作为初始化）
	game(int width,int height,int widget_num):width_game(width),height_game(height)
	{
		init_game(width,height,widget_num);
	}

	//运行游戏
	void running_game();

	//关闭游戏可以放置在析构函数
	~game()
	{
		close_game();
	}

private:
	//初始化
	void init_game(int width,int height,int widget_num);


	//关闭游戏
	void close_game();


};
