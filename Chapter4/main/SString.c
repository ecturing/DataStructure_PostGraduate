/**
 * @file SString.c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 字符串
 * @version 0.1
 * @date 2022-09-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef struct {
  char ch[MaxSize];
  int len;
} * SString, string;
/**
 * @brief 初始化
 *
 * @param s
 */
void Init(SString *s) {
  *s = (SString)malloc(sizeof(string));
  (*s)->len = 0;
}
/**
 * @brief 创建字符串
 *
 * @param s
 */
void Screate(SString *s) {
  char inputC;
  int index = 0;
  printf("请输入字符串");
  while (1) {
    inputC = getchar();
    if (inputC != '$') {
      (*s)->ch[index++] = inputC;
    } else {
      break;
    }
  }
  (*s)->len = index - 1;
  printf("创建完成，字符串长度为：%d\n", (*s)->len);
}
/**
 * @brief 打印字符串
 *
 * @param s
 */
void Print(SString s) {
  int index = 0;
  char outP;
  while (1) {
    outP = s->ch[index++];
    printf("%c", outP);
    if (index > s->len) {
      break;
    }
  }
}

/**
 * @brief 暴力搜索
 *
 * @param F
 * @param S
 */
int BFS(SString F, SString S, int Pos) {
  int i = Pos, j = 1;
  while (i <= F->len && j <= S->len) {
    if (F->ch[i] == S->ch[j]) {
      ++i;
      ++j;
    } else {
      i = i - j + 2;
      j = 1;
    }
  }
  if (j > S->len) {
    return i - S->len;
  }else {
    return 0;
  }
}

/**
 * @brief 获取next数组值
 *  
 * @param S 
 * @param next 
 */
void getNext(SString S,int next[]) {
    int i=1;
    next[1]=0;
    int j=0;
    while (i<S->len) {
        if (j==0||S->ch[i]==S->ch[j]) {
            ++i;
            ++j;
            next[i]=j;
        }else {
            j=next[j];
        }
    }
}

/**
 * @brief KPM搜索算法0
 *
 * @param F
 * @param S
 */
int KPMS(SString F, SString S, int Pos) {
  int next[MaxSize];
  int i = Pos, j = 1;
  while (i <= F->len && j <= S->len) {
    if (j == 0 || F->ch[i] == S->ch[j]) {
      ++i;
      ++j;
    } else {
      j = next[j];
    }
  }
  if (j >= S->len) {
    return i - S->len;
  } else {
    return 0;
  }
  getNext(S,next);
}
/**
 * @brief next数组获取
 *
 */

int main() {
  SString F,S;
  Init(&F);
  Screate(&F);
  Print(F);
  Init(&S);
  Screate(&S);
  printf("第一次出现的位置为%d",KPMS(F, S, 0));
}