链表线性表
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
	int n;
	struct node *next;
}node,*lis; 
void init(lis &a){
	a = (lis)malloc(sizeof(node));//new node;
	if(!a)
		exit (0);
	a->next = NULL;
}
void creat(lis &a,int n){
	//a->next = NULL;
	lis p;
	int i;
	for(i = 0;i < n;i++){
		p = (lis)malloc(sizeof(node));//new node;
		//cin >> p->n;
		p->n = i;
		p->next = a->next;
		a->next = p;
	}
}
void del(lis &a,int n){
	lis p,q;
	p = a;
	int i = 0;
	while(p != NULL && i < n-1){
		p = p->next;++i;
	}
	if(i > n-1 || !p->next){
		exit(0);
	}
	q = p->next;
	p->next = q->next;
	free(q);
}
void inset(lis &a,int n){
	int m;
	cout<<"请输入要插入的数据"<<endl;
	cin>>m;
	lis p,q;
	p = a;
	int i = 0;
	while(p != NULL && i < n -1){
		p = p->next;++i;
	}
	if(i > n -1 || !p->next){
		exit(0);
	} 
	q = new node;
	q->n = m;
	q->next = p->next;
	p->next = q;
}
void show(lis &a){
	lis p;
	p = a->next;
	while(p){
		cout<<p->n<<"";
		p = p->next;
	}
	cout<<endl;
}

