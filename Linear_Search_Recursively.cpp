//Program to implement linear search

#include<iostream>
using namespace std;

int LinearSearch(int arr[], int search, int index, int n)
{
    int pos = 0;
 
    if(index >= n)
    {
        return 0;
    }
 
    else if (arr[index] == search)
    {
        pos = index + 1;
        return pos;
    }
 
    else
    {
        return LinearSearch(arr, search, index+1, n);
    }
    return pos;
}
 
int main()
{
    int n, search, pos, m = 0, arr[100];
    cout<<"Enter the total number of elements in the array : ";
    cin>>n;
 
    cout<<"Enter the elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
 
    printf("Enter the element to search  ");
    cin>>search;
 
    pos =  LinearSearch(arr, search, 0, n);
    if (pos != 0)
    {
        cout<<"Element found at position "<<pos;
    }
    else
    {
        cout<<"Element not found";
    }
    return 0;
}
