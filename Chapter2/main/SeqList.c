/**
 * @file SeqList.c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 顺序表
 * @version 0.1
 * @date 2022-07-31
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <malloc.h>
#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define SUCCESS 1

typedef char Elemtype;

typedef struct {
  /* data */
  Elemtype data[MAXSIZE]; //数据域
  int last;               //最后一个元素的数组下标
} SeqList;

/**
 * @brief 按元素查找
 *
 * @param L 线性表
 * @param e 元素值
 * @return int 节点下标
 */
void locate(SeqList *L, Elemtype e) {
  int index = L->last;
  while (1) {
    /* code */
    if (index == -1) {
      /* code */
      break;
      printf("没有找到");
    } else if (L->data[index--] == e) {
      printf("已经找到，下标为：%d", index + 1);
      break;
    }
  }
}

/**
 * @brief 顺序表插入
 *
 * @param L 顺序表
 * @param i 插入位置
 * @param e 插入元素
 * @return int
 */
int InsList(SeqList *L, int i, Elemtype e) {
  int k;
  if (i > L->last + 2 || i < 1) {
    /* code */
    printf("插入位置不合法");
    return ERROR;
  } else {
    if (L->last >= MAXSIZE - 1) {
      /* code */
      printf("表满，无法插入");
      return ERROR;
    } else {
      for (k = L->last; k >= i - 1; k--) {
        /* code */
        L->data[k + 1] = L->data[k];
      }
      L->data[i - 1] = e;
      L->last++;
      return SUCCESS;
    }
  }
}

/**
 * @brief 顺序表删除
 *
 * @param L 顺序表
 * @param i 删除位置
 * @param e 删除元素
 * @return int 状态
 */
int DelList(SeqList *L, int i, Elemtype *e) {
  int k;
  if (i > L->last + 1 || i < 1) {
    /* code */
    printf("删除位置不合法\n");
    return ERROR;
  } else {
    *e = L->data[i - 1]; //待删除元素
    for (k = i; k <= L->last; k++) {
      /* code */
      L->data[k - 1] = L->data[k];
    }
    L->last--;
    return OK;
  }
}

/**
 * @brief 合并顺序表
 *
 * @param La 顺序表a
 * @param Lb 顺序表b
 * @param Lc 合并后的顺序表c
 */
void MergeLsit(SeqList *La, SeqList *Lb, SeqList *Lc) {
  int i = 0, j = 0, k = 0, l;
  while (i <= La->last && j <= Lb->last) {
    /* code */
    if (La->data[i] <= Lb->data[j]) {
      /* code */ Lc->data[k] = La->data[i];
      i++;
      k++;
    } else {
      Lc->data[k] = Lb->data[j];
      j++;
      k++;
    }
    while (i <= La->last) {
      /* code */
      Lc->data[k] = La->data[i];
      i++;
      k++;
    }
    while (j <= Lb->last) {
      /* code */
      Lc->data[k] = Lb->data[j];
      j++;
      k++;
    }
    Lc->last = La->last + Lb->last + 1;
  }
}
/**
 * @brief 链表初始化
 *
 * @param L
 */
void Init(SeqList **L) {
  *L = (SeqList *)malloc(sizeof(SeqList));
  (*L)->last = -1; //空表置-1
}
/**
 * @brief 顺序表构造
 *
 * @param q 顺序表
 */

void Create(SeqList *q) {
  int flag = 1;
  char c;
  printf("开始输入字符");
  while (flag) {
    /* code */
    scanf(" %c", &c);
    if (c != '$') {
      /* code */
      q->data[++q->last] = c;
    } else {
      flag = 0;
    }
  }
}
/**
 * @brief 打印顺序表
 *
 * @param q 顺序表
 */
void ListPrint(SeqList *q) {
  printf("打印顺序表(倒序)");
  int index = q->last;
  while (1) {
    /* code */
    printf("%c", q->data[index--]);
    if (index == -1) {
      /* code */
      break;
    }
  }
  printf("\n");
}

int main() {
  SeqList *q, *p;
  Init(&q);
  Init(&p);
  Create(q);
  ListPrint(q);
  locate(q, 'd');
  Elemtype del = '1';
  DelList(q, 4, &del);
  ListPrint(q);
  InsList(q, 4, 'z');
  ListPrint(q);
  Create(p);
  SeqList *res;
  /* 书本测设用例为La(2,2,3),Lb(1,3,3,4)测试通过 */
  MergeLsit(q, p, res);
  ListPrint(res);
}