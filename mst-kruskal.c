#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{ int a,b,weight; }edge;

void mrg(edge arr[],int l,int m,int r)
{	
	int i,j,k,n1=m-l+1,n2=r-m;
	edge a[n1],b[n2];
	
	for(i=0;i<n1;i++) a[i]=arr[l+i];
	for(j=0;j<n2;j++) b[j]=arr[m+1+j];
	
	i=0;j=0;k=l;
	
	while(i<n1 && j<n2)
	if(a[i].weight<=b[j].weight) arr[k++]=a[i++];
	else arr[k++]=b[j++];

	while(i<n1) arr[k++]=a[i++];
	while(j<n2) arr[k++]=b[j++];
}

void mrgsort(edge arr[],int l,int r)
{	
	if(l<r)
	{	
		int m=(r+l)/2;
		mrgsort(arr,l,m);
		mrgsort(arr,m+1,r);
		mrg(arr,l,m,r);
	}
}

void uni(int set[],int vertex,int a,int b)
{
	int i;
	for(i=0;i<vertex;i++)
		if(set[i]==b) 
			set[i]=a;
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int vertex,sum=0,edges,i=-1; scanf("%d %d",&vertex,&edges);
		int set[vertex]; edge graph[edges];
		
		for(i=0;i<vertex;i++)
			set[i]=i;
		for(i=0;i<edges;i++)
		{
			int a,b,weight;
			scanf("%d %d %d",&a,&b,&weight);
			graph[i].a=a-1;
			graph[i].b=b-1;
			graph[i].weight=weight;
		}
		mrgsort(graph,0,edges-1);
		for(i=0;i<edges;i++)
		{
			if(set[graph[i].a]!=set[graph[i].b])
			{
				sum=sum+graph[i].weight;//printf("%d %d ",graph[i].a,graph[i].b);
				uni(set,vertex,set[graph[i].a],set[graph[i].b]);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}	