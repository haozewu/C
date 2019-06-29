/**
 * 递归算法当输入大于100000时直接溢出+统计程序执行时间
 */
#include <stdio.h>
#include <time.h>

#define RUNTIME 1e7
clock_t start, stop;
double duration;

void printn(int n);
int main()
{
    int n;
    printf("%d\n", CLK_TCK);
    scanf("%d", &n);
    start = clock();
    for (int i = 0; i < RUNTIME; i++)
    {
        printn(n);
    }
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;
    printf("%f\n", duration);
    return 0;
}
void printn(int n)
{
    if (n)
    {
        printn(n - 1);
        printf("%d\n", n);
    }
}
