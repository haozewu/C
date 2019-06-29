/**
 * 最大子列和问题
 */
#include <stdio.h>

int max_given2(int matrix[], int k);
void max_given4(int matrix[], int k, int min);

int main(int argc, char const *argv[])
{
    int k;
    scanf("%d", &k);
    int matrix[100100]; // = {-2, -3, 0, -1, -5};
    /**
     * scanf函数输入时，自动以空格作为分隔符，不会读入空格。在scanf函数输入数据时，不需要考虑空白类字符的存在(空格，跳格，换行)。
     */
    int i = 0;
    int min = 0;
    while (scanf("%d", &matrix[i]) != EOF && getchar() != '\n')
    {
        if (matrix[i] < 0)
        {
            min = min + matrix[i];
        }
        i++;
    }

    // printf("%d", max_given2(matrix, k));
    max_given4(matrix, k, min);
    return 0;
}
/**
 * algorithms 2
 * Algorithmic complexity: N^2
 */
int max_given2(int matrix[], int k)
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
/**
 * algorithms 4: 在线处理并给出首尾
 * Algorithmic complexity: N
 * 此时如果有负数和0，三个输出全部都是0
 */
void max_given4(int matrix[], int k, int min)
{
    int max_res = min, this_res = 0, first = 0, last = 0;
    int flag = 0;
    for (int i = 0; i < k; i++)
    {
        this_res += matrix[i];
        if (this_res < 0)
        {
            this_res = 0;
            flag = i + 1;
        }
        else if (this_res > max_res)
        {
            last = i;
            first = flag;
            max_res = this_res;
        }
    }
    if (max_res < 0)
    {
        printf("%d %d %d\n", 0, matrix[0], matrix[k - 1]);
    }
    else
        printf("%d %d %d\n", max_res, matrix[first], matrix[last]);
}