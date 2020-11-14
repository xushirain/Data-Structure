#include <iostream>

typedef int ElemType;
//n阶矩阵A主对角线以下的所有元素(不包含主对角线上的元素)按照列序为主序方式依次存放于一个一维数组中
#define MaxN 100
void STOREAB(ElemType A[][MaxN],int n,ElemType B[]){
    int k=0;
    for (int j=0;j<n;j++) {
        for (int i=j+1;j<n;j++) {
            B[k++]=A[i][j];
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
