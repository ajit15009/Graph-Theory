#include<stdio.h>
#include<stdlib.h>
int n,m;
int visited[100001];
int top=0;
int stack[100001];
void pop()
{	--top;
}
struct node
{	int x;
	struct node* next;};
struct node* get(int y)
{	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->x=y;
	return temp;
}
struct node* insert(struct node* head,int y)
{	struct node* t;
	t=head;	
	if(head==NULL)
	{	head=get(y);return head;}
	else
	{	struct node* temp;
		temp=get(y);
		while(head->next!=NULL)
			head=head->next;
		head->next=temp;
	}
	return t;
}
void dis(struct node* head[])
{	int i;//printf("*\n");
	for(i=1;i<=n;i++)
	{	struct node* t=head[i];
	while(t!=NULL)
	{	printf("%d ",t->x);
		t=t->next;
	}
	printf("\n");}
}
void topopo(struct node* head[],int z)
{	visited[z]=1;
	struct node* t=head[z];
	while(t!=NULL)
	{	if(visited[t->x]==0)
			topopo(head,t->x);
		t=t->next;
	}
	stack[++top]=z;
}
void topo(struct node* head[])
{	int i;
	for(i=1;i<=n;i++)
		visited[i]=0;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			topopo(head,i);
	}
	while(top!=0)
	{	printf("%d ",stack[top]);
		pop();	
	}	
}
int main()
{	int t;
	scanf("%d",&t);
	while(t--)
	{	scanf("%d %d",&n,&m);
		int i,a,b;
		struct node* head[n];
		for(i=1;i<=n;i++)
		{	head[i]=NULL;}
		for(i=0;i<m;i++)
		{	scanf("%d %d",&a,&b);
			head[a]=insert(head[a],b);
		}
		//dis(head);
		topo(head);	
	}	
}