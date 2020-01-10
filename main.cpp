#include <iostream>

using namespace std;

struct MemoryAddressFromSearch{
    long int Address;
    struct MemoryAddressFromSearch *next;
};

typedef struct MemoryAddressFromSearch *MAFS;
#define MemoryAddressFromSearch_Size sizeof(struct MemoryAddressFromSearch)

MAFS add(MAFS heada,MAFS p0);

//链表合并:合并la、lb到lc
void MergeLinkList_LL(MAFS &LA, MAFS &LB, MAFS &LC) {
    MAFS pa, pb, pc;		// 定义三个链表
    pa = LA->next;				// pa指向LA指针
    pb = LB->next;				// pb指向LB指针
    LC = LA;					// 用La的头结点作为LC头结点
    pc = LC;					// pc的初值指向LC的头结点

    while (pa && pb) {			//链表不为空
        if (pa->Address <= pb->Address)	//先放小的数据
        {
            pc->next = pa;		//pc的next指向pa
            pc = pa;			//pc指向pa
            pa = pa->next;		//pa指向pa的next
        }
        else
        {
            pc->next = pb;		//pc的next指向pb
            pc = pb;			//pc指向pb
            pb = pb->next;		//pa指向pb的next
        }
    }
    pc->next = pa ? pa : pb;	// 插入非空表的剩余段
    delete LB;
}

MAFS mergeTwoLists(MAFS l1, MAFS l2)
{
    // l1、l2至少一个为空
    if(!l1 || !l2)
    {
        // (l1 && !l2)为true表示l2为空，则返回l1，否则返回l2
        // 返回l2的情况：（1）l1为空，l2不空；（2）l1、l2都为空。
        return l1 && !l2 ? l1 : l2;
    }

    MAFS result = new MemoryAddressFromSearch;
    MAFS head = result;
    while(l1 && l2)
    {
        if(l1->Address <= l2->Address)
        {
            head = head->next = l1;
            l1 = l1->next;
        }
        else
        {
            head = head->next = l2;
            l2 = l2->next;
        }
    }

    // l1或者l2不为空
    if(l1 || l2)
    {
        l1 ? (head->next=l1) : (head->next=l2);
    }
    return result;
}
MAFS mergeTwoListsV2(MAFS TEST1, MAFS TEST2)
{
    MAFS p0,p;
    do {
        p0 = (MAFS)malloc(sizeof(MemoryAddressFromSearch_Size));
        p0->Address = TEST2->Address;
        p = add(TEST1, p0);
        TEST2 = TEST2->next;
    } while(TEST2);
    return p;
}

MAFS test(){
    //创建链表
    MAFS HEAD = nullptr;
    MAFS Begin = nullptr;
    MAFS End = nullptr;
    HEAD = Begin = End = (MAFS)malloc(MemoryAddressFromSearch_Size);


    for (int i = 0; i < 3; ++i) {
        if (i == 2){
            End->Address = 3333333;
        } else{
            End->Address = 1232133;
        }

        //开始
        cout << i << endl;
        if (i == 0){
            End->next=nullptr;
            Begin = End;
            HEAD = Begin;
        } else{
            End->next = nullptr;
            Begin->next = End;
            Begin = End;
        }
        End = (MAFS)malloc(MemoryAddressFromSearch_Size);
    }
    free(End);
    return HEAD;
}

MAFS add(MAFS heada,MAFS p0)
{
    MAFS p1,p2;
    p1 = heada;
    while(/*p1->next!=NULL*/p1!=NULL && p1->Address<p0->Address) {
        p2 = p1;
        p1 = p1->next;
    }
    if(p1 == heada) {
        heada = p0;
        p0->next = p1;
    }else {
        if(p2->next != NULL) {
//            p2->next = p0;
//            p0->next = p1;    /*顺序不要搞错*/
            p0->next = p1;
            p2->next = p0;
        }else {
            p2->next = p0;
            p0->next = NULL;
        }
    }
    return heada;
}

//打印链表--会自动清除链表
void Print_Linked_list(MAFS HEAD){
    MAFS pointer = HEAD;
    while(pointer){
        cout << (*pointer).Address << endl;
        pointer = (*pointer).next;
    }

}

int GetListNodeLen(MAFS m_pHead)
{
    if (m_pHead == NULL)
    {
        return 0;
    }

    MAFS pTemp = m_pHead;
    int aListLen = 0;
    while(pTemp != NULL)    //判断当前节点指针是否为空
    {
        aListLen ++;
        pTemp = pTemp->next;
    }
    return aListLen;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
//
    MAFS TEST1 = test();
    int num = GetListNodeLen(TEST1);
    cout << num << endl;

    MAFS TEST22 = nullptr;
    int num2 = GetListNodeLen(TEST22);
    cout << "当前的：" << num2 << endl;


    cout << TEST1->Address << endl;
    cout << TEST1->next->Address << endl;


    MAFS T = TEST1;
    for (int i = 0; i < num; ++i) {


        if (i == num -1){
            cout << T->Address << endl;
        }
        T = (*T).next;
    }



    int a = 0x15;
    cout << a << endl;
//    MAFS TEST2 = test();
//
//    MAFS TEST3;
//    MAFS TEST4;
//
//    MAFS p0;
//    MAFS p;
//
//    Print_Linked_list(TEST1);
//    Print_Linked_list(TEST2);
//
//    cout << "..." << endl;
//
//    MergeLinkList_LL(TEST1,TEST2,TEST3);
//    Print_Linked_list(TEST3);
//
//    cout << "..." << endl;
//
//
////    printf("合并链表：\n");
////    do {
////        p0 = (MAFS)malloc(sizeof(MemoryAddressFromSearch_Size));
////        p0->Address = TEST2->Address;
////        p = add(TEST1, p0);
////        TEST2 = TEST2->next;
////    } while(TEST2);
//
//
//
//    TEST4 = mergeTwoListsV2(TEST1,TEST2);
//    Print_Linked_list(TEST4);

    int c = 0x21000 / 4096;
    cout << c;



    return 0;
}
