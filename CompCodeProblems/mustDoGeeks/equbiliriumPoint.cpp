#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n],sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        int temp=sum,flag=0;
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(l==sum-l-arr[i]){
                cout<<i+1<<endl;
                flag=1;
                break;
            }
            l+=arr[i];
        }
        if(!flag){
            cout<<"-1"<<endl;
        }
    }
	return 0;
}