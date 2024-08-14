#pragma once
#include<iostream>
#include<easyx.h>
#include<vector>

class Object;//物体类（人物，子弹，按钮等界面元素

class Widget
{
private:

	//界面状态
	int width_widget;
	int height_widget;

	ExMessage m_msg;

	//页面图片(背景）
	IMAGE* page;

	//界面元素
	std::vector<Object*> m_objects;

	//初始化界面
	void init_widget(int Width,int height,std::vector<Object*> objects);

	void close_widget();

public:

	Widget(int width,int height, std::vector<Object*> objects):width_widget(width),height_widget(height)
	{
		init_widget(width,height,objects);
	}


	~Widget()
	{
		close_widget();
	}


	//界面运行逻辑
	void run_widget();//数据

	void draw_widget();//图形

	//展示界面
	void show_widget()
	{		
			DWORD start_time = GetTickCount();

			BeginBatchDraw();

			run_widget();

			draw_widget();

			DWORD end_time = GetTickCount();
			DWORD gap_time = end_time - start_time;

			if (gap_time < 1000 / 60)
				Sleep(1000 / 60 - gap_time);
	}

};
