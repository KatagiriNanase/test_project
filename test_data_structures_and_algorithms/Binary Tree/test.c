#include <stdio.h>
#include <stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

//前序遍历
void PreOrder(BTNode* root)
{
    if (!root)
    {
        printf("NULL ");
        return;
    }
    printf("%c ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

//中序遍历--左 根 右
void InOrder(BTNode* left)
{
    if (!left)
    {
        printf("NULL ");
        return;
    }
    InOrder(left->left);
    printf("%c ", left->data);
    InOrder(left->right);

}
//后序遍历
void PostOrder(BTNode* root)
{
    if (!root)
    {
        printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->data);

}

//获取二叉树节点数
int BiTreeSize(BTNode* root)
{
    if (!root)
        return 0;
    // if (!root->left || !root->right)
    //     return 1;
    return BiTreeSize(root->left) + BiTreeSize(root->right) + 1;
}

//获取叶子结点
int TreeLeafSize(BTNode* root)
{
    if (!root)//空树有啥叶子节点？
        return 0;
    if (!root->left && !root->right)
        return 1;
    return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//获取二叉树深度
int BiTreeDepth(BTNode* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return BiTreeDepth(root->left) + BiTreeDepth(root->right);
}

//创建二叉树节点
BTNode* CreateBTnode(BTDataType x)
{
    BTNode* bnode = (BTNode*)malloc(sizeof(BTNode));
    bnode->data = x;
    bnode->left = bnode->right = NULL;
    return bnode;
}
int main()
{
    BTNode* A = CreateBTnode('A');
    BTNode* B = CreateBTnode('B');
    BTNode* C = CreateBTnode('C');
    BTNode* D = CreateBTnode('D');
    BTNode* E = CreateBTnode('E');
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    // printf("%d\n", BiTreeSize(A));
    // printf("%d\n", BiTreeSize(B));
    // printf("%d\n", TreeLeafSize(B));
    printf("%d ", BiTreeDepth(B));

    return 0;
}