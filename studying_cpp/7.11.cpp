#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node{
	int n;
	struct node *prior,*next;
}node,*lis;
void init(lis &a){
	a->prior = NULL;
	a->next = NULL; 
} 
void creat(lis &a,int num){
	lis temp,q;
	temp = a;
	int i;
	for(i = 0;i < num;i++){
		q = new node;
		cin>>q->n;
		q->next = NULL;
		q->next = temp->next;
		q->prior = temp;
		temp->next = q;
		temp = q; 
	}
}
void inlist(lis &a,int n){
	lis q,p;
	int m,i;
	q = a;
	cout << "请输入要插入的元素" << endl;
	cin >> m;
	for(i = 0;i < n;i++)
		q = q->next;
	if(!(p = new node))
		exit(0);
	p->n = m;
	p->fron = q->fron;
	q->fron->next = p;
	p->next = q;q->fron = p;
}

