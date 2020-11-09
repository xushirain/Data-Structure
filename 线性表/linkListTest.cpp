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
        printf("%d ", p->data);
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

//删除链表中从第i个节点开始的(包含第i个几点本身)连续k个几点的算法
void DeleteLinkListNode2(LinkList &list, int i, int k) {
    LinkList r, q = list;
    if (i == 1) {
        for (int j = 1; j <= k; j++) {
            q = list;
            list = list->link;
            free(q);
        }
    } else {
        for (int j = 1; j < i - 1; j++) {
            q = q->link;
        }
        for (int j = 1; j <= k; j++) {
            r = q->link;
            q->link = r->link;
            free(r);
        }
    }
}

//删除链表中数据域值最大的节点
void DeleteMaxNode(LinkList &list) {
    LinkList q = list; //假设第一个节点为最大
    LinkList p = list->link;
    LinkList r = list; //用于记录前驱节点
    LinkList s;//最大值节点的前驱结点
    while (p != NULL) {
        if (p->data > q->data) {
            q = p;
            s = r;
        }
        r = p;
        p = p->link;
    }
    if (q == list) {
        list = list->link;
    } else {
        s->link = q->link;
    }
    free(q);
}

//有序列表 正确1 错误0
int IsSort(LinkList list) {
    LinkList r = list, p = list->link;
    while (p != NULL) {
        if (p->data < r->data) {
            return 0;
        }
        r = p;
        p = p->link;
    }
    return 1;
}

//15.交换p节点与下一个节点位置
void Exchange(LinkList &list, LinkList p) {
    LinkList q = list;
    if (list == p) {
        list = list->link;
        p->link = p->link->link;
        list->link = p;
    } else {
        while (q->link != p) {
            q = q->link;
        }
        q->link = p->link;
        p->link = p->link->link;
        q->link->link = p;
    }
}

//16.将链表中数据域值最小的移到最前方
void RemoveMin(LinkList &list) {
    LinkList q, p, s, r;
    q = list;
    p = list->link;
    r = list;
    while (p != NULL) {
        if (q->data > p->data) {
            q = p;
            s = r;
        }
        r = p;
        p = p->link;
    }
    if (p != list) {
        s->link = q->link;
        q->link = list;
        list = q;
    }
}

//17.找到倒数第k个节点
LinkList SearchNode(LinkList list, int k) {
    LinkList p, r;
    if (list != NULL && k > 0) {
        p = list;
        for (int i = 1; i < k; i++) {
            p = p->link;
            if (p == NULL) {
                printf("链表中不存在倒数第%d个节点!", k);
                return NULL;
            }
        }
        r = list;
        while (p->link != NULL) {
            p = p->link;
            r = r->link;
        }
        return r;
    }
}

//18.合并
LinkList COMBINE(LinkList X, LinkList Y) {
    LinkList p, q, Z = X;
    if (X->link == NULL) {
        X->link = Y;
    } else {
        do {
            p = X->link;
            q = Y->link;
            X->link = Y;
            Y->link = p;
            X = p;
            Y = q;
        } while (p->link != NULL && q != NULL);
    }
    if (p->link == NULL) {
        X->link = Y;
    }
    return Z;
}

//19.删除重复 保留一个
void DelMul(LinkList list) {
    LinkList p, q, r;
    int flag = 0;
    p = list->link;
    r = list;
    while (p != NULL) {
        q = list;
        while (q != p) {
            if (q->data == p->data) {
                r->link = p->link;
                free(p);
                flag = 1;
                break;
            } else {
                q = q->link;
            }
        }
        if (flag) {
            p = r->link;
            flag = 0;
        } else {
            r = p;
            p = p->link;
        }
    }
}

//20.保存最后输入的k个元素 利用循环链表
void PrintEle(int k) {
    LinkList list, p, r;
    int a;
    list = (LinkList) malloc(sizeof(LNode));
    list->data = 0;
    r = list;
    for (int i = 1; i < k; i++) {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = 0;
        r->link = p;
        r = p;
    }
    r->link = list; //建立循环链表
    p = list;
    while (scanf("%d", &a)) {
        p->data = a;  //数据依次读入链表
        p = p->link;
    }
    for (int i = 1; i <= k; i++) {
        if (p->data != 0) {
            printf("%d", p->data);
        }
        p = p->link;
    }
}

//21.循环链表中删除p节点的前驱节点
void delPreNode(LinkList p) {
    LinkList r, q;
    r = p;
    q = q->link;
    while (q->link != p) {
        r = q;
        q = q->link;
    }
    r->link = p;
    free(q);
}

//22.拆分为两个循环链表
void Separate(LinkList list, LinkList list1, LinkList list2) {
    LinkList r1, r2, p = list;
    int flag = 1;
    list1 = (LinkList) malloc(sizeof(list1));
    list1->data = 0;
    r1 = list1;
    list2 = (LinkList) malloc(sizeof(list2));
    list2->data = 0;
    r2 = list2;
    while (p != NULL) {
        if (flag == 1) {
            r1->link = p;
            r1 = p;
            list1->data++;
            flag = 2;
        } else {
            r2->link = p;
            r2 = p;
            list2->data++;
            flag = 1;
        }
        p = p->link;
    }
    r1->link = list1;
    r2->link = list2;
}

//23.逆转循环链表
void InvertCir(LinkList list) {
    LinkList p, q, r;
    p = list->link;
    q = list;
    while (p != list) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    list->link=q;
}

//int main() {
//    ElemType elemType[] = {2, 4, 6, 8, 9, 11, 14, 16, 17, 18};
//    LinkList list = CreateLinkList(10, elemType);
//    PrintLinkList(list);
//    printf("\n");
//
////    10.
////    Modify(list, 6, 66);
////    PrintLinkList(list);
//
////    11.
////    DeleteLinkListNode(list,1);
////    PrintLinkList(list);
//
////    12.
////    DeleteLinkListNode2(list, 2, 3);
////    PrintLinkList(list);
//
////    13.
////    DeleteMaxNode(list);
////    PrintLinkList(list);
//
////    14.
////    IsSort(list);
////    PrintLinkList(list);
//
////    15. 懒得写测试了0.0
////    16.
////    17.
////    18.
////    19.
////    20.
////    21.
////    22.
////    23.
//}
