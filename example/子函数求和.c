#include <stdio.h>
int sum(int a, int b)
{
    int c = a+b;
    return c;
}
int main()
{
    int answer, a, b;
    printf("Please type tow number, divided by \',\'\n");
    scanf("%d, %d", &a, &b);
    answer = sum(a,b);
    printf("The sum is %d", answer);
    return 0;
}