/**
 * 实现一个单链表
 */
#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 10
typedef int ElementType;

typedef struct LNode *List;
struct LNode
{
    ElementType Data; //[MAXSIZE];
    List Next;
};
List FindKth(int K, List Ptrl)
{
    List p = Ptrl;
    int i = 1;
    while (p != NULL && i < K)
    {
        p = p->Next;
        i++;
    }
    if (i == K)
        return p;
    else
    {
        return NULL;
    }
}
List Insert(ElementType X, int i, List Ptrl)
{
    List p, s;
    if (i == 1)
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = NULL;
        return s;
    }
    p = FindKth(i - 1, Ptrl);
    if (p == NULL)
    {
        printf("param error\n");
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return Ptrl;
    }
}
List Delete(int i, List Ptrl)
{
    List p, s;
    if (i == 1)
    {
        s = Ptrl;
        if (Ptrl != NULL)
            Ptrl = Ptrl->Next;
        else
            return NULL;
        free(s);
        return Ptrl;
    }
    p = FindKth(i - 1, Ptrl);
    if (p == NULL)
    {
        printf("the %d node do not exist!\n", i - 1);
        return NULL;
    }
    else if (p->Next == NULL)
    {
        printf("the %d node don't exist!", i);
        return NULL;
    }
    else
    {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return Ptrl;
    }
}
int Length(List Ptrl)
{
    List p = Ptrl;
    int j = 0;
    while (p)
    {
        p = p->Next;
        j++;
    }
    return j;
}
int main(int argc, char const *argv[])
{
    int data, i = 0;
    List Ptrl;
    do
    {
        scanf("%d", &data);
        Ptrl = Insert(data, ++i, Ptrl);
    } while (getchar() != '\n');
    printf("%d", Length(Ptrl));
    Delete(4, Ptrl);
    return 0;
}
