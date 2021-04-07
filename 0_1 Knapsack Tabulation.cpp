#include<stdio.h>
int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
int knapSack(int W, int wt[], int val[], int n){
	int i, w;
	int V[n+1][W+1];
	
	for(i=0; i<=n; i++){
		for(w=0; w<=W; w++){
			if(i==0 || w==0)
				V[i][w]=0;
			else if(wt[i-1]<=w)
				V[i][w]=max(val[i-1]+V[i-1][w-wt[i-1]], V[i-1][w]);
			else
				V[i][w]=V[i-1][w];
		}
	}
}
int main(){
	int val[]={20,25,40};
	int wt[]={25,20,30};
	int W=50;
	int n=sizeof(val)/sizeof(val[0]);
	printf("Solution : %d", knapSack(W, wt, val, n));
	return 0;
}
