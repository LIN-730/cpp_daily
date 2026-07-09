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
	q = &(s.elem[n - 1]);
	p = s.elem + s.len - 1;
	for(;q <= p;q++)
	{
		*(q) = *(q + 1);
	}
	--s.len;
}
void me(node aa,node bb,node &c)
{
	int *pa,*pb,*pc,*pa_last,*pb_last;
	pa = aa.elem;
	pb = bb.elem;
	c.len = aa.len + bb.len;
	pc = c.elem = (int *)malloc(sizeof(int)*c.len);
	if(!c.elem)
		exit(0);
	pa_last = aa.elem + aa.len;
	pb_last = bb.elem + bb.len;
	while(pa < pa_last && pb < pb_last)
	{
		if(*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else *pc++ = *pb++;
	}
	while(pa < pa_last)*pc++ = *pa++;
	while(pb < pb_last)*pc++ = *pb++;
}
void print(node &s)
{
	int i;
	int *p;
	p = &(s.elem[0]);
	for(i = 0;i < s.len;i++)
		cout << *p++ << "";
	cout << endl;
}
int main()
{
	init(a);
	init(b);
	int n,m,k,y;
	while(1)
	{
		cin >> y;
		if(y == 1)
		{
			cout << "请输入要插入的数字" << endl;
			cin >> n;
			push(a,n); 
		}
		if(y == 2)
		{
			cout << "请输入要插入的位置" << endl;
			cin >> m;
			cout << "请输入要插入的元素" << endl;
			cin >> k;
			intset(a,m,k); 
		}
		if(y == 3)
		{
			cout << "请输入要删除的位置" << endl;
			cin >> m;
			del(a,m);
		}
		if(y == 4)
		{
			print(a);
		}
		if(y == 5)
		{
			int j;
			for(j = 3;j <= 20;j += 3)
			{
				push(b,j);
			}
			print(b);
		}
		if(y == 6)
		{
			me(a,b,cc);
			print(cc);
		}
		if(y == 0)
		{
			break;
		}
		return 0;
	}
}
//链表线性表
#include<iostream>
#include<srdlib.h>
using namespace std;
typedef struct node
{
	int n;
	struct node *next;
}node,*lis;
void init(lis &a) //建立空链顺序表
{
	a = (lis)malloc(sizeof(node));
	if(!a)
		exit(0);
	a->next = NULL;
}
void creat(lis &a,int n)
{
	lis p;
	int i;
	for(i = 0;i < n;i++)
	{
		p = (lis)malloc(sizeof(node));
		
	}
}
