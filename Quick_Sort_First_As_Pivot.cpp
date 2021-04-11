// Program to implement Quick Sort first element as pivot
#include<iostream>
using namespace std;

void swap(int *a, int *b) 
{ 
    int t= *a; 
    *a = *b; 
    *b = t; 
} 

int Partition (int arr[], int p, int r) 
{ 
    int pivot = arr[p];
    int i=p;
  
    for (int j=p+1; j<=r; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i], &arr[p]); 
    return (i); 
} 

void QuickSort(int arr[], int p, int r) 
{ 
    if (p<r) 
    { 
        int q=Partition(arr, p, r); 
        QuickSort(arr,p,q-1); 
        QuickSort(arr,q+1,r); 
    } 
} 

int main() 
{ 
    int arr[100];
    int n;
    cout<<"Enter size of the list : ";
    cin>>n;
    cout<<"Enter the elements in the list \n";
    
    for(int c=0; c<n; c++){
    	cin>>arr[c];
	}
	
	QuickSort(arr,0,n-1);
	
	printf("Sorted Array : ");
	
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
} 
