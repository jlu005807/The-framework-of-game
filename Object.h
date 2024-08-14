#pragma once
#include<iostream>
#include<easyx.h>
#include<vector>

class Atlas;//图集类

//抽象物体类
class Object
{
public:
	//物体状态
	bool is_load;

	int current_content_idx;
	//坐标(左上角
	int x;
	int y;

	//大小
	int m_width;
	int m_height;

	
	//物体运行逻辑

	Object(int width_wid,int height_wid,int x, int y, int width, int height) :x(x), y(y), m_width(width), m_height(height)
	{
	}

	virtual void load_object(const ExMessage& msg) = 0;

};