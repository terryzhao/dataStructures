/*
 * =====================================================================================
 *
 *  Filename:  bitree.cpp
 *
 *  Description:
 *
 *  Created:  2017年11月13日 09时28分52秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct BitTreeNode{
    int data;
    struct BitTreeNode* left;
    struct BitTreeNode* right;
}BTNode;

BTNode *createBiTree()
{
    // 先按顺序驶入二叉树中节点的值(一个字符),空格字符代表空树
    int key;
    cin >> key;
    if(key == -1) // getchar() 为逐个读入标准库函数
    {
        return NULL;
    }
    else{
        BTNode *node = new BTNode; // 产生新的子树
        node->data = key; // 由getchar()逐个读进来
        node->left = createBiTree(); // 递归创建左子树
        node->right = createBiTree(); // 递归创建右子树

        return node;
    }
}

void preOrder(BTNode *root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BTNode *root)
{
    if(root == NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void deepFirstSearch(BTNode *root)
{
    stack<BTNode *> nodeStack;

    nodeStack.push(root);
    while(!nodeStack.empty())
    {
        BTNode *node = nodeStack.top();
        cout<<node->data<<" ";
        nodeStack.pop();

        if(node->right)
            nodeStack.push(node->right);

        if(node->left)
            nodeStack.push(node->left);
    }

    cout<<endl;
}

void broadFirstSearch(BTNode *root)
{
    queue<BTNode *> nodeQueue;

    nodeQueue.push(root);
    while(!nodeQueue.empty())
    {
        BTNode *node = nodeQueue.front();
        nodeQueue.pop();
        cout<<node->data<<" ";
        if(node->left)
            nodeQueue.push(node->left);
        if(node->right)
            nodeQueue.push(node->right);
    }

    cout<<endl;
}

int main(void)
{
    BTNode *root = NULL;

    root = createBiTree();
    preOrder(root);
    cout<<endl;

    inOrder(root);
    cout<<endl;

    broadFirstSearch(root);

    deepFirstSearch(root);

    return 0;
}
