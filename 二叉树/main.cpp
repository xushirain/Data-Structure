#include <iostream>

typedef int dataType;

typedef struct node {
    dataType data;
    struct node *lChild, *rChild;
} BTNode, *BTREE;

void VISIT(dataType dataType) {
    printf("根节点为%d", dataType);
}

#define MaxN 100

//1.
void PreOrder(dataType BT[], int M) {
    int STACK[MaxN], i, top = -1;
    i = 0;
    do {
        while (i < M && BT[i] != 0) {
            VISIT(BT[i]);
            STACK[++top] = i;
            i = i * 2 + 1;
        }
        i = STACK[top--];
        i = i * 2 + 2;
    } while (!((i == M || BT[i] == 0) && top < 0));
}

//2.
int Similar(BTREE T1, BTREE T2) {
    if (T1 == NULL && T2 == NULL) {
        return 1;
    }
    if (T1 != NULL && T2 != NULL && Similar(T1->lChild, T2->lChild) && Similar(T1->rChild, T2->rChild)) {
        return 1;
    }
    return 0;
}

//3.
int EqualBT(BTREE T1, BTREE T2) {
    if (T1 == NULL && T2 == NULL) {
        return 1;
    }
    if (T1 != NULL && T2 != NULL && T1->data == T2->data && EqualBT(T1->lChild, T2->lChild) &&
        EqualBT(T1->rChild, T2->rChild)) {
        return 1;
    }
    return 0;
}

//4.
void Release(BTREE &T) {
    //后续方式
    if (T != NULL) {
        Release(T->lChild);
        Release(T->rChild);
        free(T);
    }
}

//5.
typedef struct sNode { //链式堆栈
    BTREE data;
    struct sNode *link;
} BLNode, *BLinkList;

//采用前序遍历 每次访问一个节点就判断该节点是否只存在一颗子树 同时记录满足该条件的节点数目
int Count(BTREE T) {
    BTREE p = T;
    BLinkList q, top = NULL;
    int n = 0; //记录数目
    if (T != NULL) {
        do {
            while (p != NULL) {
                if (p->lChild != NULL && p->rChild == NULL ||
                    p->rChild != NULL && p->lChild == NULL) {
                    n++;
                }
                q = (BLinkList) malloc(sizeof(BLNode));
                q->data = p;
                q->link = top;
                top = q;
                p = p->lChild;
            }
            p = top->data;
            q = top;
            top = top->link;
            free(q);
            p = p->rChild;
        } while (!(p == NULL && top == NULL));
    }
    return n;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
