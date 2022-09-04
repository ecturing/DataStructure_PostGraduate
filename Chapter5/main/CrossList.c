#include <stdio.h>

typedef char Elemtype;

typedef struct OLNode{
    int row,col;//节点在稀疏矩阵的坐标点
    Elemtype value;//矩阵值
    struct OLNode *right,*down;//right指针指向同行下一个非零元素，down指针指向同一列的下一个非零元素
}OLNode,*OLink;

typedef struct{
    OLink *row_head,*col_head;
    int m,n,len;
}CrossList;

/**
 * @brief 创建稀疏矩阵
 * 
 * @param M 稀疏矩阵的创建
 */
void Create(CrossList *M){
    scanf("")
}

void 

int main(){

}