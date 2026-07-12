//顺序栈
#include<iostream>
#include<cstdlib>
#define MAXSIZE 1000
using namespace std;
typedef struct Node{
    int *base;
    int *top;
    int len;
}node;

void init(node &a){
    a.base = (int *)malloc(sizeof(int)*MAXSIZE);
    if(!a.base)
        exit(0);
    a.top = a.base;
    a.len = MAXSIZE;
}

void push(node &a,int n){
    if(a.top - a.base >= a.len){
        a.base = (int *)realloc(a.base,(a.len + 10)*sizeof(int));
        if(!a.base)
            exit(0);
        a.top = a.base + a.len;
        a.len += 10;
    }
    *++a.top = n;
}

void pop(node &a){
    if(a.top == a.base)
        exit(0);
    --a.top;
}

void show(node &a){
    node q;
    q = a;
    while(q.top != q.base){
        cout << *(q.top)-- << " ";   // 修复1: 补上英文分号
    }
    cout << endl;
}

void clearlis(node &a){
    a.top = a.base;
}

void deslis(node &a){
    free(a.base);
    // 修复2: 删除 free(a.top) —— a.top 指向 a.base 内部，不能单独free
    a.base = a.top = NULL;
}

// 链栈
// 修复3: struct tag 从 "node" 改为 "linked_node"，避免与顺序栈的 node 冲突
typedef struct linked_node{
    int n;
    struct linked_node *next;
}lis;

typedef struct{
    lis *top;
    int len;
}link;

void init(link *a){
    a->top = NULL;
}

void push(link *a,int n){
    lis *p;
    p = (lis *)malloc(sizeof(linked_node));  // sizeof(linked_node) 明确表示链栈节点
    if(!p)
        exit(0);
    p->n = n;
    p->next = a->top;
    a->top = p;
}

void pop(link *a){
    lis *temp;
    if(a->top == NULL)
        exit(0);
    temp = a->top;
    cout << temp->n;
    a->top = temp->next;
    cout << endl;
    free(temp);
}

void show(link *a){
    lis *t;
    t = a->top;
    while(t!=NULL){
        cout << t->n << " ";
        t = t->next;
    }
    cout << endl;
}

// 链队列
// 修复4: struct tag 改为 "qnode"，所有重名类型全部换掉
// qnode = 队列节点  qptr = 队列节点指针  linkqueue = 链队列
typedef struct qnode{
    int n;
    struct qnode *next;
}qnode, *qptr;

typedef struct{
    qptr fron, rear;
}linkqueue;

void init(linkqueue &a){
    a.fron = a.rear = (qptr)malloc(sizeof(qnode));
    if(!a.fron)
        exit(0);
    a.fron->next = NULL;
}

void push(linkqueue &a,int n){
    qptr p;
    p = (qptr)malloc(sizeof(qnode));
    if(!p)
        exit(0);
    p->n = n;
    p->next = NULL;
    a.rear->next = p;
    a.rear = p;
}

void pop(linkqueue &a){
    int k;
    qptr p;
    if(a.fron == a.rear)
        exit(0);
    p = a.fron->next;
    k = p->n;
    cout << "出队元素为" << k << endl;
    a.fron->next = p->next;
    if(a.rear == p)
        a.fron = a.rear;
    free(p);
}

void show(linkqueue &a){
    linkqueue p;
    p = a;
    p.fron = p.fron->next;           // 跳过头结点
    while(p.fron != NULL){
        cout << p.fron->n << " ";     // 修复5: 打印 n（数据），而非 next（指针）
        p.fron = p.fron->next;
    }
    cout << endl;
}

