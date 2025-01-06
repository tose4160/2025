#pragma once//用来标识程序
#include<easyx.h>
#define App Application::instance();
class Scene;//前向声明
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
	void runScene(Scene* scene);
	//获取消息


private://这是另一个访问修饰符，指定下面的成员只能被该类的内部函数访问，而不能被外部直接访问。这通常用于封装类的内部数据，以防外部直接操作。
	ExMessage msg;//之后会把鼠标、按键之类的东西都保存在里面
	bool is_running;//用来标识程序是否在运行，最开始是false
	Scene* scene;//通过这个类保存为成员函数（不太懂是什么意思）
};

//用于鼠标点击，键盘按下，游戏场景的绘制
//类（Class）：
//
//类是一种用户定义的数据类型，包含属性和方法。
//可以理解为一个模板，用于创建对象。
//对象（Object）：
//
//对象是类的实例。每个对象可以拥有类定义的属性和方法，它们的状态可能不同。
//属性（Attributes）：
//
//属性是类中定义的变量，代表对象的特征。例如，一个 Car 类可以有 color 和 model 属性。
//方法（Methods）：
//
//方法是类中定义的函数，表示对象的行为。例如，Car 类可以有一个 drive 方法，用于描述如何驾驶汽车。
//*****************************
// 举例：
//#include <iostream>  
//#include <string>  
//
//class Car {
//public:
//    // 属性  
//    std::string make;
//    std::string model;
//    std::string color;
//
//    // 构造函数  
//    Car(std::string m, std::string mod, std::string c) {
//        make = m;
//        model = mod;
//        color = c;
//    }
//
//    // 方法  
//    void drive() {
//        std::cout << "The " << color << " " << make << " " << model << " is driving." << std::endl;
//    }
//};
//
//int main() {
//    // 创建对象  
//    Car myCar("Toyota", "Corolla", "red");
//
//    // 调用方法  
//    myCar.drive();  // 输出: The red Toyota Corolla is driving.  
//
//    return 0;
//}
//解析示例
//类定义：
//
//class Car 是我们定义的类，里边包含了属性和方法。
//    属性：
//
//    make、model 和 color 是类的成员变量，用于存储汽车的品牌、型号和颜色。
//    构造函数：
//
//    Car(std::string m, std::string mod, std::string c) 是一个构造函数，在创建对象时初始化属性。
//    方法：
//
//    void drive() 是一个公共方法，打印汽车的状态。
//    创建对象并使用方法：
//
//    在 main 函数中，我们创建了一个 Car 对象 myCar，并调用其 drive 方法。