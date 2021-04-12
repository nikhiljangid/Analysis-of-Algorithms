#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

int i,j,k,a,b,u,v,n,ne=1;
int min;
int mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
int kruskalMST();

int main()
{

	std::cout<<"Implementation of Kruskal's algorithm"<<std::endl;
	std::cout<<"\nEnter the no. of vertices: ";
	std::cin>>n;
	kruskalMST();
	
	return 0;
}
int kruskalMST(){
	std::cout<<std::endl<<"Enter the cost adjacency matrix:"<<std::endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			std::cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	std::cout<<std::endl<<"The edges of Minimum Cost Spanning Tree are"<<std::endl<<std::endl;
	while(ne < n)
	{
		
		for(i=1,min=INT_MAX; i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			std::cout<<ne++<<" edge ( "<<a<<", "<<b<<" ) = "<<min<<std::endl;
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=INT_MAX;
	}
	std::cout<<std::endl<<"Minimum cost = "<<mincost<<std::endl;
	getch();
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
