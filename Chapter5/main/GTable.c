/**
 * @file GTable.c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 广义表
 *举例：{1，2，{3，4}，7，{8，9，10}}
 * @version 0.1
 * @date 2022-08-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef enum { Atom, List } ElemTag;
typedef char AtomType;

typedef struct GLNode {
  ElemTag tag; //标志位，0为原子，1为子表
  union {
    AtomType atom; //原子域
    struct {
      struct GLNode *hp, *tp;
    } ptr; //子表
  } atom_htp;
} GLNode, *GList;

void CreateAtom(GList L) {
  printf("输入原子节点值:");
  char atom;
  scanf("%c", &atom);
  GLNode *Atom;
  Atom=(GLNode *)malloc(sizeof(GLNode));
  Atom->tag=0;
  Atom->atom_htp.atom=atom;
  L->atom_htp.ptr.hp=Atom;
}

void CreateList(GList L){
   printf("输入子表元素");
   while (1) {
    GLNode *List;//首先创建子表
    List=(GLNode*)malloc(sizeof(GLNode));
    List->tag=1;
    List->atom_htp.ptr.hp=List->atom_htp.ptr.tp=NULL;//先置空两个指针
    Create();
   }
}

void Create(GList L) {
  printf("请输入序号选择创建类型: 0原子节点,1子表,输入其他数字将直接退出");
  int flag;
  scanf("%d", &flag);
  while (flag) {
    switch (flag) {
    case 0:
      CreateAtom(L);
    case 1:
      CreateList(L);
    default:
      break;
    }
  }
}

void Init(GList *L) {
  /* 创建一个主表 */
  *L = (GList)malloc(sizeof(GLNode));
  (*L)->tag = 1;
  (*L)->atom_htp.ptr.tp = (*L)->atom_htp.ptr.hp = NULL;
}

/**
 * @brief 求表头
 *
 * @param L 表头指针
 */
void GetListHead(GList L) {}
/**
 * @brief 求表尾
 *
 * @param L 表头指针
 */
void Tail(GList L) {}