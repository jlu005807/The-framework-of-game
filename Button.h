#pragma once
#include"Object.h"
#include <functional>
#include <string>
#include<map>
#include<climits>


class Button : public Object
{
private:

	float scale;//���ű���
	std::function<void()> onClick;//�����ť��������

	enum class Status
	{
		Idle=0,
		Hovered,
		Pushed
	};

    std::map<Status,IMAGE*> img;
	//״̬
	Status status = Status::Idle;

public:
	Button(int x,int y,int width,int height,const std::function<void()>& onClick,std::vector<IMAGE*>contents):Object(x,y,width,height),onClick(onClick)
	{
		for (int i = 0; i < contents.size(); i++)
		{
			img[Status(i)] = contents[i];
		}
	}

	void Draw_button()
	{

		int scaledWidth = m_width * scale; // ���ź�İ�ť���
		int scaledHeight = m_height * scale; // ���ź�İ�ť�߶�
		int scaledX = x + abs((m_width - scaledWidth) / 2); // ���ź�İ�ťx����
		int scaledY = y + abs((m_height - scaledHeight) / 2); // ���ź�İ�ťy����

		putimage(x, y, img[status]);
	}

	// �������Ƿ��ڰ�ť�Ϸ�
	bool CheckCursorHit(int mouse_x, int mouse_y)
	{
		return mouse_x >= x && mouse_x <= x + m_width && mouse_y >= y && mouse_y <= y + m_height;
	}

	void ProcessEvent(const ExMessage& msg)
	{
		switch (msg.message)
		{
		case WM_MOUSEMOVE: {
			if (status == Status::Idle && CheckCursorHit(msg.x, msg.y))
			{
				status = Status::Hovered;
				scale = 1.1f;
			}
			else if (status == Status::Hovered && !CheckCursorHit(msg.x, msg.y))
			{
				status = Status::Idle;
				scale = 1.0f;
			}
			break;
		}
		case WM_LBUTTONDOWN:{
			if (CheckCursorHit(msg.x, msg.y))
			{
				status = Status::Pushed;
				scale = 0.9f;
			}
			break;
		}
		case WM_LBUTTONUP: {
			if (status == Status::Pushed)
				onClick();
			break;
		}
		default:
			break;
		}
	}

	void load_pbject(const ExMessage& msg)
	{
		ProcessEvent(msg);

		Draw_button();
	}


};