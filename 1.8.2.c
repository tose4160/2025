//��2/3��4/5��6/9��10/15��16/25��������ǰn��֮�͡����У�n<=100.
//
//ע�⣺����Ϊfloat��double���ͼ��㣬��������������ȡ�������
//#include <stdio.h>  
//
//int main() {
//    int n;
//    double sum = 0.0;
//
//    printf("������n��ֵ��n <= 100��: ");
//    scanf_s("%d", &n);
//
//    if (n > 100) {
//        printf("n��ֵ���ܳ���100��\n");
//        return 1;
//    }
//
//    for (int i = 1; i <= n; i++) {
//        double numerator = i * (i + 1); // ����Ϊ i * (i + 1)  
//        double denominator = i * (i + 2); // ��ĸΪ i * (i + 2)  
//        sum += numerator / denominator; // ����������ۼӵ�sum  
//    }
//
//    printf("%.4f\n", sum); // ����ָ����ʽ������  
//
//    return 0;
//}
#include <stdio.h>  

int main() {
    int alcohol_levels[10];
    int i;
    int count = 0;

    // �����ʻԱ�ƾ�����  
    for (i = 0; i < 10; i++) {
        scanf_s("%d", &alcohol_levels[i]);
    }

    // �жϾƼݺ��������  
    for (i = 0; i < 10; i++) {
        if (alcohol_levels[i] >= 20) {
            count++;
        }
    }

    // �����������ͱ���  
    int sum = count;
    int ratio = (sum * 100) / 10;

    // ������  
    printf("sum=%d,ratio=%d%%\n", sum, ratio);
}
