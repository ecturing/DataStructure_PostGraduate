/**
 * @file LinkList.c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 单链表
 * @version 0.1
 * @date 2022-07-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <termio.h>

typedef char Elemtype;

typedef struct Node {
  Elemtype data;     //数据域
  struct Node *next; //指针域
                     /* data */
} Node, *LinkList;

/**
 * @brief 链表初始化
 *
 * @param L 头指针
 */
void init(LinkList *L) {
  *L = (LinkList)malloc(sizeof(Node));
  (*L)->next = NULL;
}

/**
 * @brief 头插入法
 *
 * @param L 头指针
 */
void CreateFromHead(LinkList L) {
  printf("请开始输入数字，并输入$结束\n");
  Node *pre;
  char c;
  int flag = 1;
  while (flag) {
    /* code */
    scanf("%c", &c);
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
 * @brief 尾插法
 *
 * @param L 头指针
 */
void CreateFromTail(LinkList L) {
  Node *New;      //新节点
  Node *tail = L; //指向尾部的指针
  printf("请开始输入字符，以$结束");
  int flag = 1; //循环标识符
  char c;       //输入字符
  while (flag) {
    scanf(" %c", &c);
    if (c != '$') {
      /* code */
      New = (Node *)malloc(sizeof(Node));
      New->data = c;
      tail->next = New;
      tail = tail->next;
    } else {
      flag = 0;
      tail->next = NULL;
    }
  }
}

/**
 * @brief 根据节点号搜索节点值
 *
 * @param index 节点号（从0开始）
 * @return Elemtype 节点值
 */
Elemtype SearchByIndex(LinkList L, int index) {
  if (index < 0) {
    /* code */
    printf("输入不合法\n");
  }
  int status = 0;   //标识索引，标识当前遍历到第status个节点
  Node *result = L; //结果节点
  while ((result->next != NULL) && (status < index)) {
    /* code */
    result = result->next;
    status++;
  }
  if (index == status) {
    /* code */
    return result->data;
  } else {
    printf("输入不合法");
  }
  return -1;
}
/**
 * @brief 查找节点值为key的节点元素
 *
 * @param L 头节点
 * @param key 节点值
 * @return Node* 返回的节点元素
 */
void SearchKey(LinkList L, Elemtype key) {
  Node *result;
  result = L->next;
  while (result != NULL) {
    /* code */
    if (result->data != key) {
      /* code */
      result = result->next;
    } else {
      break;
      printf("节点已经找到，数据为：%d", result->data);
    }
  }
  printf("节点未能找到\n");
}

/**
 * @brief 求链表长度
 *
 * @param L 头指针
 * @return int 链表长度
 */
int ListLength(LinkList L) {
  Node *index;
  index = L->next;
  int length = 0;
  while (index != NULL) {
    /* code */
    index = index->next;
    length++;
  }
  return length;
}
/**
 * @brief 指定位置插入元素
 *
 * @param L 头指针
 * @param Index 插入点
 * @param value 插入值
 */
int InsertList(LinkList L, int Index, Elemtype value) {
  Node *NewNode, *pre = L;
  int i = 0;
  if (Index < 0) {
    /* code */
    return -1;
  }
  while (pre != NULL && i < Index - 1) {
    /* code */
    pre = pre->next;
    i++;
  }
  if (pre == NULL) {
    /* code */
    return -1;
  } else {
    NewNode = (Node *)malloc(sizeof(Node));
    NewNode->data = value;
    NewNode->next = pre->next;
    pre->next = NewNode;
    return 1;
  }
}
/**
 * @brief 指定位置删除元素
 *
 * @param L 头指针
 * @param Index 插入点
 */
int DeleteList(LinkList L, int Index) {
  Node *pre = L, *Del;
  int i = 0;
  while (pre->next != NULL && i < Index - 1) {
    /* code */
    pre = pre->next;
    i++;
  }
  if (pre->next == NULL) {
    /* code */
    return -1;
  } else {
    Del = pre->next;
    pre->next = Del->next;
    free(Del);
  }
  return 1;
}
/**
 * @brief 打印链表
 *
 * @param L 头节点
 */
void print(LinkList L) {
  Node *Index = L->next;
  while (Index != NULL) {
    /* code */
    printf("%c", Index->data);
    Index = Index->next;
  }
  printf("\n");
}

/**
 * @brief 链表销毁
 * 
 * @param L 
 */
void Destroy(LinkList L){
  Node *index;
  while (L->next!=NULL) {
    index=L->next;
    L->next=index->next;
    free(index);
  } 
}
/**
 * @brief 有序表合并
 *
 * @param A
 * @param B
 * @return LinkList 源A地址
 */
Node *MergeList(LinkList A, LinkList B) {
  Node *a, *b, *r;//a,b均为链表A,B的索引指针，*r为指向尾部的指针，关于*r,书本错误，未定义*r
  LinkList New;
  a = A->next;
  b = B->next;
  New = A;
  New->next = NULL;
  r = New;
  while (a != NULL && b != NULL) {
    /* code */
    if (a->data <= b->data) {
      /* code */
      r->next = a;
      r = a;
      a = a->next;
    } else {
      r->next = b;
      r = b;
      b = b->next;
    }
  }
  if (a) {
    /* code */
    r->next = a;
  } else {
    r->next = b;
  }
  free(B);
  return New;
}

int main() {
  /* 注意创建(CreateFrom)方法的调用 */
  LinkList head;
  init(&head);
  // CreateFromHead(head);
  CreateFromTail(head);
  print(head);
  SearchByIndex(head, 6);
  SearchKey(head, '4');
  printf("链表长度:%d\n", ListLength(head));
  DeleteList(head, 6);
  printf("删除后：");
  print(head);
  InsertList(head, 6, '4');
  printf("插入后：");
  print(head);
  printf("合并有序表");

  /* part2顺序表的合并
  书上例子为(2,2,3),(1,3,3,4),合并成功
  */
  LinkList two;
  init(&two);
  // CreateFromHead(two);
  CreateFromTail(two);
  Node *merge = MergeList(head, two);
  printf("合并后链表为");
  print(merge);
  Destroy(head);
  printf("链表长度：%d",ListLength(head));
}