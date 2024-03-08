/*
    双链表（带头）
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct DLNode {
    ElemType data;
    struct DLNode *prior;
    struct DLNode *next;
} DLNode, *DLinkList;

//初始化
bool InitList(DLinkList &L) {
    L = (DLNode*)malloc(sizeof(DLNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//判空
bool Empty(DLinkList &L) {
    return L->next == NULL;
}

//遍历打印
void PrintList(DLinkList &L) {
    DLNode *p = L->next;
    while(p != NULL) {
        printf("%d,", p->data);
        p = p->next;
    }
    printf("\n");
}

//前向遍历打印
void PrintList_prior(DLNode *p) {
    while(p->prior != NULL) {
        printf("%d,", p->data);
        p = p->prior;
    }
    printf("\n");
}

//指定结点后插入
bool InsertNextNode(DLNode *p, ElemType e) {
    DLNode *s = (DLNode*)malloc(sizeof(DLNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->prior = p;
    s->next = p->next;
    if(p->next != NULL)
        p->next->prior = s;
    p->next = s;
    return true;
}

//指定结点前插入
bool InsertPriorNode(DLNode *p, ElemType e) {
    //插入到指定结点的前驱结点的后面
    return InsertNextNode(p->prior, e);
}

//删除指定结点的后继结点
bool DeleteNextNode(DLNode *p) {
    if (p == NULL)
        return false;
    DLNode *d = p->next;
    if (d == NULL)
        return false;
    p->next = d->next;
    if (d->next != NULL)
        d->next->prior = p;
    free(d);
    return true;
}

//清空链表
void ClearList(DLinkList &L) {
    while (L->next != NULL)
        DeleteNextNode(L);
    //free(L);  //若是销毁，还需要释放头结点
    //L = NULL;
}

DLNode* GetListNode(DLinkList &L, ElemType e) {
    DLNode *p = L->next;
    while (p != NULL) {
        if (p->data == e)
            return p;
        p = p->next;
    }
    return NULL;
}

int DLinkListDemo() {
    printf("双向链表演示：\n");
    DLinkList L;
    InitList(L);
    for (int i=5; i>=1; i--)
        InsertNextNode(L, i);
    printf("\t初始化完成，遍历：");
    PrintList(L);
    DLNode *p = GetListNode(L, 3);
    printf("\t从元素3前向遍历：");
    PrintList_prior(p);
    ClearList(L);
    printf("\t清空列表，遍历：");
    PrintList(L);
    return 0;
}

int main() {
    int ret = 0;
    ret = DLinkListDemo();
    return ret;
}