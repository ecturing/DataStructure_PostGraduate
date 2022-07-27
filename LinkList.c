#include <stdio.h>
#include <malloc.h>
#include <termio.h>

typedef char Elemtype;

typedef struct Node
{
    Elemtype data;
    struct Node *next;
    /* data */
} Node, *LinkList;

/**
 * @brief 链表初始化
 *
 * @param L 头指针
 */
void init(LinkList *L){
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

/**
 * @brief 头插入法
 *
 * @param L 头指针
 */
void CreateFromHead(LinkList L){
    Node*p=L->next;
    printf("请开始输入数字，并输入$结束\n");
    Node *pre;
    char c;
    int flag = 1;
    while (flag){
        /* code */
        scanf("%c",&c);
        if (c != '$'){
            /* code */
            pre = (Node *)malloc(sizeof(Node));
            pre->data = c;
            pre->next = L->next;
            L->next = pre;
        }
        else{
            flag = 0;
        }
    }
}
/**
 * @brief 尾插法
 * 
 * @param L 头指针
 */
int CreateFromTail(LinkList L){
}

/**
 * @brief 根据节点号搜索节点值
 * 
 * @param index 节点号（从0开始）
 * @return Elemtype 节点值
 */
Elemtype SearchByIndex(LinkList L, int index){
    if (index < 0){
        /* code */
        return -1;
    }
    int status=0; //标识索引，标识当前遍历到第status个节点
    Node *result=L; //结果节点
    while ((result->next != NULL) && (status < index)){
        /* code */
        result = result->next;
        status++;
    }
    if (index == status){
        /* code */
        return result->data;
    }
    else{
        return -1;
    }
}
/**
 * @brief 查找节点值为key的节点元素
 * 
 * @param L 头节点
 * @param key 节点值
 * @return Node* 返回的节点元素
 */
Node* SearchKey(LinkList L,Elemtype key){
    Node *result;
    result=L->next;
    while (result!=NULL)
    {
        /* code */
        if (result->data!=key){
            /* code */
            result=result->next;
        }else{
            break;
            return result;
        }
    }
}

/**
 * @brief 求链表长度
 * 
 * @param L 头指针
 * @return int 链表长度
 */
int ListLength(LinkList L){
    Node *index;
    index=L->next;
    int length=0;
    while (index!=NULL){
        /* code */
        index=index->next;
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
int InsertList(LinkList L,int Index,Elemtype value){
    Node* NewNode,* pre=L;
    int i=0;
    if (Index<0){
        /* code */
        return -1;
    }
    while (pre!=NULL&&i<Index-1)
    {
        /* code */
        pre=pre->next;
        i++;
    }
    if (pre==NULL){
        /* code */
        return -1;
    }else{
        NewNode=(Node*)malloc(sizeof(Node));
        NewNode->data=value;
        NewNode->next=pre->next;
        pre->next=NewNode;
        return 1;      
    }
}
/**
 * @brief 指定位置删除元素
 * 
 * @param L 头指针
 * @param Index 插入点
 */
int DeleteList(LinkList L,int Index){
    Node* pre=L,*Del;
    int i=0;
    while (pre->next!=NULL&&i<Index-1)
    {
        /* code */
        pre=pre->next;
        i++;
    }
    if (pre->next==NULL)
    {
        /* code */
        return -1;
    }else{
        Del=pre->next;
        pre->next=Del->next;
        free(Del);
    }  
}
/**
 * @brief 打印链表
 * 
 * @param L 头节点
 */
void print(LinkList L){
    Node *Index=L->next;
    while (Index!=NULL){
        /* code */
        printf("%c",Index->data);
        Index=Index->next;
    }
    printf("\n");
}


int main(){
    Node *head;
    init(&head);
    CreateFromHead(head);
    print(head);
    Elemtype a= SearchByIndex(head,6);
    printf("搜索结果%c\n",a);
    Node *p=SearchKey(head,'4');
    printf("链表长度:%d\n",ListLength(head));
    DeleteList(head,6);
    print(head);
    InsertList(head,6,'4');
    print(head);
}