#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0

typedef char Elemtype;

typedef struct
{
    /* data */
    Elemtype data[MAXSIZE];//数据域
    int last;//最后一个元素的数组下标
}SeqList;

/**
 * @brief 按元素查找
 * 
 * @param L 线性表 
 * @param e 元素值
 * @return int 节点下标
 */
int locate(SeqList *L,Elemtype e){
    while (1)
    {
        /* code */
        int index=L->last;
        if(L->data[index--]==e){
            if (index==-1){
                printf("无此值");
                break;
            }else{
                return L->last;
                break;
            }
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
int InsList(SeqList *L,int i,Elemtype e){
    if (i>L->last+2&&i<0)
    {
        /* code */
        printf("插入位置不合法");
        return ERROR;
    }else{
        if (L->last>=MAXSIZE-1)
        {
            /* code */
            printf("表满，无法插入");
            return ERROR;
        }else{
            for (int i = L->last; i>=i-1; i--)
            {
                /* code */
                L->data[i+1]=L->data[i];
            }
            L->data[i-1]=e;
            L->last++;
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
int DelList(SeqList *L,int i,Elemtype *e){
    if (i>L->last+1||i<0)
    {
        /* code */
        printf("删除位置不合法");
        return ERROR;
    }else{
        *e=L->data[i-1];//待删除元素
        for (int i = 0; i <= L->last; i++){
            /* code */
            L->data[i-1]=L->data[i];
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
void MergeLsit(SeqList La,SeqList Lb,SeqList Lc){

}
/**
 * @brief 链表初始化
 * 
 * @param L 
 */
void Init(SeqList **L){
    *L=(SeqList*)malloc(sizeof(SeqList));
    (*L)->last=-1;//空表置-1
}
/**
 * @brief 顺序表构造
 * 
 * @param q 顺序表
 */

void Create(SeqList *q){
    int flag=1;
    char c;
    printf("开始输入字符");
    while (flag)
    {
           /* code */
           scanf("%c",&c);
           if (c!='$'){
            /* code */
            q->data[++q->last]=c;
           }else{
            flag=0;
           }
    }
    
}
/**
 * @brief 打印顺序表
 * 
 * @param q 顺序表
 */
void print(SeqList *q){ 
    print("打印顺序表(倒序)");
    while (1){
        /* code */
        int index=q->last;
        printf("%c",q->data[index--]);
        if (q->last==-1){
            /* code */
            break;
        }   
    } 
}

int main(){
    SeqList *q;
    Init(&q);
    Create(q);
    print(q);
}