#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main()
{
	char arr1[6];
	scanf("%s", &arr1);
	char arr2[7];
	for (int n=5; n >= 0; n--)
	{
		arr2[n] = arr1[5 - n];
	}
    arr2[6] = '\0';
	printf("%s", arr2);
	return 0;
}
