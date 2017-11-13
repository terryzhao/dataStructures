/*
 * =====================================================================================
 *
 *  Filename:  linkList.cpp
 *
 *  Description:
 *
 *  Created:  2017年11月13日 11时01分32秒
 *  Revision:  none
 *
 *  Author:  Terry Zhao
 *  Organization:
 *
 * =====================================================================================
 */

#include <iostream>


using namespace std;


typedef struct LinkNode{
    int value;
    struct LinkNode* next;
}LNode;

LNode *createLinkList()
{
    int key=0;

    cin >> key;

    if(key == -1){
        return NULL;
    }else{
        LNode *node = new LNode;
        node->value = key;
        node->next = createLinkList();

        return node;
    }
}

void scanLinkList(LNode *head)
{
    while(head != NULL)
    {
        cout<<head->value<<" ";
        head = head->next;
    }

    cout<<endl;
}

LNode *getMidNode(LNode *head)
{
    LNode *p = head;
    LNode *q = head;

    if((head == NULL) || (head->next == NULL))
        return head;

    while(q->next != NULL)
    {
        p = p->next;
        if(q->next->next != NULL)
            q = q->next->next;
        else
            break;
    }

    cout<<"Mid Node is "<<p->value<<endl;
    return p;
}

LNode *getKthNodeBackward(LNode *head, int k)
{
    LNode *p, *q;
    p = q = head;

    while(k--){
        if(q!=NULL)
            q = q->next;
        else
            return NULL;
    }

    while(q!=NULL)
    {
        p = p->next;
        q = q->next;
    }

    cout<<"The K th node from backward is "<<p->value<<endl;
    return p;
}

LNode* reverseList(LNode *head)
{
    LNode *p, *pre, *cur;
    cur = head;
    pre = NULL;
    p = head->next;

    while(p != NULL)
    {
        cur->next = pre;
        pre = cur;
        cur = p;
        p = p->next;
    }

    cur->next = pre;

    scanLinkList(cur);

    return cur;
}

int main()
{
    LNode *head;

    head = createLinkList();

    scanLinkList(head);

    getMidNode(head);

    getKthNodeBackward(head, 3);

    reverseList(head);
}

