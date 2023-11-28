#include <stdio.h>
#include <stdlib.h>

// 定义链表结构
struct Node
{
    int data;
    struct Node *next;
};

// 初始化链表
struct Node *initList()
{
    return NULL;
}

// 插入元素到指定位置
struct Node *insertElement(struct Node *head, int element, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("内存分配失败，插入元素失败。\n");
        return head;
    }
    newNode->data = element;

    if (position == 0 || head == NULL)
    {
        newNode->next = head;
        return newNode;
    }

    struct Node *current = head;
    int currentPosition = 0;

    while (current != NULL && currentPosition < position - 1)
    {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL)
    {
        printf("插入位置无效。\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// 删除指定位置的元素
struct Node *deleteElement(struct Node *head, int position)
{
    if (position < 0 || head == NULL)
    {
        printf("删除位置无效。\n");
        return head;
    }

    if (position == 0)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *current = head;
    int currentPosition = 0;

    while (current != NULL && currentPosition < position - 1)
    {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || current->next == NULL)
    {
        printf("删除位置无效。\n");
        return head;
    }

    struct Node *temp = current->next;
    current->next = current->next->next;
    free(temp);

    return head;
}

// 打印链表
void printList(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    struct Node *head = initList();

    int n, element;

    printf("请输入链表的元素个数：");
    scanf("%d", &n);

    printf("请输入%d个元素：", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &element);
        head = insertElement(head, element, i); // 在指定位置插入元素
    }

    int choice, position;

    while (1)
    {
        printf("当前链表：");
        printList(head);

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
            head = insertElement(head, element, position); // 在指定位置插入元素
            break;
        case 2:
            printf("请输入要删除的位置: ");
            scanf("%d", &position);
            head = deleteElement(head, position); // 删除指定位置的元素
            break;
        case 3:
            return 0;
        default:
            printf("无效操作编号\n");
        }
    }

    return 0;
}
