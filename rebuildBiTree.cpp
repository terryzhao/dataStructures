/*
 * =====================================================================================
 *
 *  Filename:  rebuildBiTree.cpp
 *
 *  Description:
 *
 *  Created:  2017年11月13日 16时13分37秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

#define TREELEN 6

struct NODE
{
    NODE *left;
    NODE *right;
    char chValue;
};

void rebuildTree(char* pPreOrder, char* pInOrder, int nTreeLen, NODE **pRoot)
{
    if(pPreOrder == NULL || pInOrder == NULL)
        return;

    NODE *nTemp = new NODE;
    nTemp->chValue = *pPreOrder;
    nTemp->left  = NULL;
    nTemp->right = NULL;

    if(*pRoot == NULL)
        *pRoot = nTemp;

    if(nTreeLen == 1)
        return;

    char* pOrgInOrder = pInOrder;
    char* pLeftEnd = pInOrder;
    int nTempLen = 0;

    while(*pPreOrder != *pLeftEnd){
        if(pPreOrder == NULL || pLeftEnd == NULL)
            return;

        nTempLen++;
        if(nTempLen > nTreeLen)
            break;
        pLeftEnd++;
    }

    int nLeftLen = 0;
    nLeftLen = int(pLeftEnd - pOrgInOrder);

    int nRightLen = 0;
    nRightLen = nTreeLen - nLeftLen - 1;

    if(nLeftLen > 0)
        rebuildTree(pPreOrder+1, pInOrder, nLeftLen, &((*pRoot)->left));

    if(nRightLen > 0)
        rebuildTree(pPreOrder+nLeftLen+1, pInOrder, nRightLen, &((*pRoot)->right));
}

void postOrder(NODE *root)
{
    if(root == NULL)
        return;

    if(root->left)
        postOrder(root->left);

    if(root->right)
        postOrder(root->right);

    cout<<root->chValue<<" ";
}

int main(void)
{
    char szPreOrder[TREELEN] = {'a', 'b', 'd', 'c', 'e', 'f'};
    char szInOrder[TREELEN]  = {'d', 'b', 'a', 'e', 'c', 'f'};

    NODE *root = NULL;
    rebuildTree(szPreOrder, szInOrder, TREELEN, &root);
    cout<<endl;

    postOrder(root);
}




