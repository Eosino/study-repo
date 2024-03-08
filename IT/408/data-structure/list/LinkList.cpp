/*
    单链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//带头链表，初始化
bool InitList(LinkList &L) {
    L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

//无头链表，初始化
bool InitList_headless(LinkList &L) {
    L = NULL;
    return true;
}

//带头链表，判空
bool Empty(LinkList &L) {
    return L->next == NULL;
}

//无头链表，判空
bool Empty_headless(LinkList &L) {
    return L == NULL;
}

//带头链表，遍历打印
void PrintList(LinkList &L) {
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d,", p->data);
        p = p->next;
    }
    printf("\n");
}

//无头链表，遍历打印
void PrintList_headless(LinkList &L) {
    LNode *p = L;
    while (p != NULL) {
        printf("%d,", p->data);
        p = p->next;
    }
    printf("\n");
}

//在指定结点后插入
bool InsertNextNode(LNode *p, ElemType e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//在指定结点前插入
bool InsertPriorNode(LNode *p, ElemType e) {
    //单链表无法直接插到指定结点前面，但可以插到后面，然后交换两者的数据
    if (!InsertNextNode(p, e))
        return false;
    p->next->data = p->data;
    p->data = e;
    return true;
}

//带头链表，指定位序插入
bool InsertList(LinkList &L, int k, ElemType e) {
    if (k < 1)
        return false;
    LNode *p = L->next; //当前扫描到的结点，带头链表从头结点的下一个结点开始
    int i = 1;  //当前扫描到的结点的位序
    while (i<k-1 && p!=NULL) {  //找到第k-1个结点
        p = p->next;
        i++;
    }
    if (p == NULL)
        return false;
    return InsertNextNode(p, e);
}

//无头链表，指定位序插入
bool InsertList_headless(LinkList &L, int k, ElemType e) {
    if (k < 1)
        return false;
    if (k == 1) {
        //无头链表需单独处理位序为1的情况
        LNode *s = (LNode*)malloc(sizeof(LNode));
        if (s == NULL)
            return false;
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p = L;   //当前扫描到的结点，无头链表从头开始
    int i = 1;  //当前扫描到的结点的位序
    while (i<k-1 && p!=NULL) {  //找到第k-1个结点
        p = p->next;
        i++;
    }
    if (p == NULL)
        return false;
    return InsertNextNode(p, e);
}

//删除指定结点的后继结点
bool DeleteNextNode(LNode *p) {
    if (p == NULL)
        return false;
    LNode *d = p->next;
    if (d == NULL)
        return false;
    p->next = d->next;
    free(d);
    return true;
}

//带头链表，清空
void ClearList(LinkList &L) {
    while (L->next != NULL)
        DeleteNextNode(L);
    //free(L);  //若是销毁，还需要释放头结点
    //L = NULL;
}

//无头链表，清空
void ClearList_headless(LinkList &L) {
    while (L->next != NULL)
        DeleteNextNode(L);
    free(L);
    L = NULL;
}

//带头链表，指定位序删除
bool DeleteList(LinkList &L, int k, ElemType &e) {
    if (k < 1)
        return false;
    LNode *p = L->next; //当前扫描到的结点，带头链表从头结点的下一个结点开始
    int i = 1;  //当前扫描到的结点的位序
    while (i<k-1 && p!=NULL)    //找到第k-1个结点
        p = p->next;
    if (p == NULL)
        return false; 
    e = p->next->data;
    DeleteNextNode(p);
    return true;
}

//无头链表，指定位序删除
bool DeleteList_headless(LinkList &L, int k, ElemType &e) {
    if (k < 1)
        return false;
    if (k == 1) {
        //无头链表需单独处理位序为1的情况
        LNode *d = L;   //待删除的结点
        e = d->data;
        L = d->next;
        free(d);
        return true;
    }
    LNode *p = L; //当前扫描到的结点，无头链表从头开始
    int i = 1;  //当前扫描到的结点的位序
    while (i<k-1 && p!=NULL)    //找到第k-1个结点
        p = p->next;
    if (p == NULL)
        return false; 
    e = p->next->data;
    DeleteNextNode(p);
    return true;
}

//尾插法生成一个带头链表
void TailInsert(LinkList &L) {
    LNode *s = NULL;    //待插入结点的指针
    LNode *r = L;   //尾指针
    ElemType e; //待插入的数据
    for (int i=1; i<=5; i++) {  //i是位序
        s = (LNode*)malloc(sizeof(LNode));
        e = i;
        s->data = e;
        s->next = NULL;
        r->next = s;
        r = s;
    }
}

//尾插法生成一个无头链表
void TailInsert_headless(LinkList &L) {
    LNode *s = NULL;    //待插入结点的指针
    LNode *r = L;   //尾指针
    ElemType e; //待插入的数据
    for (int i=1; i<=5; i++) {  //i是位序
        s = (LNode*)malloc(sizeof(LNode));
        e = i;
        s->data = e;
        s->next = NULL;
        if (i == 1) {
            //单独处理i为0的情况（与带头链表相比仅此不同）
            L = s;
            r = s;
            continue;
        }
        r->next = s;
        r = s;
    }
}

//头插法生成一个带头链表
void HeadInsert(LinkList &L) {
    LNode *s = NULL;    //待插入结点的指针
    ElemType e; //待插入的数据
    for (int i=5; i>=1; i--) {  //i是位序
        s = (LNode*)malloc(sizeof(LNode));
        e = i;
        s->data = e;
        s->next = L->next;
        L->next = s;
    }
}

//头插法生成一个无头链表
void HeadInsert_headless(LinkList &L) {
    LNode *s = NULL;    //待插入结点的指针
    ElemType e; //待插入的数据
    for (int i=5; i>=1; i--) {  //i是位序
        s = (LNode*)malloc(sizeof(LNode));
        e = i;
        s->data = e;
        if (Empty_headless(L)) {
            L = s;
            L->next = NULL;
            continue;
        }
        s->next = L;
        L = s;
    }
}

//头插法逆置一个带头链表
void ReverseList(LinkList &L) {
    LNode *s = NULL;
    LNode *p = L->next;
    LinkList L2 = NULL;
    InitList(L2);
    while (p != NULL) {
        s = p;
        p = p->next;
        s->next = L2->next;
        L2->next = s;
    }
    free(L);
    L = L2;
}

//头插法逆置一个无头链表
void ReverseList_headless(LinkList &L) {
    LNode *s = NULL;
    LNode *p = L;
    LinkList L2 = NULL;
    while (p != NULL) {
        s = p;
        p = p->next;
        s->next = L2;
        L2 = s;
    }
    L = L2;
}

//带头链表演示
int LinkListDemo() {
    printf("单链表（带头）演示：\n");
    LinkList L;
    if (!InitList(L))
        return -1;
    //false为0，true为1
    printf("\t初始化成功，链表是否为空：%d\n", Empty(L));
    TailInsert(L);
    printf("\t尾插法插入完成，链表是否为空：%d，遍历打印：", Empty(L));
    //HeadInsert(L);
    //printf("\t头插法插入完成，链表是否为空：%d，遍历打印：", Empty(L));
    PrintList(L);
    ReverseList(L);
    printf("\t使用头插法逆置后遍历打印：");
    PrintList(L);
    InsertList(L, 2, 100);
    printf("\t第2位插入100后遍历打印：");
    PrintList(L);
    ElemType e;
    DeleteList(L, 2, e);
    printf("\t删除第2位结点（%d），然后遍历打印：", e);
    PrintList(L);
    ClearList(L);
    printf("\t清空链表，遍历打印：");
    PrintList(L);
    return 0;
}

//无头链表演示
int LinkListDemo_headless() {
    printf("单链表（无头）演示：\n");
    LinkList L;
    if (!InitList_headless(L))
        return -1;
    //false为0，true为1
    printf("\t初始化成功，链表是否为空：%d\n", Empty_headless(L));
    TailInsert_headless(L);
    printf("\t尾插法插入完成，链表是否为空：%d，遍历打印：", Empty_headless(L));
    //HeadInsert_headless(L);
    //printf("\t头插法插入完成，链表是否为空：%d，遍历打印：", Empty_headless(L));
    PrintList_headless(L);
    ReverseList_headless(L);
    printf("\t使用头插法逆置后遍历打印：");
    PrintList_headless(L);
    InsertList_headless(L, 2, 100);
    printf("\t第2位插入100后遍历打印：");
    PrintList_headless(L);
    ElemType e;
    DeleteList_headless(L, 2, e);
    printf("\t删除第2位结点（%d），然后遍历打印：", e);
    PrintList_headless(L);
    ClearList_headless(L);
    printf("\t清空链表，遍历打印：");
    PrintList_headless(L);
    return 0;
}

int main() {
    int ret = 0;
    ret = LinkListDemo();
    //ret = LinkListDemo_headless();
    return ret;
}