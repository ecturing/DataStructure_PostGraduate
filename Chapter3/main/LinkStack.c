/**
 * @file LinkStack.c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 链栈实现
 * @version 0.1
 * @date 2022-08-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef char Elemtype;

typedef struct LinkNode {
  Elemtype data;
  struct LinkNode *next;
} * LinkStackNode, Node;

/**
 * @brief 链栈初始化
 *
 * @param L 头指针
 */
void Init(LinkStackNode *L) {
  *L = (Node *)malloc(sizeof(Node));
  (*L)->next = NULL;
}

/**
 * @brief 全压栈,头插法，top指针指向首节点
 *
 * @param L
 */
void AllPush(LinkStackNode L) {
  printf("请开始输入数字，并输入$结束\n");
  Node *pre;
  char c;
  int flag = 1;
  while (flag) {
    /* code */
    scanf(" %c", &c);
    if (c != '$') {
      /* code */
      pre = (Node *)malloc(sizeof(Node));
      pre->data = c;
      pre->next = L->next;
      L->next = pre;
    } else {
      flag = 0;
    }
  }
}

/**
 * @brief 普通压栈
 *
 * @param L
 */
void Push(LinkStackNode L) {
  printf("请输入一个字符，将压入栈");
  char c;
  scanf(" %c",&c);
  Node *New;
  New = (Node *)malloc(sizeof(Node));
  New->data = c;
  New->next = L->next;
  L->next = New;
}

/**
 * @brief 出栈
 *
 * @param L
 */
void Pop(LinkStackNode L) {
  Node *top;
  top = L->next;
  if (top == NULL) {
    printf("栈空，无法弹出");
  } else {
    printf("出栈！出栈元素为：%c\n", top->data);
    L->next = top->next;
    free(top);
  }
}

/**
 * @brief 清空栈
 *
 * @param L
 */
void Clear(LinkStackNode L) {
  Node *index;//删除元素索引
  while (L->next!=NULL) {
    index=L->next;
    L->next=index->next;
    free(index);
  }
}

/**
 * @brief 栈空
 *
 * @param L
 */
void IsEmpty(LinkStackNode L) {
  if (L->next==NULL) {
    printf("栈空\n");
  }else {
    printf("栈内有元素\n");
  }
}

/**
 * @brief 栈满(链栈在内存可用的情况下，不会满，不予实现)
 *
 * @param L
 */
void IsFull(LinkStackNode L) {}

/**
 * @brief 获取栈顶元素
 *
 * @param L
 */
void GetTop(LinkStackNode L) {
  Node *Top=L->next;
  if (Top==NULL) {
    printf("栈空，无法获取\n");
  }else {
    printf("栈顶元素为：%c\n",Top->data);
  }
}

int main() {
  LinkStackNode L;
  Init(&L);
  AllPush(L);
  Pop(L);
  Push(L);
  GetTop(L);
  Clear(L);
  IsEmpty(L);
}