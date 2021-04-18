#include<iostream>
using namespace std;

void optimalMerge(int arr[],int c[],int n)
{
	int i=0, k=0;
	c[k] = arr[i]+arr[i+1];
	i += 2;
	while(i<n)
	{
		k++;
		if(c[k-1]+arr[i]<=arr[i]+arr[i+1])
		c[k] = c[k-1]+arr[i];
		else
		{
			c[k] = arr[i]+arr[i+1];
			i += 2;
			while(i<n)
			{
				k++;
				if(c[k-1]+arr[i]<=c[k-2]+arr[i])
				c[k] = c[k-1]+arr[i];
				else
				c[k] = c[k-2]+arr[i];
				i++;
			}
		}
		i++;
	}
	k++;
	c[k] = c[k-1]+c[k-2];
	int sum=0;
	cout<<"Optimal Merge:\n";
	for(k=0;k<n-1;k++)
	{
		sum += c[k];
		cout<<c[k]<<" ";
	}
	cout<<"\nMinimum Computation: "<<sum;
}

int main()
{
	int size;
	cout<<"Enter the size of array: ";
	cin>>size;
	int arr[size],c[size-1];
	cout<<"Enter "<<size<<" elements in array:"<<endl;
	int i;
	for(i=0;i<size;i++)
		cin>>arr[i];
	
	optimalMerge(arr,c,size);
}
