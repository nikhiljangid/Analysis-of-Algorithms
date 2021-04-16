#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

int Print_LCS(char b[10][10], char X[], int i, int j){
	if(i==0||j==0)
		return 0;
	
	else if(b[i][j]=='d'){
		Print_LCS(b,X,i-1,j-1);
		cout<<X[i-1];
	}

	else if(b[i][j]=='|')
		Print_LCS(b,X,i-1,j);
		
	else
		Print_LCS(b,X,i,j-1);	
}
void LCS_Length(char X[], char Y[]){
	int m=strlen(X); //X.length
	int n=strlen(Y); //Y.length     
	int c[10][10], i, j;
	char b[10][10];
	
	for(i=1; i<=m; i++)
		c[i][0]=0;
	
	for(j=0; j<=n; j++)
		c[0][j]=0;
		
	for(i=1; i<=m; i++){
		for(j=1; j<=n; j++){
			if(X[i-1]==Y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 'd';
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] ='|';
			}
			else{
				c[i][j] = c[i][j-1];
				b[i][j] = '-';
			}
		}
	}
	
	/*for(int c=1; c<=m; c++){
		for(int a=1; a<=n; a++){
			cout<<b[c][a];
		}
		cout<<endl;
	}
	**/
	
	cout<<"C  #  ";
	for(j=0; j<=n; j++)
		cout<<Y[j]<<"  ";
	cout<<endl<<"#  ";

	for(i=0; i<=m; i++){
	
		for(j=0; j<=n; j++){
			cout<<c[i][j]<<"  ";
		}
		cout<<endl<<X[i]<<"  ";
	}
	
	cout<<endl<<"LCS = "<<c[m][n]<<endl;
	cout<<"Order of string : ";
	
	Print_LCS(b,X,m,n);
}

int main(){
	char X[10], Y[10];
	cout<<"Enter 1st string : ";
	gets(X);
	cout<<"Enter 2nd string : ";
	gets(Y);
	LCS_Length(X,Y);
	
	return 0;
}
