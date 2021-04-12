#include<iostream>
using namespace std;

int max(int a, int b){
	int max=(a>b)?a:b;
	return max;
}

int k(int wt[], int val[], int n, int w){
	if(n==0||w==0)
		return 0;
	else if(wt[n-1]>w)
		return k(wt, val, n-1, w);
	else{
		return max(val[n-1]+k(wt,val,n-1,w-wt[n-1]), k(wt,val,n-1,w));
	}
}

int main(){
	int val[]={10,20,20,12,20};
	int wt[]={1,2,3,2,4};
	int w=4, n=sizeof(val)/sizeof(val[0]);
	int v[10][10];
	cout<<k(wt,val,n,w);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(wt[i]>=j){
				v[i][j]=v[i-1][j];
			}
			else if(wt[i]<=j){
				v[i][j]=val[i];
			}
		}
	}
}
