/**
 * @file CLinkList.c
 * @author ecturing (Ecturing@vip.qq.com)
 * @brief 循环链表
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<malloc.h>

typedef char Elemtype;

typedef struct Node
{
    Elemtype data;//数据域
    struct Node *next;//指针域
    /* data */
} Node, *LinkList;

/**
 * @brief 循环链表初始化
 * 
 * @param L 
 */
void Init(LinkList *L){
    *L=(Node*)malloc(sizeof(Node));
    (*L)->next=*L;
}
/**
 * @brief 循环链表创建
 * 
 * @param L 
 */
void CreateCList(LinkList L){
    Node *New;
    Node *tail=L;
    printf("开始输入字符");
    char c;
    int flag=1;
    while (flag)
    {
        /* code */
        scanf(" %c",&c);//避免缓冲区内\n被读取，参考来源：https://blog.csdn.net/as480133937/article/details/102625223
        if (c!='$')
        {
            /* code */
            New=(Node*)malloc(sizeof(Node));
            New->data=c;
            tail->next=New;
            tail=New;
        }else{
            flag=0;
        }
        
    }
    tail->next=L;
}

/**
 * @brief 
 * 
 * @param A 链表a
 * @param B 链表b
 * @return LinkList 新链表
 */
LinkList ListMerge(LinkList A,LinkList B){
    Node *aIndex,*bIndex;
    aIndex=A;
    bIndex=B;
    while (aIndex->next!=A)
    {
        /* code */
        aIndex=aIndex->next;
    }
    while (bIndex->next!=B)
    {
        /* code */
        bIndex=bIndex->next;
    }
    bIndex->next=A;
    aIndex->next=B->next;
    free(B);
    return A;
}
/**
 * @brief 链表打印
 * 
 * @param L 
 */
void Listprint(LinkList L){
    printf("字符打印");
    Node *Index=L->next;
    while (Index!=L){
        /* code */
        printf("%c",Index->data);
        Index=Index->next;
    }
    printf("\n");
}

int main(){
    LinkList headOne,headTwo;
    Init(&headOne);
    Init(&headTwo);
    CreateCList(headOne);
    Listprint(headOne);
    CreateCList(headTwo);
    Node* NewList= ListMerge(headOne,headTwo);
    Listprint(NewList);
}