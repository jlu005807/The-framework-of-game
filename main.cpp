#include"game.h"
#include"Widget.h"
#include"Object.h"
#include"Button.h"

//完善函数

//游戏初始化
void game::init_game(int width, int height,int widget_num)
{
	game::current_widget = 0;
	game::widget_num = widget_num;
	game::is_running = true;

	for (int i = 0; i < widget_num; i++)
	{
		std::vector<Object*> widget_obj;
		//加载物体


		//
		Widget* one = new Widget(width, height, widget_obj);
		m_widgets.push_back(one);
	}
};


//界面初始化
void Widget::init_widget(int Width, int height, std::vector<Object*> objects)
{
	for (int i = 0; i < objects.size(); i++)
		m_objects.push_back(objects[i]);
}


void game::running_game()
{
	while(is_running)
	{
		m_widgets[current_widget]->show_widget();
	}

	EndBatchDraw();
}

void Widget::run_widget()
{
	while (peekmessage(&m_msg))
	{
		for (int i = 0; i < m_objects.size(); i++)
			m_objects[i]->load_object(m_msg);
	}
}

void Widget::draw_widget()
{
	cleardevice();
	putimage(0, 0, page);
	FlushBatchDraw();
}





int main()
{
	int widget = 4;
	game my_game(640, 640,4);
	my_game.running_game();

	return 0;

}