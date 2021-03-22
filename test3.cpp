#include<bits/stdc++.h> 
#include<vector>
using namespace std;

//int main(){/*顺序查找*/
//	vector<int> array;
//	int number;
//	while (1) {
//		cin >> number;
//		array.push_back(number);
//		if(cin.get() == '\n')
//			break;
//	}
//	int x, k=0;
//	cin >> x;
//	int len = array.size();
//	for(int i=0; i<len; i++){
//		if(array[i]==x){
//			k = 1;
//			cout << i << " ";
//		}
//	}
//	if(k == 0) cout<<"j=0";
//	return 0;
//}

int binary_search(int x, int a[], int n){
    int low, high, mid, count=0;
    low = 0;
    high = n-1;
    while(low < high){
        mid = (low+high)/2;
        if(x < a[mid])
            high = mid-1;
        else if(x > a[mid])
            low = mid+1;
        else if(x == a[mid]){
            cout<<mid;
            count = 1;
            break;
        }
    }
    if(count == 0)
        cout<<"j=0";
    return 0;
}
int main(){
    int i,x,a[100],n;
    cout<<"数组长度"<<endl;
    cin>>n;
    cout<<"数组元素"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"查找元素"<<endl;
    cin>>x;
    binary_search(x, a, n);
    return 0;
}



	  
