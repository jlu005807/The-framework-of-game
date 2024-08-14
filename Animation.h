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

//图集
class Atlas
{
public:
	Atlas(LPCTSTR path, int num)
	{
		TCHAR path_file[256];
		for (int i = 0; i < num; i++)
		{
			_stprintf_s(path_file, path, 1);

			IMAGE* frame = new IMAGE();

			loadimage(frame, path_file);

			frame_list.push_back(frame);

		}
	}

	~Atlas()
	{
		for (int i = 1; i < frame_list.size(); i++)
			delete frame_list[i];
	}

	std::vector<IMAGE*> frame_list;
};

class Animation
{
private:
	int interval_ms = 0;//动画帧间隔
	int idx_frame = 0;//动画帧索引
	int timer = 0;//动画计时器
	Atlas* anim_atlas;

public:

	Animation(LPCTSTR path, int num, int interval, Atlas* atlas) :interval_ms(interval)
	{
		anim_atlas = atlas;
	}

	~Animation() = default;


	void Play(int x, int y, int delta)
	{
		timer += delta;

		if (timer >= interval_ms)
		{
			idx_frame = (idx_frame + 1) % anim_atlas->frame_list.size();
			timer = 0;
		}

		putimage_alpha(x, y, anim_atlas->frame_list[idx_frame]);
	}
};