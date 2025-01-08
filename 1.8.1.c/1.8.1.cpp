#include<iostream>
void Log(const char* message);//函数调用的形式
int main()//main函数可以不写return 0
{
	//std::cout << "Hellow World!" << std::endl;// << 重载运算符（类似于一个函数）//因为它等价于下面的函数（1）
	//将字符串helloworld推送到cout流，然后打印到终端，然后推送一行结束符endl告诉终端跳到下一行
	Log("Hellow world!");//函数调用形式
	std::cin.get();//cin.get函数是等待我们按下enter键
}
//（1）.
//#include <iostream>  
//
//class MyCout {
//public:
//    MyCout& print(const std::string& msg) {
//        std::cout << msg;
//        return *this; // 返回 MyCout 的引用以支持链式调用  
//    }
//
//    MyCout& print(std::ostream& (*manip)(std::ostream&)) {
//        std::cout << manip; // 支持操作符像 std::endl  
//        return *this; // 返回 MyCout 的引用以支持链式调用  
//    }
//};
//
//// 全局对象  
//MyCout cout;
//
//int main() {
//    // 使用自定义的 cout  
//    cout.print("Hello World!").print(std::endl);
//    std::cin.get(); // 等待用户输入，关闭程序前暂停  
//}
////解释/*：
////MyCout 类：定义了一个自定义的 MyCout 类，其中包含一个 print 方法，该方法可以接收字符串和标准流操作符（如 std::endl）。
////链式调用：通过返回* this，可以实现链式调用。*/