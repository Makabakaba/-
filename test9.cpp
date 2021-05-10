/*
LCS�㷨�� 

#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
int dp[N][N];

int main() {
    string a, b;
    cout<<"��������X��\n";
    getline(cin, a);
    cout<<"��������Y��\n";
    getline(cin, b);

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << "����������г���Ϊ��" <<dp[a.length()][b.length()] << endl;
    return 0;
}
*/ 

//�������⣺

#include<stdio.h>
 
int max(int a, int b) { return (a > b)? a : b; }
 
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
 
int main()
{
    int i, n, val[20], wt[20], W;
    
    printf("��������Ʒ������");
    scanf("%d", &n);
    
    printf("������ÿ����Ʒ�ļ�ֵ��������\n");
    for(i = 0;i < n; ++i){
    	scanf("%d%d", &val[i], &wt[i]);
    }
 
    printf("�����뱳���ܳ��ܵ�������");
    scanf("%d", &W);
    
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
