/*
    循环单链表（带头）
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct CLNode {
    ElemType data;
    struct CLNode *next;
} CLNode, *CLinkList;

//初始化
bool InitList(CLinkList &L) {
    L = (CLNode*)malloc(sizeof(CLNode));
    if (L == NULL)
        return false;
    L->next = L;    //头结点的next指向自身
    return true;
}

//判空
bool Empty(CLinkList &L) {
    return L->next == L;
}

//判断指定结点是否尾巴结点
bool IsTail(CLinkList &L, CLNode *p) {
    return p->next == L;
}

//遍历打印
void PrintList(CLinkList &L) {
    CLNode *p = L->next;
    while (p != L) {
        printf("%d,", p->data);
        p = p->next;
    }
    printf("\n");
}

//在指定结点后插入
bool InsertNextNode(CLNode *p, ElemType e) {
    if (p == NULL)
        return false;
    CLNode *s = (CLNode*)malloc(sizeof(CLNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//在指定结点前插入
bool InsertPriorNode(CLNode *p, ElemType e) {
    //单链表无法直接插到指定结点前面，但可以插到后面，然后交换两者的数据
    if (!InsertNextNode(p, e))
        return false;
    p->next->data = p->data;
    p->data = e;
}

//删除指定结点的后继结点
bool DeleteNextNode(CLNode *p) {
    if (p == NULL)
        return false;
    CLNode *d = p->next;    //待删除的结点（循环链表中任何结点的next都不会指向NULL）
    p->next = d->next;
    free(d);
    return true;
}

//清空
void ClearList(CLinkList &L) {
    while (L->next != L)
        DeleteNextNode(L);
}

//按内容查找节点
CLNode* GetListNode(CLinkList &L, ElemType e) {
    CLNode *p = L->next;
    while (p != L) {
        if (p->data == e)
            return p;
        p = p->next;
    }
    return NULL;
}

int CLinkListDemo() {
    printf("循环单链表（带头）演示：\n");
    CLinkList L = NULL;
    InitList(L);
    printf("\t初始化完成，是否为空[%d]\n", Empty(L));
    InsertNextNode(L, 3);
    InsertNextNode(L, 2);
    InsertNextNode(L, 1);
    printf("\t插入1~3，是否为空[%d]，遍历：", Empty(L));
    PrintList(L);
    CLNode *p = GetListNode(L, 2);
    printf("\t获取内容为2的结点，其值为：%d\n", p->data);
    InsertNextNode(p, 10);
    printf("\t在2后面插入10，遍历：");
    PrintList(L);
    DeleteNextNode(p);
    printf("\t删除2后面的结点，遍历：");
    PrintList(L);
    ClearList(L);
    printf("\t清空链表，是否为空[%d]，遍历：", Empty(L));
    return 0;
}


int main() {
    int ret = CLinkListDemo();
    return ret;
}