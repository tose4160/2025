#include "Application.h"

static Application* global_app = nullptr;//初始化为空指针//定义全局静态变量

//对应的程序部分

Application::Application()
{

	if (!global_app)
	{
		global_app = this;
	}
	//创建游戏窗口
	initgraph(1080,640);
	this->is_running = true;//表示程序正在运行
}

Application* Application::instance()
{
	return global_app;
}

int Application::run()
{
	float fps = 1000 / 120.0;//设置帧率//后面有SLEEP操作以调节帧率
	DWORD startTick = 0;//开始时间
	//游戏主循环
	while (this->is_running)
	{
		//获取系统时间，精度毫秒
		startTick=GetTickCount();
		//处理消息(调动成员函数）
		handleMsg();
		//开启双缓冲绘图（为了防止游戏出现卡顿）
		BeginBatchDraw();
		if (this->scene)
			this->scene->draw();
		//关闭双缓冲
		EndBatchDraw();//开启双缓冲绘图之后，所有图像会先绘制到内存里面，但是内存不会马上刷新到界面上，所以想要看得到画面，就需要调用关闭双缓冲，这样才能看到画面。
		//游戏数据的更新
		if (this->scene)
			this->scene->updata();
		auto diff = GetTickCount() - startTick;//获取时间差
		if (fps > diff)
		{
			Sleep(fps - diff);
		}
		//清除旧的消息
		msg = { 0 };
	}
	return 0;
}
//解析
//float fps = 1000 / 120.0; :
//
//设置每帧的时间间隔，目标帧率为 120 FPS（每秒 120 帧）。计算结果为每帧约 8.33 毫秒（1000 毫秒 / 120）。
//DWORD startTick = 0; :
//
//	声明一个变量 startTick，用于存储当前时间的毫秒数，类型为 DWORD（无符号长整型）。
//	while (true) :
//
//		开始一个无限循环，这是游戏的主循环，持续运行直到程序结束。
//		startTick = GetTickCount(); :
//
//		获取当前系统时间（以毫秒为单位），并存储在 startTick 中。GetTickCount() 是 Windows API 函数，用于获取系统启动以来的时间。
//		handleMsg(); :
//
//		调用 handleMsg 方法，处理系统消息（如输入事件、窗口消息等）。这个方法通常是应用程序的消息循环的一部分。
//		BeginBatchDraw(); :
//
//		开始双缓冲绘图，以减少画面卡顿现象。双缓冲技术通过在内存中绘制图像，然后一次性将其显示到屏幕上，从而提高渲染效率。
//		if (this->scene) this->scene->draw(); :
//
//			如果当前场景存在，调用该场景的 draw 方法进行绘制。this->scene 指向当前运行的场景对象。
//			EndBatchDraw(); :
//
//			结束双缓冲绘图，将内存中的图像刷新到屏幕上，使用户能够看到更新后的画面。
//			if (this->scene) this->scene->updata(); :
//
//				如果当前场景存在，调用该场景的 updata 方法更新游戏状态（如角色位置、物体状态等）。这里可能是个拼写错误，应该是 update。
//				auto diff = GetTickCount() - startTick; :
//
//				计算当前帧的执行时间（毫秒），即从开始到现在的时间差。
//				if (fps > diff) { Sleep(fps - diff); } :
//
//					如果当前帧的执行时间小于目标帧时间（fps），则调用 Sleep 函数使当前线程休眠，确保游戏的帧率稳定。Sleep 的参数是剩余的时间，以确保每帧的时间间隔达到设定值。
//					msg = { 0 }; :
//
//					清除旧的消息，通常是将消息结构体重置为零，以便为下一次处理准备。
//					return 0; :
//
//					退出循环后，返回 0（虽然在这个无限循环中实际上不会执行到这一行）
void Application::handleMsg()
{
	if (peekmessage(&msg))
	{
		if (msg.message == WM_KEYDOWN && msg.vkcode == VK_ESCAPE)
		{
			quit();
		}
	}//判断是否按下ESC键
}

void Application::quit()
{
	this->is_running = false;
}
//场景的设置
void Application::runScene(GoldMinerScene* scene)
{
	if (scene)//检查传入的 scene 指针是否为非空
	{
		this->scene = scene;
		this->scene->init();
	}
}
