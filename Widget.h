#pragma once
#include<iostream>
#include<easyx.h>
#include<vector>

class Object;//�����ࣨ����ӵ�����ť�Ƚ���Ԫ��

class Widget
{
private:

	//����״̬
	int width_widget;
	int height_widget;

	ExMessage m_msg;

	//ҳ��ͼƬ(������
	IMAGE* page;

	//����Ԫ��
	std::vector<Object*> m_objects;

	//��ʼ������
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


	//���������߼�
	void run_widget();//����

	void draw_widget();//ͼ��

	//չʾ����
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
