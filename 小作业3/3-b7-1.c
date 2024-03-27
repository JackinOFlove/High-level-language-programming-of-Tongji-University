/*2253744 林觉凯 软工*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
    printf("请输入找零值：\n");
    double a;
    scanf("%lf", &a);
    double n;
    int f, i, f1, f2;
    f = rint(modf(a, &n) * 100);
    i = (int)fmod(a, 1000000000.0);
    f1 = f / 10;
    f1 = (int)fmin(9, f1);
    f2 = f - f1 * 10;
    f2 = (int)fmin(9, f2);

    int sum = 0;
    int number = 0;
    int change = i;
    int num_50, num_20, num_10, num_5, num_1, num_j5, num_j1, num_f5, num_f2, num_f1;

    num_50 = change / 50;
    number += num_50;
    change -= num_50 * 50;

    num_20 = change / 20;
    number += num_20;
    change -= num_20 * 20;

    num_10 = change / 10;
    number += num_10;
    change -= num_10 * 10;

    num_5 = change / 5;
    number += num_5;
    change -= num_5 * 5;

    num_1 = change / 1;
    number += num_1;
    change -= num_1 * 1;

    change = f1 * 10 + f2;

    num_j5 = change / 50;
    number += num_j5;
    change -= num_j5 * 50;

    num_j1 = change / 10;
    number += num_j1;
    change -= num_j1 * 10;

    num_f5 = change / 5;
    number += num_f5;
    change -= num_f5 * 5;

    num_f2 = change / 2;
    number += num_f2;
    change -= num_f2 * 2;

    num_f1 = change / 1;
    number += num_f1;
    change -= num_f1 * 1;

    printf("共%d张找零，具体如下：\n", number);
    if (num_50 != 0)
        printf("%-5s: %d张\n", "50元", num_50);
    if (num_20 != 0)
        printf("%-5s: %d张\n", "20元", num_20);
    if (num_10 != 0)
        printf("%-5s: %d张\n", "10元", num_10);
    if (num_5 != 0)
        printf("%-5s: %d张\n", "5元", num_5);
    if (num_1 != 0)
        printf("%-5s: %d张\n", "1元", num_1);
    if (num_j5 != 0)
        printf("%-5s: %d张\n", "5角", num_j5);
    if (num_j1 != 0)
        printf("%-5s: %d张\n", "1角", num_j1);
    if (num_f5 != 0)
        printf("%-5s: %d张\n", "5分", num_f5);
    if (num_f2 != 0)
        printf("%-5s: %d张\n", "2分", num_f2);
    if (num_f1 != 0)
        printf("%-5s: %d张\n", "1分", num_f1);

    return 0;
}