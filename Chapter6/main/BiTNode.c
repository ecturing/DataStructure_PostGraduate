/**
 * @file BiTNode.c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 二叉树 递归版本(递归是整个重点)
 * @version 0.1
 * @date 2022-08-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <collection_stack.h>
#include <stdio.h>
#include <stdlib.h>
typedef char Elemtype;

typedef struct BiTNode {
  
  Elemtype data;
  struct BiTNode *left;  //左孩子
  struct BiTNode *right; //右孩子
} BiTNdoe, *BTree;

/**
 * @brief 初始化二叉树
 *
 * @param L
 */
 void Create(BTree *L) {
  char c;
  scanf(" %c", &c);
  if (c == '$') {
    (*L) = NULL;
  } else {
    *L = (BTree)malloc(sizeof(BiTNdoe));
    (*L)->data = c;
    Create(&(*L)->left);
    Create(&(*L)->right);
  }
}
/**
 * @brief 先序遍历,根左右
 *
 * @param L
 */
void PreOrder(BTree L) {
  if (L != NULL) {
    printf("%c ", L->data);
    PreOrder(L->left);
    PreOrder(L->right);
  }
}
/**
 * @brief 中序遍历，左根右
 *
 */
void InOrder(BTree L) {
  if (L != NULL) {
    InOrder(L->left);
    printf("%c ", L->data);
    InOrder(L->right);
  }
}
/**
 * @brief 后序遍历，左右根
 *
 */
void PostOrder(BTree L) {
  if (L != NULL) {
    PostOrder(L->left);
    PostOrder(L->right);
    printf("%c ", L->data);
  }
}

int main() {
  BTree tree;
  printf("输入序列开始建立");
  Create(&tree);
  printf("开始打印序列：\n前");
  PreOrder(tree);
  printf("\n中");
  InOrder(tree);
  printf("\n后");
  PostOrder(tree);
}