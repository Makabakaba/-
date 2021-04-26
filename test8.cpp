#include<bits/stdc++.h>

using namespace std;

#define M 100
int Rec[M][M]; //������ Ui~~Uj �����ŷָ�λ��
int dp[M][M]; //��������� Ui~~Uj����������˷�����С���� ��Ŀ��dp[1][n] 
int n, p[M];  //������� , ����ά������ 


void MartixChainMultiply(){
	int q;
	// ��ʼ�� 
	for(int i=1;i<=n;i++){
		dp[i][i] = 0;
	}
	for(int l=2;l<=n;l++){ //���������ȴ�С���� 
		for(int i=1;i<=n-l+1; i++){  //���μ��������� ��n-l+1��Χ����ʼ����+1 
			int j = i+l-1;    //�ȼ�l = j-i+1, ���Ĺ��� 
			dp[i][j] = INT_MAX;
			for(int k=i;k<=j-1;k++){ //ö�����зָ�λ�� 
				q = dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
				if(q< dp[i][j]){    //����, ��¼ 
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
	cout<<"��������������\n";
	cin>>n;
	cout<<"�������ά�����飺("<<n+1<<"��)\n";
	for(int i=0;i<=n;i++){
		cin>>p[i];
	} 
	MartixChainMultiply();
	cout<<"��n="<<n<<"���Ž�Ϊ��"<<dp[1][n]<<"\n";
	cout<<"������ŵķ���";
	print(1,n);
	return 0;
}
