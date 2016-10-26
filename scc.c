#include<stdio.h>
#include<stdlib.h>
int n,m;
int visited[100001],arr[100001];
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
void dvis(struct node* head[],int z)
{	struct node* t=head[z];
	//time++;
	//head->d=time;
	visited[z]=1;
	//printf("%d ",z);
	while(t!=NULL)
	{	if(visited[t->x]==0)
			dvis(head,t->x);
		t=t->next;	
	}
	//visited[z]=2;
	//time++;
	//arr[d]=time;
	//d++;
	stack[++top]=z;
}
void dvis1(struct node* tail[],int z)
{	struct node* t=tail[z];
	visited[z]=1;
	printf("%d ",z);
	while(t!=NULL)
	{	if(visited[t->x]==0)
			dvis1(tail,t->x);
		t=t->next;	
	}
}
void dfs(struct node* head[])
{	//struct node* t;
	int k=1,v=1;
	while(k!=n+1)
	{	visited[k]=0;k++;}
	//visited[v]=1;
	//printf("*");
	//dvis(head,1);
	for(k=1;k<=n;k++)
	{	//printf("*");
		//printf("%d\n",visited[i]);
		if(visited[k]==0)
		{	dvis(head,k);
		}
	}
}
void dfs1(struct node* tail[])
{	int k=1;
	while(k!=n+1)
	{	visited[k]=0;k++;}
	while(top!=0)
	{	int v=stack[top];
		pop();
		if(visited[v]==0)
		{	dvis1(tail,v);printf("\n");
		}
	}
}
void transpose(struct node* head[],struct node* tail[])
{	int i;
	//struct node* tail[n];
	for(i=1;i<=n;i++)
	{	struct node* t=head[i];
		while(t!=NULL)
		{	(tail[t->x])=insert((tail[t->x]),i);
			t=t->next;
		}
	}	
}
int main()
{	int t,i;
	scanf("%d",&t);
	while(t--)
	{	int a,b;
		//c=0;
		scanf("%d %d",&n,&m);
		//printf("%d\n",n);
		struct node* head[n];
		struct node* tail[n];
		for(i=1;i<=n;i++)
		{	head[i]=NULL;tail[i]=NULL;}
		for(i=0;i<m;i++)
		{	//int a,b;
			scanf("%d %d",&a,&b);
			//head[a]=NULL;
			head[a]=insert(head[a],b);
			//head[b]=insert(head[b],a);
			//printf("%d",head[a]->x);
		}
		dfs(head);
		transpose(head,tail);
		dfs1(tail);
	}
}
