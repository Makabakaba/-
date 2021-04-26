#include<bits/stdc++.h>

using namespace std;

#define M 100
int Rec[M][M]; //矩阵链 Ui~~Uj 的最优分割位置
int dp[M][M]; //计算矩阵链 Ui~~Uj的所需标量乘法的最小次数 ，目的dp[1][n] 
int n, p[M];  //矩阵个数 , 矩阵维度数组 


void MartixChainMultiply(){
	int q;
	// 初始化 
	for(int i=1;i<=n;i++){
		dp[i][i] = 0;
	}
	for(int l=2;l<=n;l++){ //矩阵链长度从小到大 
		for(int i=1;i<=n-l+1; i++){  //依次计算子问题 ，n-l+1范围，初始化了+1 
			int j = i+l-1;    //等价l = j-i+1, 填表的过程 
			dp[i][j] = INT_MAX;
			for(int k=i;k<=j-1;k++){ //枚举所有分割位置 
				q = dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
				if(q< dp[i][j]){    //更新, 记录 
	 				dp[i][j] = q; Rec[i][j] = k; 
				} 
			}
		}
	} 
}

void print(int i,int j){
	if(i == j){
		cout<<"A"<<i; 
	}
	else{
		cout<<"(";
		print(i,Rec[i][j]);
		print(Rec[i][j]+1,j); 
		cout<<")";
	}
}

int main(){
	cout<<"请输入矩阵个数：\n";
	cin>>n;
	cout<<"输入矩阵维度数组：("<<n+1<<"个)\n";
	for(int i=0;i<=n;i++){
		cin>>p[i];
	} 
	MartixChainMultiply();
	cout<<"当n="<<n<<"最优解为："<<dp[1][n]<<"\n";
	cout<<"添加括号的方法";
	print(1,n);
	return 0;
}
