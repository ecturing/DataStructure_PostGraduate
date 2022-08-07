/**
 * @file LinkQueen.c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 链栈
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef char Elemtype;

typedef struct QuNode {
  Elemtype data;
  struct QuNode *next;
} LinkQueenNode;

typedef struct {
  LinkQueenNode *front; //队列头
  LinkQueenNode *rear;  //队列尾
} LinkQueen;
/**
 * @brief 队列初始化
 *
 * @param Q 队列元素
 */
void Init(LinkQueen *Q) {
  Q->front = (LinkQueenNode *)malloc(
      sizeof(LinkQueenNode)); //分配队列头,与链表头结点类似，不存储数据
  if (Q->front != NULL) { //分配后的队列头如果不为空，继续操作，若为空表示溢出
    Q->rear = Q->front;
    Q->front->next = NULL;
  } else {
    printf("内存无法分配，栈队列");
  }
}
/**
 * @brief 一次全入队函数
 *
 * @param Q
 */
void AllPush(LinkQueen *Q) {
  LinkQueenNode *New;
  char c;
  printf("输入元素并以$结束");
  while (1) {
    scanf(" %c", &c);
    if (c != '$') {
      New = (LinkQueenNode *)malloc(sizeof(LinkQueenNode));
      New->data = c;
      New->next = NULL;
      Q->rear->next = New;
      Q->rear = New;
    } else {
      break;
    }
  }
}
/**
 * @brief 入队函数
 *
 * @param Q 队列头
 */
void Push(LinkQueen *Q) {
  char c;
  printf("输入一个元素并入队");
  scanf(" %c", &c);
  LinkQueenNode *New;
  New = (LinkQueenNode *)malloc(sizeof(LinkQueenNode));
  if (New != NULL) {
    New->data = c;
    New->next = NULL;
    Q->rear->next = New;
    Q->rear = New;
  } else {
    printf("溢出\n");
  }
}
/**
 * @brief 出队函数
 *
 * @param Q 队列头
 */
void Pop(LinkQueen *Q) {
  LinkQueenNode *Del;
  if (Q->front == Q->rear) {
    printf("空队列无法再出队\n");
  }
  Del = Q->front->next;
  Q->front->next = Del->next;
  if (Q->rear == Del) {
    Q->rear = Q->front;//重要！因链队列存在头结点，尾指针无法移动到头指针处，需要手动移动至头指针处
  }
  printf("出队，出队元素为：%c\n", Del->data);
  free(Del);
}
/**
 * @brief 队列为空？函数
 *
 * @param Q  队列头
 */
void IsEmpty(LinkQueen *Q) {
  if (Q->front == Q->rear) {
    printf("队列空\n");
  } else {
    printf("队列有元素存在\n");
  }
}
/**
 * @brief 获取队列头元素值但不出队
 *
 * @param Q 队头
 */
void GetHead(LinkQueen *Q) {
  if (Q->front->next == NULL) {
    printf("队列空，无可获取元素\n");
  } else {
    printf("队头元素为：%c\n", Q->front->next->data);
  }
}
/**
 * @brief 销毁队列
 *
 * @param Q
 */
void Destory(LinkQueen *Q) {
  LinkQueenNode *Del;
  if (Q->front == Q->rear) {
    printf("队空，不能销毁\n");
  } else {
    while (Q->front != Q->rear) {
      Del = Q->front->next;
      Q->front->next = Del->next;
      if (Q->rear == Del) {
        Q->rear = Q->front;//同理出队列注释
      }
      free(Del);
    }
    printf("队列已经销毁\n");
  }
}

int main() {
  LinkQueen *q;
  Init(q);
  // Push(q);
  AllPush(q);
  GetHead(q);
  Pop(q);
  Pop(q);
  Destory(q);
  IsEmpty(q);
}