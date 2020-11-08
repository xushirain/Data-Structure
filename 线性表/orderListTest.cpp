//
// Created by NPCXU on 2020/11/8.
//
#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct {
    ElemType data[50];
    int length;
} SqList;

//建立顺序表
void CreateList(SqList *&list, ElemType elem[], int n) {
    list = (SqList *) malloc(sizeof(SqList));
    for (int i = 0; i < n; i++)
        list->data[i] = elem[i];
    list->length = n;
}

//按照元素删除
void DeleteList(SqList *&list, ElemType elem) {
    int pos;
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == elem) {
            pos = i;
        }
    }
    for (int i = pos; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
}

//打印
void DisplayList(SqList *list) {
    for (int i = 0; i < list->length; i++)
        printf("%d ", list->data[i]);
    printf("\n");
}

//查找最小值
int FindMin(SqList *list) {
    int tmp = list->data[0];
    for (int i = 0; i < list->length; i++) {
        if (tmp > list->data[i]) {
            tmp = list->data[i];
        }
    }
    return tmp;
}

//查找最大值和最小值 3n/2比较次数
void MaxAndMin(SqList *list) {
    int max = list->data[0], min = list->data[0];
    for (int i = 0; i < list->length; i++)
        if (max < list->data[i])
            max = list->data[i];
        else if (min > list->data[i])
            min = list->data[i];
    printf("\nmax= %d,min= %d", max, min);
}

//递归查找值 返回位置
int SeqSearch(SqList *list, ElemType item, int pos) {
    if (pos > list->length)
        return -1;
    else if (list->data[pos] == item)
        return pos;
    return SeqSearch(list, item, pos + 1);
}

//逆转
void reverse(SqList *list) {
    ElemType temp;
    for (int i = 0; i < list->length / 2; i++) {
        temp = list->data[i];
        list->data[i] = list->data[list->length - i - 1];
        list->data[list->length - i - 1] = temp;
    }
}

//删除奇数
void DeleteOdd(SqList *list) {
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] % 2 != 0) {
            DeleteList(list, list->data[i]);
        }
    }
}

//删除序号为奇数
void DeleteNumOdd(SqList *list) {
    int j = -1;
    for (int i = 0; i < list->length; i += 2) {
        list->data[++j] = list->data[i];
    }
    int odd;
    for (int i = 0; i < list->length; i++) {
        if (i % 2 != 0) {
            odd++;
        }
    }
    list->length = list->length - odd;
}

//删除范围内的数据 (有序条件)
void DeleteRange(SqList *list, ElemType low, ElemType high) {
    int l = 0, h = list->length - 1;
    while (list->data[l] < low) {
        l++;
    }
    while (list->data[h] > high) {
        h--;
    }
    int pos = l;
    for (int k = h + 1; k < list->length; k++) {
        list->data[l++] = list->data[k];
    }
    list->length = list->length - h + pos - 1;
}

//建立一个长度为n且不包含重复元素的线性表a
void BuildList(SqList *&list, int length) {
    int flag, i;
    list->length = length;
    scanf("%d", &list->data[0]);
    while (i < length - 1) {
        scanf("%d", &list->data[i]);
        for (int j = 0; j < i; j++) {
            if (list->data[j] == list->data[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            i++;
        else
            flag = 0;
    }
}

//向A中的第i个元素插入B 不考虑溢出
int InsertAB(ElemType A[], int n, ElemType B[], int m, int i) {
    int j;
    for (int j = n - 1; j > i - 2; j--) {
        A[j + m] = A[j];
    }
    for (j = 0; j < m; j++) {
        A[i + j - 1] = B[j];
    }
    return n + m;
}

//int main() {
//    SqList *list;
//    int n = 5;
//    ElemType elem[] = {10, 8, 2, 6, 15};
//    CreateList(list, elem, n);
//    DisplayList(list);
//
////    1.
////    printf("最小值为：\n");
////    int min = FindMin(list);
////    printf("%d",min);
//
////    2.
////    MaxAndMin(list);
//
////    3.
////    int pos = SeqSearch(list, elem[3], 0);
////    printf("最小值位置为：%d\n", pos);
//
////    4.
////    reverse(list);
////    DisplayList(list);
//
////    5.
////    DeleteOdd(list);
////    DisplayList(list);
//
////    6.
////    DeleteNumOdd(list);
////    DisplayList(list);
//
////    7.
////    SqList *listOrder;
////    ElemType elemOrder[] = {2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 14, 21, 56, 78};
////    CreateList(listOrder, elemOrder, 14);
////    DisplayList(listOrder);
////    DeleteRange(listOrder,7,14);
////    DisplayList(listOrder);
//
////    8.
////    SqList *list_new;
////    BuildList(list_new,10);
//
////    9.
//
//}

