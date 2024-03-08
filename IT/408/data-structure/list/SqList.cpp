/*
    顺序表
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

#define MaxSize 30
#define InitSize 10

//静态分配
typedef struct {
    int length; //长度
    ElemType data[MaxSize];
} SqList;

//动态分配
typedef struct {
    int length; //长度
    int size;   //容量
    ElemType *data;
} DSqList;

//静态分配，初始化
void InitList(SqList &L) {
    L.length = 0;
}

//动态分配，初始化
bool InitList_dynamic(DSqList &L) {
    L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
    if (L.data == NULL)
        return false;
    L.size = InitSize;
    L.length = 0;
    return true;
}

//动态分配，扩容
bool IncreaseList_dynamic(DSqList &L, int len) {
    ElemType *p = L.data;
    L.data = (ElemType*)malloc(sizeof(ElemType)*(L.size+len));
    if (L.data == NULL)
        return false;
    memcpy(L.data, p, sizeof(ElemType)*L.size);
    L.size += len;
    free(p);
    return true;
}

//静态分配，遍历打印
void PrintList(SqList &L) {
    for (int i=0; i<L.length; i++) {
        printf("%d", L.data[i]);
        if (i != L.length-1)
            printf(",");
    }
    printf("\n");
}

//动态分配，遍历打印
void PrintList_dynamic(DSqList &L) {
    for (int i=0; i<L.length; i++) {
        printf("%d", L.data[i]);
        if (i != L.length-1)
            printf(",");
    }
    printf("\n");
}

//静态分配，插入
bool InsertList(SqList &L, int k, ElemType e) {
    if (k<1 || k>L.length+1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int i=L.length; i>=k; i--)  //第k个及之后的元素全部后移一位
        L.data[i] = L.data[i-1];
    L.data[k-1] = e;
    L.length++;
    return true;
}

//动态分配，插入
bool InsertList_dynamic(DSqList &L, int k, ElemType e) {
    if (k<1 || k>L.length+1)
        return false;
    if (L.length >= L.size)
        return false;
    for (int i=L.length; i>=k; i--)   //第k个及之后的元素全部后移一位
        L.data[i] = L.data[i-1];
    L.data[k-1] = e;
    L.length++;
    return true;
}

//静态分配，删除
bool DeleteList(SqList &L, int k, ElemType &e) {
    if (k<1 || k>L.length)
        return false;
    e = L.data[k-1];
    for (int i=k; i<L.length; i++)
        L.data[i-1] = L.data[i];    //第k个之后的元素全部前移一位
    L.length--;
    return true;
}

//动态分配，删除
bool DeleteList_dynamic(DSqList &L, int k, ElemType &e) {
    if (k<1 || k>L.length)
        return false;
    e = L.data[k-1];
    for (int i=k; i<L.length; i++)
        L.data[i-1] = L.data[i];    //第k个之后的元素全部前移一位
    L.length--;
    return true;
}

//静态分配，获取指定位序的元素
bool GetListElem(SqList &L, int k, ElemType &e) {
    if (k<1 || k>L.length)
        return false;
    e = L.data[k-1];
    return true;
}

//动态分配，获取指定位序的元素
bool GetListElem_dynamic(DSqList &L, int k, ElemType &e) {
    if (k<1 || k>L.length)
        return false;
    e = L.data[k-1];
    return true;
}

//静态分配，获取指定元素的位序
int LocateListElem(SqList &L, ElemType &e) {
    for (int i=1; i<=L.length; i++)
        if (L.data[i-1] == e)
            return i;
    return 0;
}

//动态分配，获取指定元素的位序
int LocateListElem_dynamic(DSqList &L, ElemType &e) {
    for (int i=1; i<=L.length; i++)
        if (L.data[i-1] == e)
            return i;
    return 0;
}

//静态分配，清空
void ClearList(SqList &L) {
    L.length = 0;
}

//动态分配，清空
void ClearList_dynamic(DSqList &L) {
    L.length = 0;
}

//静态分配的顺序表演示
int SqListDemo() {
    printf("顺序表（静态分配）演示：\n");
    SqList L;
    InitList(L);
    printf("\t初始化完成，当前长度[%d]\n", L.length);
    for (int i=1; i<=5; i++)
        InsertList(L, L.length+1, i);
    printf("\t插入数据完成，当前长度[%d]，遍历打印：", L.length);
    PrintList(L);
    InsertList(L, 3, 10);
    printf("\t第3位插入10后长度[%d]，遍历打印：", L.length);
    PrintList(L);
    ElemType e;
    GetListElem(L, 2, e);
    printf("\t获取第2个元素[%d]\n", e);
    e = 4;
    printf("\t值为4的元素的位序是[%d]\n", LocateListElem(L, e));
    DeleteList(L, 3, e);
    printf("\t删除第3位元素[%d]后长度[%d]，遍历打印：", e, L.length);
    PrintList(L);
    ClearList(L);
    printf("\t清空列表后长度[%d]\n", L.length);
    return 0;
}

//动态分配的顺序表演示
int SqListDemo_dynamic() {
    printf("顺序表（动态分配）演示：\n");
    DSqList L;
    InitList_dynamic(L);
    printf("\t初始化完成，当前长度[%d]，当前容量[%d]\n", L.length, L.size);
    for (int i=1; i<=5; i++)
        InsertList_dynamic(L, L.length+1, i);
    printf("\t插入数据完成，当前长度[%d]，遍历打印：", L.length);
    PrintList_dynamic(L);
    InsertList_dynamic(L, 3, 10);
    printf("\t第3位插入10后长度[%d]，遍历打印：", L.length);
    PrintList_dynamic(L);
    ElemType e;
    GetListElem_dynamic(L, 2, e);
    printf("\t获取第2个元素[%d]\n", e);
    e = 4;
    printf("\t值为4的元素的位序是[%d]\n", LocateListElem_dynamic(L, e));
    DeleteList_dynamic(L, 3, e);
    printf("\t删除第3位元素[%d]后长度[%d]，遍历打印：", e, L.length);
    PrintList_dynamic(L);
    for (int i=6; i<=20; i++)
        InsertList_dynamic(L, L.length+1, i);
    printf("\t因容量不足，尾部插入6到20失败，当前长度[%d]，容量[%d]，遍历打印：", L.length, L.size);
    PrintList_dynamic(L);
    IncreaseList_dynamic(L, 10);
    for (int i=11; i<=20; i++)
        InsertList_dynamic(L, L.length+1, i);
    printf("\t扩容10个长度的容量，尾部插入11~20，当前长度[%d]，容量[%d]，遍历打印：", L.length, L.size);
    PrintList_dynamic(L);
    ClearList_dynamic(L);
    printf("\t清空列表后长度[%d]\n", L.length);
    return 0;
}

//顺序表题目一：从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。
bool DeleteMin(SqList &L, ElemType &e) {
    if (L.length <= 0)
        return false;
    e = L.data[0];  //初始记录第1个元素
    int k = 1;  //当前记录的元素的位序
    for (int i=2; i<=L.length; i++) {   //从第2个元素开始比较
        if (L.data[i-1] < e) {  //小于当前记录则替换
            e = L.data[i-1];
            k = i;
        }
    }
    L.data[k-1] = L.data[L.length-1];
    L.length--;
    return true;
}
int DeleteMinDemo() {
    SqList L;
    InitList(L);
    InsertList(L, 1, 3);
    InsertList(L, 2, 2);
    InsertList(L, 3, 1);
    InsertList(L, 4, 2);
    InsertList(L, 5, 3);
    PrintList(L);
    ElemType e;
    if (DeleteMin(L, e)) {
        printf("DeleteMin success. Delete [%d].\n", e);
        PrintList(L);
    }
    else
        printf("DeleteMin failed.\n");
    return 0;
}

//顺序表题目二：设计一个高效的算法，将顺序表的所有元素逆置，要求算法的空间复杂度为O(1)。
void Reverse(SqList &L) {
    ElemType tmp;
    for (int i=1; i<=L.length/2; i++) {
        tmp = L.data[i-1];
        L.data[i-1] = L.data[L.length-i];
        L.data[L.length-i] = tmp;
    }
}
int ReverseDemo() {
    SqList L;
    InitList(L);
    InsertList(L, 1, 1);
    InsertList(L, 2, 3);
    InsertList(L, 3, 5);
    InsertList(L, 4, 7);
    InsertList(L, 5, 9);
    PrintList(L);
    Reverse(L);
    PrintList(L);
    return 0;
}

//顺序表题目三：长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素。
void DeleteAllElem(SqList &L, ElemType e) {
    int mark = 0;
    for (int i=1; i<=L.length; i++) {
        if (L.data[i-1] == e)
            mark += 1;
        else
            L.data[i-1-mark] = L.data[i-1];
    }
    L.length -= mark;
}
int DeleteAllElem() {
    SqList L;
    InitList(L);
    InsertList(L, 1, 1);
    InsertList(L, 2, 2);
    InsertList(L, 3, 3);
    InsertList(L, 4, 2);
    InsertList(L, 5, 5);
    InsertList(L, 6, 2);
    PrintList(L);
    DeleteAllElem(L, 2);
    PrintList(L);
    return 0;
}

//顺序表题目四：从有序顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素，如果s或t不合理或者顺序表为空则显示出错信息并退出运行
bool DeleteStoT(SqList &L, int s, int t) {
    if (s>=t || L.length==0) {  //题目要求，实际不需要，因为下面的算法会覆盖异常情况
        printf("参数s或t不合理，或顺序表为空，本程序退出！\n");
        return false;
    }
    int mark = 0;
    for (int i=1; i<=L.length; i++) {
        int tmp = L.data[i-1];
        if (s<=L.data[i-1] && L.data[i-1]<=t)
            mark += 1;
        else
            L.data[i-1-mark] = L.data[i-1];
    }
    L.length -= mark;
    return true;
}
int DeleteStoTDemo() {
    SqList L;
    InitList(L);
    for (int i=1; i<=5; i++)
        InsertList(L, L.length+1, i*2);
    printf("初始化：");
    PrintList(L);
    int s = 5;
    int t = 9;
    DeleteStoT(L, s, t);
    printf("删除%d~%d后：", s, t);
    PrintList(L);
    return 0;
}

//顺序表题目四：从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
void DeleteDuplicate(SqList &L) {
    int mark = 0;
    for (int i=1; i<L.length; i++)  //从第2个元素开始，i是下标
        if (L.data[i] == L.data[i-1])
            mark += 1;
        else
            L.data[i-mark] = L.data[i];
    L.length -= mark;
}
int DeleteDuplicateDemo() {
    SqList L;
    InitList(L);
    for (int i=0; i<5; i++)
        for (int j=0; j<3; j++)
            InsertList(L, L.length+1, i);
    printf("初始化：");
    PrintList(L);
    DeleteDuplicate(L);
    printf("去重后：");
    PrintList(L);
    return 0;
}

//顺序表题目五：将两个有序顺序表合并成一个新的有序顺序表，并由函数返回结果顺序表
bool MergeSqList(SqList &A, SqList &B, SqList &C) {
    if (A.length+B.length > MaxSize)
        return false;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i<A.length && j<B.length) {  //A和B都没遍历完毕时
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length)    //B已遍历完毕，A还有剩余时
        C.data[k++] = A.data[i++];
    while (j < B.length)    //A已遍历完毕，B还有剩余时
        C.data[k++] = B.data[j++];
    C.length = k;   //k虽然是小标，但上面最后的运算的k++，所以无需再+1
    return true;
}
int MergeSqListDemo() {
    SqList A, B, C;
    InitList(A);
    InitList(B);
    InitList(C);
    for (int i=1; i<=5; i++) {
        InsertList(A, A.length+1, i*2-1);
        InsertList(B, B.length+1, i*2);
    }
    printf("初始化A：");
    PrintList(A);
    printf("初始化B：");
    PrintList(B);
    MergeSqList(A, B, C);
    printf("合并后的C：");
    PrintList(C);
    return 0;
}

int main() {
    int ret = 0;
    //ret = SqListDemo();
    //ret = SqListDemo_dynamic();
    //ret = DeleteMinDemo();
    //ret = ReverseDemo();
    //ret = DeleteAllElem();
    //ret = DeleteStoTDemo();
    //ret = DeleteDuplicateDemo();
    ret = MergeSqListDemo();
    return ret;
}