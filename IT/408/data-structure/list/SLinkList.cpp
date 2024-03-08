/*
    静态链表（带头），以数组方式实现的链表
    优点：相比数组和顺序表增删不需要大量移动元素
    缺点：不能随机存取；容量固定不变
    场景：当前已少见，主要用于：
        1、不支持指针的低级语言；
        2、数据元素数量固定不变的场景（如操作系统的文件分配表FAT）；
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

#define MaxSize 10

typedef struct {
    ElemType data;
    int next;   //下个结点的下标
} SLNode, SLinkList[MaxSize];

//初始化
void InitList(SLinkList &L) {
    //下标为0的是头结点
    //next为-1的是尾结点
    //next为-2的是空结点
    L[0].next = -1;
    for (int i=1; i<MaxSize; i++)
        L[i].next = -2;
}

//判空
bool Empty(SLinkList &L) {
    return L[0].next == -1;
}

//遍历打印
void PrintList(SLinkList &L) {
    int i = L[0].next;
    while (i != -1) {
        printf("%d,", L[i]);
        i = L[i].next;
    }
    printf("\n");
}

//获取一个空结点，返回的是下标
bool GetNULLNode(SLinkList &L, int &i) {
    for (int j=1; j<MaxSize; j++)
        if (L[j].next == -2) {
            i = j;
            return true;
        }
    //满了
    return false;
}

//获取指定位序结点的下标
bool GetListNode(SLinkList &L, int k, int &i) {
    if (k == 0) {
        i = 0;
        return true;
    }
    if (k<0 || k>MaxSize-1) //位序无效
        return false;
    i = L[0].next;
    int j = 1;
    while (j<k && i!=-1) {
        i = L[i].next;  //找到第k个结点，i为其下标
        j++;
    }
    if (i == -1)
        return false;
    return true;
}

//在第k位插入新元素
bool InsertList(SLinkList &L,int k, ElemType e) {
    int i;
    if (!GetListNode(L, k-1, i))
        return false;
    int s;
    if (!GetNULLNode(L, s))
        return false;
    L[s].data = e;
    L[s].next = L[i].next;
    L[i].next = s;
    return true;
}

//删除第k位元素
bool DeleteList(SLinkList &L,int k) {
    int i;
    if (!GetListNode(L, k-1, i))    //找到第k-1位，下标赋值给i
        return false;
    int c = L[i].next;  //第k位
    if (c != -1)
        L[i].next = L[c].next;
    else
        L[i].next = -1;
    L[c].next = -2;
    return true;
}

//清空
void ClearList(SLinkList &L) {
    InitList(L);
}

int SLinkListDemo() {
    printf("静态链表（带头）演示：\n");
    SLinkList L;
    InitList(L);
    printf("\t初始化完成，为空[%d]，遍历：", Empty(L));
    PrintList(L);
    InsertList(L, 1, 3);
    InsertList(L, 1, 2);
    InsertList(L, 1, 1);
    printf("\t插入1~3，为空[%d]，遍历：", Empty(L));
    PrintList(L);
    InsertList(L, 2, 10);
    printf("\t第2位插入10，遍历：");
    PrintList(L);
    DeleteList(L, 3);
    printf("\t删除第3位，遍历：");
    PrintList(L);
    ClearList(L);
    printf("\t清空，为空[%d]，遍历：", Empty(L));
    PrintList(L);
    return 0;
}

int main() {
    int ret = SLinkListDemo();
    return ret;
}