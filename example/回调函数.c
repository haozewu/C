#include <stdio.h>
//定义回调函数
void PrintfText()
{
    printf("Hello World!\n");
}
//定义实现回调函数的"调用函数"
void CallPrintfText(void (*callfuct)())
{
    callfuct();
}
// 实现函数回调
int main(int argc,char* argv[])
{
    CallPrintfText(PrintfText);
    return 0;
}
