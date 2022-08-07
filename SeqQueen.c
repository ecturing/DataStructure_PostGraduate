/**
 * @file SeqQueen.c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 循环队列（队列满条件考察为重点）
 * @version 0.1
 * @date 2022-08-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6

typedef char QueueElemType;

typedef struct {
  QueueElemType data[MAXSIZE];
  int front;
  int rear;
} SeqQueen;
/**
 * @brief 初始化队列
 *
 * @param S
 */
void Init(SeqQueen **S) {
  *S = (SeqQueen *)malloc(sizeof(SeqQueen));
  (*S)->front = (*S)->rear = 0;
}

/**
 * @brief 全插入
 *
 * @param S
 */
void ALlPush(SeqQueen *S) {
  char c;
  printf("请输入并以$结束");
  while (1) {
    scanf(" %c", &c);
    if (c != '$') {
      if ((S->rear + 1) % MAXSIZE == S->front) {
        break;
      } else {
        S->data[S->rear] = c;
        S->rear = (S->rear + 1) % MAXSIZE;
      }
    } else {
      break;
    }
  }
}

/**
 * @brief 入队函数
 * 
 * @param S 
 */
void Push(SeqQueen *S) {
    char c;
    if ((S->rear + 1) % MAXSIZE == S->front) {
        printf("队列已经满,不能输入\n");
    }else {
        printf("输入一个元素");
        scanf(" %c",&c);
        S->data[S->rear]=c;
        S->rear = (S->rear + 1) % MAXSIZE;
    }
}
/**
 * @brief 出队函数
 * 
 * @param S 
 */
void Pop(SeqQueen *S) {
  if (S->front == S->rear) {
    printf("队列空,不能出栈");
  } else {
    printf("出队！出队元素为%c\n", S->data[S->front]);
    S->front = (S->front + 1) % MAXSIZE;
  }
}
int main() {
    /* 测试MaxSize为6,输入测试用例为123456$ */
  SeqQueen *s;
  Init(&s);
  ALlPush(s);
  Push(s);//插入失败，队列已满
  Pop(s);
  Pop(s);
}