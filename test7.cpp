#include<bits/stdc++.h>

using namespace std;

const int M = 5;
const int N = 6;

int bestInvest(int a[M][N], int f[M][N], int n, int money){
	for(int i=1; i<=n; i++){
		for(int j=0; j<=money; j++){
			a[i][j] = 0;
			for(int k=0; k<=j; k++){
				if(a[i][j] < f[i][k]+a[i-1][j-k])
					a[i][j] = f[i][k]+a[i-1][j-k];
			}
		}
	}
	return a[n][money];
}

int main(){
	int a[M][N] = {0};
	int f[M][N] = {0,0,0,0,0,0,
				   0,11,12,13,14,15,
				   0,0,5,10,15,20,
				   0,2,10,30,32,40,
				   0,20,21,22,23,24};
	cout << bestInvest(a, f, 4, 5)<<endl;
	system("pause");
	return 0;
}
