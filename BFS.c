#include<stdio.h>
#include<stdlib.h>
int n,m,ta=0,he=0;
int visited[100001],q[100001];
int top=0;
int dis[100001];
struct que
{	struct node* head;
	struct node* tail;
};
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
void enque(struct que (*q),int a)
{	
	struct node* te=(struct node*)malloc(sizeof(struct node));
	te->x=a; te->next=NULL;
	if((*q).tail==NULL)
	{	(*q).tail=(*q).head=te; }
	else
	{	
		(*q).tail->next=te;
		(*q).tail=te;
	}
}
int deque(struct que* q)
{	struct node* temp;
	temp=(*q).head;
	if((*q).head==(*q).tail)
		(*q).tail=NULL;
	((*q)).head=((*q)).head->next;
	return (temp->x);	
}
void en(int a)
{
	ta++;
	q[ta]=a;	
}

int de()
{
	he++;
	return(q[he]);
}
void BFS(struct node* head[])
{
 	int w,i,v=1;
 	struct node *p;
 	//struct que q;
 	//q.head=q.tail=NULL;
 	//struct que (*q);
 	//q->R=q->F=-1;              //initialise
 	for(i=1;i<=n;i++)
  		visited[i]=0;
 	en(v);
 	//printf("\nVisit\t%d",v);
	while(he!=ta)//while(q.head!=NULL)
	{
  		v=de();
  		//printf("%d\n",v);
  		//insert all unvisited,adjacent vertices of v into queue
  		for(p=head[v];p!=NULL;p=p->next)
  		{
   			w=p->x;
   			//dis[w]=v+1;
   			if(visited[w]==0)
   			{
    			en(w);
    			visited[w]=1;
    			dis[w]=dis[v]+1;
			//if(w!=n)
    				//c=c+1;
    			//printf("\nvisit\t%d",w)
   			}
   			else
   			{	if(dis[w]>dis[v]+1)
   					dis[w]=dis[v]+1;
   			}
  		}
  		visited[v]=1;
 	}
}
void display(struct node* head[])
{	int i;//printf("*\n");
	for(i=1;i<=n;i++)
	{	struct node* t=head[i];
	while(t!=NULL)
	{	printf("%d ",t->x);
		t=t->next;
	}
	printf("\n");}
}
int main()
{	int t,i;
	int a,b;
		//c=0;
	scanf("%d",&t);
	while(t--){
	scanf("%d %d",&n,&m);
		//printf("%d\n",n);
	struct node* head[n];
	for(i=1;i<=n;i++)
	{	head[i]=NULL;}

	for(i=0;i<m;i++)
	{	//int a,b;
		scanf("%d %d",&a,&b);
		//head[a]=NULL;
		head[a]=insert(head[a],b);
		head[b]=insert(head[b],a);
		//printf("%d",head[a]->x);
	}
		int j;
		BFS(head);
		int s=0;
		if(dis[n]!=0)
			printf("%d\n",dis[n]);
		else
			printf("-1\n");
		he=ta=0;
	}
}
