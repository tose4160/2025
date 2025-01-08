//求2/3、4/5、6/9、10/15、16/25……数列前n项之和。其中，n<=100.
//
//注意：设置为float或double类型计算，避免整除运算结果取整情况。
//#include <stdio.h>  
//
//int main() {
//    int n;
//    double sum = 0.0;
//
//    printf("请输入n的值（n <= 100）: ");
//    scanf_s("%d", &n);
//
//    if (n > 100) {
//        printf("n的值不能超过100。\n");
//        return 1;
//    }
//
//    for (int i = 1; i <= n; i++) {
//        double numerator = i * (i + 1); // 分子为 i * (i + 1)  
//        double denominator = i * (i + 2); // 分母为 i * (i + 2)  
//        sum += numerator / denominator; // 计算分数并累加到sum  
//    }
//
//    printf("%.4f\n", sum); // 按照指定格式输出结果  
//
//    return 0;
//}
#include <stdio.h>  

int main() {
    int alcohol_levels[10];
    int i;
    int count = 0;

    // 输入驾驶员酒精含量  
    for (i = 0; i < 10; i++) {
        scanf_s("%d", &alcohol_levels[i]);
    }

    // 判断酒驾和醉驾人数  
    for (i = 0; i < 10; i++) {
        if (alcohol_levels[i] >= 20) {
            count++;
        }
    }

    // 计算总人数和比例  
    int sum = count;
    int ratio = (sum * 100) / 10;

    // 输出结果  
    printf("sum=%d,ratio=%d%%\n", sum, ratio);
}
