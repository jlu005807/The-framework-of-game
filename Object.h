#pragma once
#include<iostream>
#include<easyx.h>
#include<vector>

class Atlas;//ͼ����

//����������
class Object
{
public:
	//����״̬
	bool is_load;

	int current_content_idx;
	//����(���Ͻ�
	int x;
	int y;

	//��С
	int m_width;
	int m_height;

	
	//���������߼�

	Object(int width_wid,int height_wid,int x, int y, int width, int height) :x(x), y(y), m_width(width), m_height(height)
	{
	}

	virtual void load_object(const ExMessage& msg) = 0;

};