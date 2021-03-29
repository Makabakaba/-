#include <bits/stdc++.h>
using namespace std;

int mergeList(int a[], int left, int mid, int right,
			   int temp[]){
	int i=mid+1, k=0, l=left;
 	while(left <= mid && i <= right){
  		if(a[left] <= a[i]) temp[k++] = a[left++];
  		else temp[k++] = a[i++];
	}
 	while(left <= mid)
  		temp[k++] = a[left++];
 	while(i <= right)
  		temp[k++] = a[i++];
 	for(int j=0; j<k; j++){
  		a[l+j] = temp[j];
 	}
} 

int mergeSort(int a[], int l, int r, int temp[]){
	if(l<r){
		int mid = (l+r)/2;
		mergeSort(a,l,mid,temp);
  		mergeSort(a,mid+1,r,temp);
  		mergeList(a,l,mid,r,temp);
 	}
}

int main(){
 	int n;
 	int list[100];
 	cout<<"输入数据的个数为（个数必须为2的n次）："; 
	cin>>n;
 	for(int i=0; i<n; i++){
 		cin>>list[i];
	 }
	int *temp = (int *)malloc(n*sizeof(int));
 	mergeSort(list,0,n-1,temp);
 	for(int i=0;i<n;i++)
  		cout<<list[i]<<" ";
}

