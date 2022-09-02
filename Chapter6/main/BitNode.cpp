/**
 * @file BitNode(regular).c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 迭代版本二叉树(主要考点为非递归三种遍历方式)
 * @version 0.1
 * @date 2022-08-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cstddef>
#include <stack> //导入C++的自带的栈
#include <stdio.h>
#include <stdlib.h>

using namespace std; //引用标准库

typedef char Elemtype;

typedef struct BiTNode {
  Elemtype data;
  struct BiTNode *left;
  struct BiTNode *right;
} BiTNode, *BTree;

/**
 * @brief 递归方式建立
 * 
 * @param L 
 */
void Create(BTree *L) {
  char c;
  scanf(" %c", &c);
  if (c == '$') {
    (*L) = NULL;
  } else {
    *L = (BTree)malloc(sizeof(BiTNode));
    (*L)->data = c;
    Create(&(*L)->left);
    Create(&(*L)->right);
  }
}


/**
 * @brief 非递归的中序遍历 左根右
 * 
 * @param T 
 * @param s 
 */
void InOrder(BTree T, stack<BiTNode*> s) {
    BiTNode *node=T;
    while (node!=NULL||!s.empty()) {
        if (node!=NULL) {
            s.push(node);
            node=node->left;
        }else {
            node=s.top();
            printf(" %c",node->data);
            s.pop();
            node=node->right;
        }
    }
    printf("\n");
}

/**
 * @brief 先序遍历，根左右
 * 
 * @param T 
 * @param s 
 */
void PreOrder(BTree T,stack<BiTNode*> s){
  BiTNode *node=T;
  while (node!=NULL||!s.empty()) {
    while (node!=NULL) {
      printf(" %c",node->data);
      s.push(node);
      node=node->left;
    }
    if (!s.empty()) {
      node=s.top();
      s.pop();
      node=node->right;
    }
  }
  printf("\n");
}


/**
 * @brief 后序遍历，左右根
 * 
 * @param T 
 * @param s 
 */
void PostOrder(BTree T,stack<BiTNode*> s){
  BiTNode *node=T;
  BiTNode *r=NULL;
  while (node!=NULL||!s.empty()) {
    if (node!=NULL) {
      s.push(node);
      node=node->left;
    }else {
      node=s.top();
      if (node->right==NULL||node->right==r) {
        printf(" %c",node->data);
        r=node;
        s.pop();
        node=NULL;
      }else {
        node=node->right;
      }
    }
  }
  printf("\n");  
}

int main() {
  stack<BiTNode*> s;
  BTree T;
  printf("开始创建二叉树，空节点以$代替，输入方式为先序建立");
  Create(&T);
  printf("前序遍历");
  InOrder(T,  s);
  printf("后序遍历");
  PostOrder(T, s);
  printf("先序遍历：");
  PreOrder(T, s);
}