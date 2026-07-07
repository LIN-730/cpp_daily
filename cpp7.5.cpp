#include<iostream> 
#include<stdlib.h>
using namespace std;
#define nn 1000
#define mm 10
typedef struct //线性表表示
{
	int *elem;
	int len;
	int num;
} node;
 node a,b,cc;
void init(node &s) //建立空线性表
{
	s.elem = (int *)malloc(sizeof(int)*nn); //分配储存空间
	if(!s.elem)
		exit(0);
	s.len = 0;
	s.num = nn;
} 
void push(node &s,int n) //向顺序表中存入数据
{
	int *newa;
	if(s.len >= s.num)
	{
		newa = (int *)realloc(s.elem,sizeof(int)*(s.num + mm));
		if(!newa)
			exit(0);
		s.elem = newa;
		s.num += mm;
	}
	s.elem[s.len ++] = n;
} 
void intset(node& s,int n,int m) //在第n个位置插入元素m 
{
	int *newa;
	if(n < 1 || n > s.len)
		exit(0);
	if(s.len >= s.num)
	{
		newa = (int *)realloc(s.elem,sizeof(int)*(s.num + mm));
		if(!newa)
			exit(0);
		s.elem = newa;
		s.num += mm;
	}
	int *q,*p;
	q = &(s.elem[n -1]);
	p = &(s.elem[s.len - 1]);
	for(;q <= p;--p)
	{
		*(p + 1) = *p;
	}
	*q = m;
	s.len++;
}
void del(node &s,int n)
{
	int *newa;
	if(n < 1 || n > s.num)
		exit(0);
	if(s.len >= s.num)
	{
		newa = (int *)realloc(s.elem,sizeof(int)*(s.num + mm));
		if(!newa)
			exit(0);
		s.elem = newa;
		s.num += mm;
	}
	int *q,*p;
	q = &(s.elem[n-1]);
	p = s.elem + s.len - 1;
	for(;q <= p;q++)
	{
		*q = *(q + 1);
	}
	--s.len;
}
void me(node aa,node bb,node &c)
{
	int *pa,*pb,*pc,pa_last,*pb_last;
	pa = aa.elem;pb = bb.elem; //把a、b线性表首地址赋给pa、pb
	c.len = aa.len + bb.len;
	 
}
 
