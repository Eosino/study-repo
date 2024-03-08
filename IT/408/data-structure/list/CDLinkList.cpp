/*
    循环双链表（带头）
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct CDLNode {
    ElemType data;
    struct CDLNode *prior;
    struct CDLNode *next;
} CDLNode, *CDLinkList;

//初始化
bool InitList(CDLinkList &L) {
    L = (CDLNode*)malloc(sizeof(CDLNode));
    if (L == NULL)
        return false;
    L->prior = L;
    L->next = L;
    return true;
}

//判空
bool Empty(CDLinkList &L) {
    return L->next == L;
}

//判断指定结点是否尾结点
bool IsTail(CDLinkList &L, CDLNode *p) {
    return p->next == L;
}

//遍历打印
void PrintList(CDLinkList &L) {
    CDLNode *p = L->next;
    while (p != L) {
        printf("%d,", p->data);
        p = p->next;
    }
    printf("\n");
}

//反向遍历
void PrintList_reverse(CDLinkList &L) {
    CDLNode *p = L->prior;
    while (p != L) {
        printf("%d,", p->data);
        p = p->prior;
    }
    printf("\n");
}

//在指定结点后插入
bool InsertNextNode(CDLNode *p, ElemType e) {
    if (p == NULL)
        return false;
    CDLNode *s = (CDLNode*)malloc(sizeof(CDLNode));
    if (s == NULL)
        return false;
    s->data =e;
    s->prior = p;
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    return true;
}

//在指定结点前插入
bool InsertPriorNode(CDLNode *p, ElemType e) {
    return InsertNextNode(p->prior, e);
}

//删除指定结点
bool DeleteNode(CDLNode *p) {
    if (p==NULL || p->next==p)  //不能为空，不能删除头结点
        return false;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return true;
}

//清空
void ClearList(CDLinkList &L) {
    while (!Empty(L))
        DeleteNode(L->next);
}

//按内容获取结点
CDLNode* GetListNode(CDLinkList L, ElemType e) {
    CDLNode *p = L->next;
    while (p != L) {
        if (p->data == e)
            return p;
        p = p->next;
    }
    return NULL;
}

int CDLinkListDemo() {
    printf("循环双链表（带头）演示：\n");
    CDLinkList L = NULL;
    InitList(L);
    printf("\t初始化完成，为空[%d]，遍历：", Empty(L));
    PrintList(L);
    InsertNextNode(L, 3);
    InsertNextNode(L, 2);
    InsertNextNode(L, 1);
    printf("\t插入1~3后，为空[%d]，遍历：", Empty(L));
    PrintList(L);
    printf("\t反向遍历：");
    PrintList_reverse(L);
    CDLNode *p = GetListNode(L, 2);
    InsertNextNode(p, 10);
    printf("\t获取值为2的结点，其值为[%d]，在其后插入10，然后遍历：", p->data);
    PrintList(L);
    DeleteNode(p->next);
    printf("\t删除2后面的结点，遍历：");
    PrintList(L);
    ClearList(L);
    printf("\t清空，为空[%d]，遍历：", Empty(L));
    PrintList(L);
    return 0;
}

int main() {
    int ret = CDLinkListDemo();
    return ret;
}