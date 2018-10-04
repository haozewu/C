#include <stdio.h>
int sum(int a, int b)
{
    int c = a+b;
    return c;
}
int main()
{
    int answer, a, b;
    scanf("%d, %d", &a, &b);
    answer = sum(a,b);
    printf("The sum is %d", answer);
    return 0;
}