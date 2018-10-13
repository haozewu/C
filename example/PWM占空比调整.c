#include <windows.h>
#include <stdio.h>
int main()
{
    int onetime = 1000;//how long 1 have
    int flag = 0;
    while(1)
    {
        printf("%d\n", 1);
        if(onetime == 10000)
            flag = 1;
        if(onetime == 1000)
            flag = 0;
        Sleep(onetime);
        printf("%d\n", 0);
        Sleep(10000 - onetime);
        if(flag == 1)
            onetime -= 1000;
        else
            onetime += 1000;
    }
    return 0;
}