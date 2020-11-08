//
// Created by NPCXU on 2020/11/8.
//

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *link;
} LNode, *LinkList;

//建立线性链表
LinkList CreateLinkList(int n, ElemType elemType[]) {
    LinkList p, r, list = NULL;
    for (int i = 0; i < n; i++) {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = elemType[i];
        p->link = NULL;
        if (list == NULL) {
            list = p;
        } else {
            r->link = p;
        }
        r = p;
    }
    return list;
}

//打印链表
void PrintLinkList(LinkList list) {
    LinkList p = list;
    int n = 0;
    while (p != NULL) {
        printf("%d, ", p->data);
        p = p->link;
    }
}

//将链表中数据域值为d的所有节点的数据域值修改为item
void Modify(LinkList list, ElemType d, ElemType item) {
    LinkList p = list;
    while (p != NULL) {
        if (p->data == d) {
            p->data = item;
        }
        p = p->link;
    }
}

//删除链表第i个节点
void DeleteLinkListNode(LinkList &list, int i) {
    LinkList r, q = list;
    if (i == 1) {
        list = list->link;
    } else {
        for (int k = 1; k < i; k++) {
            r = q;
            q = q->link;
        }
        r->link = q->link;
    }
    free(q);
}

int main() {
    ElemType elemType[] = {2, 4, 6, 8, 9};
    LinkList list = CreateLinkList(5, elemType);
    PrintLinkList(list);
    printf("\n");

//    10.
//    Modify(list, 6, 66);
//    PrintLinkList(list);

//    11.
//    DeleteLinkListNode(list,1);
//    PrintLinkList(list);


}
