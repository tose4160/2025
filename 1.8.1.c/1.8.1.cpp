#include<iostream>
void Log(const char* message);//�������õ���ʽ
int main()//main�������Բ�дreturn 0
{
	//std::cout << "Hellow World!" << std::endl;// << �����������������һ��������//��Ϊ���ȼ�������ĺ�����1��
	//���ַ���helloworld���͵�cout����Ȼ���ӡ���նˣ�Ȼ������һ�н�����endl�����ն�������һ��
	Log("Hellow world!");//����������ʽ
	std::cin.get();//cin.get�����ǵȴ����ǰ���enter��
}
//��1��.
//#include <iostream>  
//
//class MyCout {
//public:
//    MyCout& print(const std::string& msg) {
//        std::cout << msg;
//        return *this; // ���� MyCout ��������֧����ʽ����  
//    }
//
//    MyCout& print(std::ostream& (*manip)(std::ostream&)) {
//        std::cout << manip; // ֧�ֲ������� std::endl  
//        return *this; // ���� MyCout ��������֧����ʽ����  
//    }
//};
//
//// ȫ�ֶ���  
//MyCout cout;
//
//int main() {
//    // ʹ���Զ���� cout  
//    cout.print("Hello World!").print(std::endl);
//    std::cin.get(); // �ȴ��û����룬�رճ���ǰ��ͣ  
//}
////����/*��
////MyCout �ࣺ������һ���Զ���� MyCout �࣬���а���һ�� print �������÷������Խ����ַ����ͱ�׼������������ std::endl����
////��ʽ���ã�ͨ������* this������ʵ����ʽ���á�*/