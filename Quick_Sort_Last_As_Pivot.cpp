#include<iostream>
using namespace std;

void swap(int* a, int* b) 
{ 
    int t= *a; 
    *a = *b; 
    *b = t; 
} 

int Partition (int arr[], int p, int r) 
{ 
    int pivot = arr[r];
    int i=p-1;
  
    for (int j=p; j<r; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i+1], &arr[r]); 
    return (i+1); 
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
    int size;
    cout<<"Enter size of the list : "; 
    cin>>size;
    cout<<"Enter the elements in the list \n";
    for(int c=0; c<size; c++){
    	cin>>arr[c];
	}
	
	QuickSort(arr,0,size-1);
	
	for(int c=0; c<size; c++){
    	cout<<arr[c]<<" ";
	}
	
} 
