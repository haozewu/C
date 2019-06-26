/**
 * 最大子列和问题
 */
#include <stdio.h>
int max_given(int matrix[], int k);
int main(int argc, char const *argv[])
{
    int k;
    scanf("%d", &k);
    int matrix[100000];
    /**
     * scanf函数输入时，自动以空格作为分隔符，不会读入空格。在scanf函数输入数据时，不需要考虑空白类字符的存在(空格，跳格，换行)。
     */
    int i = 0;
    while (scanf("%d", &matrix[i]) != EOF && getchar() != '\n')
        i++;
    printf("%d", max_given(matrix, k));
    return 0;
}
int max_given(int matrix[], int k)
{
    int max_res = 0, this_res = 0;
    for (int i = 0; i < k; i++)
    {
        this_res = 0;
        for (int j = i; j < k; j++)
        {
            this_res += matrix[j];
            if (this_res > max_res)
            {
                max_res = this_res;
            }
        }
    }
    return max_res > 0 ? max_res : 0;
}
