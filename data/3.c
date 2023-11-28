#include <stdio.h>
#include <stdlib.h>

// 二叉树结点定义
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 栈结点定义
struct StackNode
{
    struct TreeNode *node;
    struct StackNode *next;
};

// 创建一个新的栈结点
struct StackNode *createStackNode(struct TreeNode *node)
{
    struct StackNode *stackNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = NULL;
    return stackNode;
}

// 压栈
void push(struct StackNode **top, struct TreeNode *node)
{
    struct StackNode *stackNode = createStackNode(node);
    stackNode->next = *top;
    *top = stackNode;
}

// 弹栈
struct TreeNode *pop(struct StackNode **top)
{
    if (*top == NULL)
    {
        return NULL;
    }
    struct StackNode *temp = *top;
    *top = (*top)->next;
    struct TreeNode *popped = temp->node;
    free(temp);
    return popped;
}

// 先序建立二叉树
struct TreeNode *buildTree()
{
    int data;
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = buildTree();
    newNode->right = buildTree();
    return newNode;
}

// 非递归中序遍历二叉树
void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    struct StackNode *stack = NULL;
    struct TreeNode *current = root;

    while (current != NULL || stack != NULL)
    {
        while (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

int main()
{
    // printf("请输入先序遍历序列，-1表示空节点，以空格分隔：\n");
    struct TreeNode *root = buildTree();
    printf("中序遍历结果：\n");
    inorderTraversal(root);
    printf("\n");
    system("pause");
    return 0;
}