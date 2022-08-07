/**
 * @file SeqStack.c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 顺序栈
 * @version 0.1
 * @date 2022-08-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <malloc.h>
#include <stdio.h>

#define MaxSize 20

typedef char Elemtype;

typedef struct SeqStack {
  /* data */
  Elemtype data[MaxSize]; //数据域
  int top;                //栈顶指针
} * Stack, SeqStack;

/**
 * @brief 初始化栈
 *
 * @param S
 */
void Init(Stack *S) {
  *S = (Stack)malloc(sizeof(SeqStack));
  (*S)->top = -1; //栈顶坐标初始化
}

/**
 * @brief 一次性插入更加直观显示栈的运作
 *
 * @param s 栈指针
 */
void AllPush(Stack s) {
  printf("请输入字符串，并以$结束");
  char c;
  while (1) {
    c = getchar();
    if (c != '$') {
      s->data[++s->top] = c;
    } else {
      break;
    }
  }
}
/**
 * @brief 压栈
 *
 * @param s 栈指针
 */
void Push(Stack s) {
  char c;
  c = getchar();
  s->data[++s->top] = c;
}
/**
 * @brief 清空栈
 *
 * @param s 栈指针
 */
void Clear(Stack s) {
  free(s);
  s->top = -1;
}
/**
 * @brief 是否为空栈
 *
 * @param s 栈指针
 */
void IsEmpty(Stack s) {
  if (s->top == -1) {
    /* code */
    printf("栈空\n");
  } else {
    printf("栈未空\n");
  }
}
/**
 * @brief 获取头指针数据
 *
 * @param s 栈指针
 */
void getTop(Stack s) { printf("获取栈顶数据为:%c\n", s->data[s->top]); }
/**
 * @brief 出栈函数
 *
 * @param s 栈指针
 */
void Pop(Stack s) {
  if (s->top == -1) {
    printf("栈已空\n");
  } else {
    printf("出栈，元素为%c\n",s->data[s->top--]);
  }
}

/**
 * @brief 栈满函数
 *
 * @param s 栈指针
 */
void IsFull(Stack s) {
  if (s->top == MaxSize - 1) {
    printf("栈已经满了\n");
  } else {
    printf("栈未满\n");
  }
}

int main() {
  SeqStack *s;
  Init(&s);
  // 默认直接一次性插入
  AllPush(s);
  // Push(s);
  IsEmpty(s);
  IsFull(s);
  getTop(s);
  Pop(s);
  IsEmpty(s);
}