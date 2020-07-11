#include<bits/stdc++.h>
using namespace std;

int coinChangeMin(int arr[],int n,int sum){
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=INT_MAX-1;
            }else if(j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(j%arr[0]==0){
                t[i][j]=j/arr[0];
            }
            else{
                t[i][j]=INT_MAX-1;
            }
        }
    }
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=min(t[i][j-arr[i-1]]+1,t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
 {
	int t;cin>>t;
	while(t--){
	    int sum,n;cin>>sum>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)cin>>arr[i];
	    int x = coinChangeMin(arr,n,sum);
	    if(x!=INT_MAX-1)cout<<x;
	    else cout<<"-1";
	    cout<<endl;
	}
	return 0;
}