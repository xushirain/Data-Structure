//
// Created by NPCXU on 2020/11/9.
//

#include "doubleLinkListTest.h"
#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *lLink, *rLink;
} DNode, *DLinkList;

//建立双向链表
DLinkList CreateDLinkList(int n, ElemType elemType[]) {
    DLinkList head = (DLinkList) malloc(sizeof(DNode));
    DLinkList p, s;
    p = head;
    p->data = 0;
    p->lLink = NULL;
    for (int i = 0; i < n; i++) {
        s = (DLinkList) malloc(sizeof(DNode));
        s->data = elemType[i];
        p->rLink = s;
        s->lLink = p;
        p = s;
    }
    s->rLink = NULL;
    return head;
}

//打印链表
void PrintDLinkList(DLinkList list) {
    DLinkList p = list;
    int n = 0;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->rLink;
    }
}


typedef struct SpNode {
    ElemType data, freq;
    struct SpNode *lLink, *rLink;
} *SpLinkList;

//26.
int Locate(SpNode *list, ElemType x) {
    SpLinkList p, q;
    p = list->rLink;
    while (p != NULL && p->data != x) {
        p = p->rLink;
    }
    if (p != NULL) {
        return 0;
    } else {
        p->freq++;
        q = p->lLink;
        while (q != list && q->freq < p->freq) {
            p->lLink = q->lLink;
            p->lLink->rLink = p;
            q->rLink = p->rLink;
            if (q->rLink != NULL) {
                q->rLink->lLink = q;
            }
            p->rLink = q;
            q->lLink = p;
            q = p->lLink;
        }
    }
    return 1;
}

//27.删除内容为x的节点 双向循环链表
void DeleteX(DLinkList list, ElemType x) {
    DLinkList p = list->rLink;
    while (p != list) {
        if (p->data == x) {
            p->lLink->rLink = p->rLink;
            p->rLink->lLink = p->lLink;
            free(p);
        }
    }
}

//28.判断是否是对称链表 双向循环链表
int Symmetry(DLinkList list) {
    DLinkList front, rear;
    front = list;
    rear = list->lLink;
    int flag = 0;
    while (flag == 0 && front->data == rear->data) {
        front = front->rLink;
        rear = rear->lLink;
        if (front == rear || front->lLink == rear) { //指向同一节点为奇数 rear指向front的前驱节点时为偶数
            flag = 1;
        }
    }
    if (flag == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    ElemType elemType[] = {2, 4, 6, 8, 9, 11, 14, 16, 17, 18};
    DLinkList list = CreateDLinkList(10, elemType);
    PrintDLinkList(list);
    printf("\n");

//    10.
//    Modify(list, 6, 66);
//    PrintLinkList(list);

//    11.
//    DeleteLinkListNode(list,1);
//    PrintLinkList(list);

//    12.
//    DeleteLinkListNode2(list, 2, 3);
//    PrintLinkList(list);

//    13.
//    DeleteMaxNode(list);
//    PrintLinkList(list);

//    14.
//    IsSort(list);
//    PrintLinkList(list);

//    15. 懒得写测试了0.0
//    16.
//    17.
//    18.
//    19.
//    20.
//    21.
//    22.
//    23.
}