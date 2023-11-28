#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// 定义顺序栈结构
struct Stack
{
    int top;
    int data[MAX_STACK_SIZE];
};

// 初始化栈
void initStack(struct Stack *stack)
{
    stack->top = -1;
}

// 判断栈是否为空
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(struct Stack *stack)
{
    return stack->top == MAX_STACK_SIZE - 1;
}

// 入栈
void push(struct Stack *stack, int value)
{
    if (!isFull(stack))
    {
        stack->data[++stack->top] = value;
    }
    else
    {
        printf("栈已满，无法入栈\n");
    }
}

// 出栈
int pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->data[stack->top--];
    }
    else
    {
        printf("栈已空，无法出栈\n");
        return -1; // 表示出错
    }
}

// 十进制转二进制
void decimalToBinary(int decimal)
{
    struct Stack stack;
    initStack(&stack);

    while (decimal > 0)
    {
        int remainder = decimal % 2;
        push(&stack, remainder);
        decimal /= 2;
    }

    printf("二进制表示：");
    while (!isEmpty(&stack))
    {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main()
{
    int decimal;
    printf("请输入一个十进制数：");
    scanf("%d", &decimal);

    if (decimal < 0)
    {
        printf("请输入一个非负整数。\n");
    }
    else
    {
        decimalToBinary(decimal);
    }
    system("pause");
    return 0;
}