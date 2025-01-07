#pragma once//用来标识程序
#include<easyx.h>
#define App Application::instance();
class GoldMinerScene;//前向声明
class Application//这个类的意义就是划分区域
{
public://public：这是一个访问修饰符，它指定下面的成员可以被类的外部访问。也就是说，public 成员可以被创建该类的对象或者其他类直接访问。
	Application();//这是构造函数的声明。构造函数是一个特殊类型的成员函数，当创建类的对象时自动调用。
//ALT加回车创建声明定义            //构造函数的名称与类名相同，通常用于初始化对象的状态。如果没有定义，C++ 会自动生成一个默认构造函数。
public://关键字用于让类的成员对外部可访问，是实现类与外部环境交互的重要部分
	static Application* instance();
public:
	//运行程序
	int run();
	//消息处理
	void handleMsg();
	//程序退出
	void quit();
	//运行场景(需要传入一个场景，场景单独划分一个类）
	void runScene(GoldMinerScene* scene);
	//获取消息


private://这是另一个访问修饰符，指定下面的成员只能被该类的内部函数访问，而不能被外部直接访问。这通常用于封装类的内部数据，以防外部直接操作。
	ExMessage msg;//之后会把鼠标、按键之类的东西都保存在里面
	bool is_running;//用来标识程序是否在运行，最开始是false
	GoldMinerScene* scene;//通过这个类保存为成员函数（不太懂是什么意思）
};
