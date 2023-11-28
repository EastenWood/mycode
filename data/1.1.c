#include <stdio.h>

#define MAX_SIZE 100

// 定义顺序表结构
struct SeqList
{
    int data[MAX_SIZE];
    int length;
};

// 初始化顺序表
void initList(struct SeqList *list)
{
    list->length = 0;
}

// 插入元素到指定位置
int insertElement(struct SeqList *list, int element, int position)
{
    if (list->length >= MAX_SIZE)
    {
        printf("顺序表已满，无法插入元素。\n");
        return -1;
    }

    if (position < 0 || position > list->length)
    {
        printf("插入位置无效。\n");
        return -1;
    }

    for (int i = list->length; i > position; i--)
    {
        list->data[i] = list->data[i - 1];
    }

    list->data[position] = element;
    list->length++;

    return 0;
}

// 删除指定位置的元素
int deleteElement(struct SeqList *list, int position)
{
    if (position < 0 || position >= list->length)
    {
        printf("删除位置无效。\n");
        return -1;
    }

    for (int i = position; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }

    list->length--;

    return 0;
}

int main()
{
    struct SeqList list;
    initList(&list);

    int n, element;

    printf("请输入顺序表的元素个数：");
    scanf("%d", &n);

    printf("请输入%d个元素：", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &element);
        list.data[i] = element;
        list.length++;
    }

    int choice, position;

    while (1)
    {
        printf("当前顺序表：");
        for (int i = 0; i < list.length; i++)
        {
            printf("%d ", list.data[i]);
        }
        printf("\n");

        printf("选择操作:\n");
        printf("1. 插入元素\n");
        printf("2. 删除元素\n");
        printf("3. 退出\n");

        printf("请输入操作编号: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("请输入要插入的元素: ");
            scanf("%d", &element);
            printf("请输入要插入的位置: ");
            scanf("%d", &position);
            insertElement(&list, element, position);
            break;
        case 2:
            printf("请输入要删除的位置: ");
            scanf("%d", &position);
            deleteElement(&list, position);
            break;
        case 3:
            return 0;
        default:
            printf("无效操作编号\n");
        }
    }
    return 0;
}
