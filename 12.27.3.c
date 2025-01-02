////在C语言中，创建一个二进制文件并向其写入一个整数
//
//#include <stdio.h>  
//
//int main() {
//    // 要写入的整数  
//    int number = 42;
//
//    // 创建并打开一个二进制文件  
//    FILE* file = fopen("D:\\test","wb");
//    if (file == NULL) {
//        perror("无法打开文件");
//        return 1; // 返回非零值表示错误  
//    }
//
//    // 写入整数到文件  
//    fwrite(&number, sizeof(int), 1, file);
//
//    // 关闭文件  
//    fclose(file);
//
//    printf("整数 %d 已写入二进制文件 output.bin\n", number);
//    return 0; // 返回零表示成功  
//}
////写入后会发现会是一个*，实际上是一段乱码，文本文件不能存储二进制文件，但是用Ultra转换成十六进制文件就可以算出这个是对的
////代码解释：
////头文件：
////
////#include <stdio.h>：引入标准输入输出库。
////主函数：
////
////int main()：程序入口函数。
////定义整数：
////
////int number = 42; ：定义要写入的整数。
////打开文件：
////
////FILE* file = fopen("output.bin", "wb"); ：以二进制写入模式打开或创建一个名为output.bin的文件。
////检查文件是否打开成功：如果file为NULL，则打印错误信息。
////写入数据：
////
////fwrite(&number, sizeof(int), 1, file); ：将整数number以二进制格式写入文件。
////第一个参数是数据的指针，第二个参数是每个元素的大小（这里是int的大小），第三个参数是要写入的元素数量（这里是1个）。
////关闭文件：
////
////fclose(file); ：关闭文件以确保数据写入完成并释放资源。
////程序结束：
////
////return 0; ：返回零表示程序成功执行。
//**********************************************
//注意：一个特殊的知识点：看下面的结构体它的内存应该是4+4+50=58，可是在实际中你就会发现它占用的空间是60，因为里面存在着一种默认对其的情况如果不是4的倍数这里会补充变成4的倍数
#include <stdio.h>  
#include <stdlib.h>  
//这里又有一个区分（25行），操作会发现用文本解读下面的name可以正确的解读，原因是字符串本身就是ascii值转换过来的。
typedef struct {
    int id;//4
    float salary;//4
    char name[50];//50
} Employee;

int main() {
    // 创建一个结构体实例  
    Employee emp1 = { 1, 50000.50, "John Doe" };

    // 创建并打开一个二进制文件用于写入  
    FILE* file = fopen("employee.dat", "wb");
    if (file == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    // 将结构体写入二进制文件  
    size_t result = fwrite(&emp1, sizeof(Employee), 1, file);
    if (result != 1) {
        perror("Error writing to file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // 关闭文件  
    fclose(file);

    printf("Structure written to binary file successfully.\n");
    return EXIT_SUCCESS;
}
//代码解释
//定义结构体：这个例子定义了一个Employee结构体，包含ID、薪水和姓名的字段。
//
//创建文件：使用fopen函数以二进制写入方式打开文件employee.dat。如果文件无法打开，程序将打印错误信息并退出。
//
//写入结构体：使用fwrite函数将结构体实例emp1写入打开的文件。fwrite的参数包括结构体地址、结构体大小和要写入的数量。
//
//关闭文件：使用fclose函数关闭文件，确保数据写入完成