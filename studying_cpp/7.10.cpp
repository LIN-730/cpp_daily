void hebing(lis &a,lis &b,lis &c){
	lis p,q,r;
	p = a->next;q = b->next;
	c = r = a;
	while(p && q){
		if(p->n <= q->n){
			r->next = p;
			r = p;p = p->next;
		}
		else{
			r->next = q;r = q;q = q->next;
		}
	}
	while(p){
		r->next = p;
		r = p;p = p->next;
	}
	while(q){
		r->next = q;r = q;q = q->next;
	}
	free(b);
} 
Ë«ÏòÁ´±í
#include<iostream>
#include(cstdlib)
using namespace std;
typedef struct node{
	int n;
	struct node *fron,*next;
}node,*lis;
void init(lis &a){
	a->fron = NULL;
	a->next = NULL;
}
void creat(lis &a,int n){
	lis temp,q;
	temp = a;
	int i;
	for(i = 0;i <n;i++){
		q = new node;
		cin>>q->n;
		q->next = NULL;
		q->next = temp->next;
		q->fron = temp;
		temp->next = q;
		temp = q;
	}
}
