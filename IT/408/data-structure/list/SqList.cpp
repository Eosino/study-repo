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

//顺序表题目六：已知在一维数组L[m+n]中依次存放着两个线性表（a1,a2,...,am）和（b1,b2,...,bn）；
//试编写一个函数，将数组中两个顺序表的位置互换，即将（b1,b2,...,bn）放到（a1,a2,...,am）的前面。
//原理：先逆置L变为（bn,...b2,b1,am,...,a2,a1），再分别逆置b和a即可得（b1,b2,...,bn,a1,a2,...,am）
//Reverse2：逆置顺序表L的第s位到第t位
bool ReversePos(SqList &L, int s, int t) {
    if (s<1 || s>t || t>L.length)
        return false;
    ElemType tmp;
    int mid = (s+t)/2;
    for (int i=0; i<=mid-s; i++) {  //这里的i表示偏移量，从s开始最大偏移到mid
        //s向前偏移i，其对应要交换的目标就是t向后偏移i
        //因为这里都是位序，所以还需要-1才是下标
        tmp = L.data[s+i-1];
        L.data[s+i-1] = L.data[t-i-1];
        L.data[t-i-1] = tmp;
    }
    return true;

}
void SwapList(SqList &L, int m, int n) {
    //初始为（a1,a2,...,am,b1,b2,...,bn）
    ReversePos(L, 1, L.length); //逆置整个L，结果为：（bn,...b2,b1,am,...,a2,a1）
    PrintList(L);
    ReversePos(L, 1, n);    //逆置L的第1位到第n位，结果为：（b1,b2,...,bn,am,...,a2,a1）
    PrintList(L);
    ReversePos(L, n+1, m+n);    //逆置L的第n+1位到最后一位，结果为：（b1,b2,...,bn,a1,a2,...,am）
    PrintList(L);
}
int SwapListDemo() {
    SqList L;
    InitList(L);
    int m = 4;
    int n = 6;
    int i;
    for (i=1; i<=m; i++)
        InsertList(L, L.length+1, i);
    for (i=1; i<=n; i++)
        InsertList(L, L.length+1, i+10);
    printf("初始化：");
    PrintList(L);
    SwapList(L, m, n);
    printf("交换后：");
    PrintList(L);
    return 0;
}

/*
顺序表题目七：
    设将n(n>1)个整数存放到一维数组R中。试设计一个在时间和空间两方面都尽可能高效的算法。将R中保存的序列循环左移p(0<p<n)个位置，
即将R中的数据由(X0,X1,...,Xn-1)变换为(Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1)。要求：
    1. 给出算法的基本设计思想。
    2. 根据设计思想，采用C、C++或Java语言描述算法，关键之处给出注释。
    3. 说明所设计算法的时间复杂度和空间复杂度。

答：1. 将R看成A、B两个数组，其中A(X0,X1,...,Xp-1)、B(Xp,Xp+1,...,Xn-1)，则该题就是要将AB变换为BA，需要的步骤是：
       将(AB)逆置，得(B逆A逆)；然后分别逆置（B逆）和（A逆）即可得（BA）。
    2. 见下方ReverseList和ReverseListDemo。
    3. 时间复杂度为O(n)，空间复杂度为O(1)。
*/
//bool ReverseList(SqList &L, int from, int to) {
    //if (from<0 || from>to || to>L.length-1)
void ReverseArray(int R[], int from, int to) {
    int tmp;
    for (int i=0; i<=(to-from)/2; i++) {
        tmp = R[from+i];
        R[from+i] = R[to-i];
        R[to-i] = tmp;
    }
}
void PrintArray(int R[], int n) {
    for (int i=0; i<n; i++)
        printf("%d,", R[i]);
    printf("\n");
}
int ReverseArrayDemo() {
    int R[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    printf("初始化：");
    PrintArray(R, n);
    int p = 3;
    ReverseArray(R, 0, p-1);
    printf("逆置(A)得(A逆B)：");
    PrintArray(R, n);
    ReverseArray(R, p, n-1);
    printf("逆置(B)得(A逆B逆)：");
    PrintArray(R, n);
    ReverseArray(R, 0, n-1);
    printf("逆置(A逆B逆)得(BA)：");
    PrintArray(R, n);
    return 0;
}

/*
顺序表题目八：
    一个长度L(L>=1)的升序序列S，处在第[L/2]个位置的数称为S的中位数。例如，若序列S1=(11,13,15,17,19)，则S1的中位数是15；
两个序列的中位数是含它们所有元素的升序序列的中位数。例如，若S2=(2,4,6,8,20)，则S1和S2的中位数是11。
    现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。要求：
    1. 给出算法的基本设计思想。
    2. 根据设计思想，采用C、C++或Java语言描述算法，关键之处给出注释。
    3. 说明你所设计算法的时间复杂度和空间复杂度。

答：最优算法：通过两个序列各自求中位数，然后比较，舍弃小于较小中位数的部分和大于较大中位数的部分，直到两者相等，或只剩一个元素，较小者为中位数。
        时间O(log2n)，空间O(1)。
    次优算法：类比归并排序的思想但不实现归并，仅按顺序访问对比，访问到[L/2]即为所求。（推荐）
        时间O(n)，空间O(1)。
    最易算法：归并排序，定位中位数。
        时间O(n)，空间O(n)。
*/
int FindMedian_optimal(int A[], int B[], int n) {
    int s1=0, m1, d1=n-1;   //序列A的首位数、中位数、末位数
    int s2=0, m2, d2=n-1;   //序列B的首位数、中位数、末位数
    while (s1!=d1 || s2!=d2) {
        m1 = (s1+d1)/2;
        m2 = (s2+d2)/2;
        if (A[m1] == B[m1]) //两个序列的中位数相等，那这个就是两个序列的中位数
            return A[m1];
        else if (A[m1] < B[m2]) {
            if ((d1-s1+1)%2 == 0) { //元素个数为偶数
                //因为偶数序列的中位数取的是中间两个数的较小者，所以这里舍弃较小的中位数，保留较大的中位数
                s1 = m1+1;  //中位数较小的序列，舍弃该中位数及前面的元素
                d2 = m2;    //中位数较大的序列，保留该中位数，舍弃其后面的元素
            } else {    //元素个数为奇数
                s1 = m1;    //中位数较小的序列，保留该中位数，舍弃其前面的元素
                d2 = m2;    //中位数较大的序列，保留该中位数，舍弃其后面的元素
            }
        } else {
            if ((d1-s1+1)%2 == 0) { //元素个数为偶数
                s2 = m2+1;
                d1 = m1;
            } else {    //元素个数为奇数
                s1 = m1;
                d2 = m2;
            }
        }
    }
    //最后两个序列各剩下一个元素，取较小的那个
    return A[s1]<B[s2] ? A[s1] : B[s2];
}
int FindMedian(int A[], int B[], int n) {
    int k=0, k1=0, k2=0;    //分别表示归并下标、A下标、B下标
    int mid = n;    //两个等长序列的中位数的位序
    while (k < mid-1) {     //归并下标到达中位数时跳出循环；这里的mid是位序而不是下标所以要减一
        if (A[k1] < B[k2]) {
            k1++;
        } else {
            k2++;
        }
        k++;
    }
    //归并下标到达中位数时，两个序列的下个元素较小的那个即是中位数
    return A[k1]<B[k2] ? A[k1] : B[k2];
}
int FindMedianDemo() {
    //int n = 5;
    //int A[] = {1,2,3,100,200};
    //int B[] = {2,6,8,10,20};
    int n = 3;
    int A[] = {1,11,111};
    int B[] = {2,22,222};
    printf("初始化：\n"); PrintArray(A, n); PrintArray(B, n);
    printf("中位数（归并）：%d\n", FindMedian(A, B, n));
    printf("中位数（最佳）：%d\n", FindMedian_optimal(A, B, n));
    return 0;
}

/*
顺序表题目九：
    已知一个整数序列A=(a0,a1,...,an-1)，其中0<=ai<n(0<=i<n)。若存在ap1=ap2=...=apm=x，且m>n/2(0<=pk<n, 1<=k<=m)，则称x为A的主元素。
    例如A=(0,5,5,3,5,7,5,5)，则5是主元素；又如A=(0,5,5,3,5,1,5,7)，则A中没有主元素。
    假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素。若存在，输出主元素，否则输出-1。要求：
    1. 给出算法的基本设计思想。
    2. 根据设计思想，采用C、C++或Java语言描述算法，关键之处给出注释。
    3. 说明你所设计算法的时间复杂度和空间复杂度。

答：最优算法：遍历数组，找出唯一可能为主元素的数，然后遍历第二次，确认该数是否主元素；具体步骤如下：
        1. 设变量tmp保存可能为主元素的数，设变量count进行计数；第一次遍历数组，将遇到的第一个数保存到tmp，count记为1；
            往下若遇到相同的数则count加1，不相同则count减1；
            若count减为了0，则将下一个数赋值给tmp，count记为1；
            如此循环，直到遍历完成；
        2. 第二次遍历数组，统计tmp所存元素的数量，若数量大于n/2，则为主元素，否则该数组没有主元素。
        该算法的时间复杂度是O(n)，空间复杂度是O(1)
    次优算法：构建一个大小为n的数组B，以下标表示序列A中的元素，以内容表示该元素的数量，遍历一遍A即可得到每个元素的数量，再遍历一遍B找出最大值即可；
        注：该算法是经典的以空间换时间的次优方案，需要题中序列的元素全部>=0且<n
        时间复杂度O(n)，空间复杂度O(n)
*/
int FindMedian_optimal(int A[], int n) {
    int tmp = A[0];
    int count = 1;
    int i;
    for (i=1; i<n; i++) {
        if (A[i] == tmp)
            count++;
        else
            if (count > 0)
                count--;
            else {
                tmp = A[i];
                count = 1;
            }
    }
    count = 0;
    for (i=0; i<n; i++)
        if (A[i] == tmp)
            count++;
    if (count > n/2)
        return tmp;
    else
        return -1;
}
int FindMainElem_suboptimal(int A[], int n) {
    int B[n], i;
    memset(B, 0, sizeof(int)*n);    //确保 0~n-1 每个数的初始计数都是0
    for (i=0; i<n; i++)
        B[A[i]]++;
    int elem = 0;   //B中最大值对应的下标，也就是A的元素
    int count = B[0];   //elem对应的计数
    for (i=1; i<n; i++)
        //打擂算法找出最大值
        if (B[i] > count) {
            count = B[i];
            elem = i;
        }
    if (count > n/2)
        return elem;
    else
        return -1;
}

int FindMainElemDemo() {
    int A[] = {0,1,3,3,3,6,7};
    int n = 7;
    //printf("%d\n", FindMainElem_optimal(A, n));
    printf("%d\n", FindMainElem_suboptimal(A, n));
    return 0;
}

/*
顺序表题目十：
    给定一个含n(n>=1)个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。
    例如{-5,3,2,3}中未出现的最小正整数是1，{1,2,3}中未出现的最小正整数是4。要求：
    1. 给出算法的基本设计思想。
    2. 根据设计思想，采用C、C++或Java语言描述算法，关键之处给出注释。
    3. 说明你所设计算法的时间复杂度和空间复杂度。

答：假设题中数组为A；新建一个长度为n的整数数组B，全部初始化为0；
    遍历一遍数组A，将每个元素的值减一作为B的下标赋值对应的元素值为1；
    之后再遍历数组B，找出第一个值为0的元素所对应的下标i，则i+1即为数组A中未出现的最小正整数。
    时间复杂度O(n)，空间复杂度O(n)
*/
int FindMissMin(int A[], int n) {
    int B[n], i;
    memset(B, 0, sizeof(int)*n);
    for (i=0; i<n; i++)
        if (A[i]>0 && A[i]<=n)  //小于0和大于n的舍弃不管
            B[A[i]-1] = 1;
    //未出现的最小正整数只可能是：[1~n+1]
    for (i=0; i<n; i++)
        if (B[i] == 0)
            break;
    return i+1;
}
int FindMissMinDemo() {
    //int A[] = {-5,3,2,3};
    //int n = 4;
    int A[] = {1,2,3};
    int n = 3;
    printf("%d\n", FindMissMin(A, n));
    return 0;
}

/*
顺序表题目十一：
    定义三元组(a,b,c)（a、b、c均为整数）的距离D=|a-b|+|b-c|+|c-a|。给定3个非空整数集合S1、S2和S3，按升序分别存储在3个数组中。
    请设计一个尽可能高效的算法，计算并输出所有可能的三元组(a,b,c)（a∈S1、b∈S2，c∈S3）中的最小距离。
    例如S1={-1,0,9}，S2={-25,-10,10,11}，S3={2,9,17,30,41}，则最小距离为2，相应的三元组为(9,10,9)。要求：
    1. 给出算法的基本设计思想。
    2. 根据设计思想，采用C、C++或Java语言描述算法，关键之处给出注释。
    3. 说明你所设计算法的时间复杂度和空间复杂度。

答：假设a≤b≤c，则距离 D = |c-a| * 2，可知最小距离只跟3个数中的最大和最小值有关；
    当固定住c而增大a时，可以减少这个最小距离，直到a∈[b,c]时则不再减少，等到a>c时则开始增加；
    所以思路就是不停增加最小值直到它不再是最小值，到其中一个数组遍历完成时循环结束；
    算法设计思路：
        使用D_min记录已处理的三元组的最小距离，初值给一个足够大的整数；
        三个集合分别存储在数组A、B、C，下标分别为i、j、k，循环从下标0开始直到其中一个数组遍历完成，循环内的逻辑是：
            计算(A[i],B[j],C[k])的距离D，若D<D_min，则D_min=D；将A[i],B[j],C[k]的最小值的下标+1
        循环结束，则输出结果D_min
    时间复杂度O(n)，空间复杂度O(1)
*/
//获取绝对值
int absValue(int n) {
    if (n < 0)
        return -n;
    return n;
}
//判断a是否3个数中的最小值
bool isMin(int a, int b, int c) {
    if (a<=b && a<=c)
        return true;
    return false;
}
int findMinTrip(int A[], int n1, int B[], int n2, int C[], int n3) {
    int i=0, j=0, k=0, D_min=INT_MAX, D;
    while (i<n1 && j<n2 && k<n3 && D_min>0) {   //疑问：D_min>0有必要吗？D_min应该不可能<0
        D = absValue(A[i]-B[j]) + absValue(B[j]-C[k]) + absValue(C[k]-A[i]);
        if (D < D_min)
            D_min = D;
        if (isMin(A[i], B[j], C[k]))
            i++;
        else if (isMin(B[j], A[i], C[k]))
            j++;
        else
            k++;
    }
    int a, b, c;
    if (i >= n1) {
        a = A[i-1];
        b = B[j];
        c = C[k];
    } else if(j >= n2) {
        a = A[i];
        b = B[j-1];
        c = C[k];
    } else if(k >= n3) {
        a = A[i];
        b = B[j];
        c = C[k-1];
    }
    printf("最小距离是：%d，对应三元组是：(%d, %d, %d)\n", D_min, a, b, c);
    return D_min;
}
int findMinTripDemo() {
    int A[] = {-1,0,9};
    int B[] = {-25,-10,10,11};
    int C[] = {2,9,17,30,41};
    int n1=3, n2=4, n3=5;
    findMinTrip(A, n1, B, n2, C, n3);
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
    //ret = MergeSqListDemo();
    //ret = SwapListDemo();
    //ret = ReverseArrayDemo();
    //ret = FindMedianDemo();
    //ret = FindMainElemDemo();
    //ret = FindMissMinDemo();
    ret = findMinTripDemo();
    return ret;
}