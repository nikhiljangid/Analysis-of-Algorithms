#include<iostream>
#include<conio.h>
#include<limits.h>
using namespace std;

int main()
{
	int i, j,cost[5][5], s, n, te=1, u, v, min, mincost, visited[5]={0}, flag=1;
	cout<<"Enter the number of vertices : ";
	cin>>n;
	cout<<"Enter the cost adjency matrix : \n";
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=INT_MAX;
		}
	}
	cout<<endl;
	while(flag!=0){
		cout<<"Enter the source vertex from 1 to "<<n<<" : ";
		cin>>s;
	
		if(s<1||s>n)
		{
			cout<<"Source vertex exceeds the range"<<endl;
		}
		else
			flag=0;
	}
	cout<<endl;
	visited[s]=1;
	while(te<n)
	{       min=INT_MAX;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(cost[i][j]<min)
				{
					if(visited[i]!=0)
					{
						min=cost[i][j];
						u=i;
						v=j;
					}
					
				}
			}
		}
		if(visited[u]==0||visited[v]==0)
		{
			cout<<te++<<" edge ("<<u<<"--"<<v<<") : "<<min<<endl;
			visited[v]=1;
			mincost += min;
		}
		cost[u][v]=cost[v][u]=INT_MAX;
	}
	cout<<endl<<"Minimum Cost = "<<mincost;
	getch();
	
	return 0;
}
