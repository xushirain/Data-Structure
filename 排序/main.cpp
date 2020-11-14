#include <iostream>

typedef int keyType;

void InsertSort(keyType k[], int n);

void SelectSort(keyType k[], int n);

void BubbleSort(keyType k[], int n);

void ShellSort(keyType k[], int n);

void QuickSort(keyType k[], int n);

void HeadSort(keyType k[], int n);

void MergeSort(keyType k[], int n);

void printSort(keyType k[], int n);


int main() {
    int n = 8;
    keyType k[] = {38, 49, 65, 97, 76, 13, 27, 49};

//    InsertSort(k, n);
//    SelectSort(k, n);
//    BubbleSort(k, n);
//    ShellSort(k, n);
//    QuickSort(k, n);
//    HeadSort(k, n);

    MergeSort(k, n);
    return 0;
}

/*插入排序
 *时间复杂度O(n^2)
 */
void InsertSort(keyType k[], int n) {
    int j;
    keyType temp;
    for (int i = 1; i < n; i++) {
        temp = k[i];
        j = i - 1;
        while (temp < k[j] && j > -1) {
            k[j + 1] = k[j];
            j--;
        }
        k[j + 1] = temp;
    }
    printSort(k, n);
}

/*选择排序
 *时间复杂度O(n^2)
 */
void SelectSort(keyType k[], int n) {
    int d;
    keyType temp;
    for (int i = 0; i < n - 1; i++) {
        d = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (k[j] < k[d]) {
                d = j;
            }
        }
        if (d != i) {
            temp = k[d];
            k[d] = k[i];
            k[i] = temp;
        }
    }
    printSort(k, n);
}

/*冒泡排序
 *时间复杂度O(n^2)
 */
void BubbleSort(keyType k[], int n) {
    int flag = 1;
    keyType temp;
    for (int i = 0; i < n - 1; i++) {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (k[j] > k[j + 1]) {
                temp = k[j];
                k[j] = k[j + 1];
                k[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    printSort(k, n);
}

/*希尔排序
 *时间复杂度O(nlog2n)~O(n^2)
 */
void ShellSort(keyType k[], int n) {
    int j, flag, gap = n;
    keyType temp;
    while (gap > 1) {
        gap = gap / 2;
        do {
            flag = 0;
            for (int i = 0; i < n - gap; i++) {
                j = i + gap;
                if (k[i] > k[j]) {
                    temp = k[i];
                    k[i] = k[j];
                    k[j] = temp;
                    flag = 1;
                }
            }
        } while (flag != 0);
    }
    printSort(k, n);
}

/*快速排序
 *时间复杂度O(log2n)
 */
void SWAP(keyType &i, keyType &j) {
    keyType temp;
    temp = i;
    i = j;
    j = temp;
}

void Quick(keyType k[], int s, int t) {
    int i, j;
    if (s < t) {
        i = s;
        j = t + 1;
        while (1) {
            do i++;
            while (!(k[s] <= k[i] || i == t));
            do j--;
            while (!(k[s] >= k[j] || j == s));
            if (i < j) {
                SWAP(k[i], k[j]);
            } else {
                break;
            }
        }
        SWAP(k[s], k[j]);
        Quick(k, s, j - 1);
        Quick(k, j + 1, t);
    }
}

void QuickSort(keyType k[], int n) {
    Quick(k, 0, n - 1);
    printSort(k, n);
}

/*堆排序
 *时间复杂度O(nlog2n)
 */
void Adjust(keyType k[], int i, int n) { //i为根节点的序号 j为左右子树根节点值最大者的序号
    int temp = k[i];
    for (int j = i * 2 + 1; j < n; j = j * 2 + 1) {
        if (j + 1 < n && k[j] < k[j + 1]) {
            j++;
        }
        if (k[j] > temp) {
            k[i] = k[j];
            i = j;
        } else {
            break;
        }
    }
    k[i] = temp;
    printSort(k, n);
}

void HeadSort(keyType k[], int n) {
    //构建大顶堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        Adjust(k, i, n);
    }
    //排序 由小到大
    for (int i = n - 1; i > 0; i--) {
        SWAP(k[0], k[i]);
        Adjust(k, 0, i);
    }
    printSort(k, n);
}

/*归并排序
 *时间复杂度O(nlog2n)
 */
void Merge(keyType k[], int left, int mid, int right, keyType temp[]) {
    int i = left;
    int j = mid + 1;
    int t = 0;
    while (i <= mid && j <= right) {
        if (k[i] <= k[j]) {
            temp[t++] = k[i++];
        } else {
            temp[t++] = k[j++];
        }
    }
    while (i <= mid) {
        temp[t++] = k[i++];
    }
    while (j <= right) {
        temp[t++] = k[j++];
    }
    t = 0;
    while (left <= right) {
        k[left++]=temp[t++];
    }
}
void Sort(keyType k[], int left, int right, keyType temp[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        Sort(k, left, mid, temp);
        Sort(k, mid + 1, right, temp);
        Merge(k, left, mid, right, temp);
    }
}
void MergeSort(keyType k[], int n) {
    keyType temp[n];
    Sort(k,0,n-1,temp);
    printSort(k, n);
}

void printSort(keyType k[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", k[i]);
    }
    printf("\n");
}


