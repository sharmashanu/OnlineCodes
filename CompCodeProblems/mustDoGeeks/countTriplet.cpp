#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)cin>>arr[i];
	    int start=0,end=0;int count=0;
	    sort(arr,arr+n);
	    for(int i=n-1;i>=2;i--){
	        start=0,end=i-1;
	       // cout<<count<<" "<<start<<" "<<end<<"   "<<arr[start]<<" "<<arr[end]<<endl;
	        while(start<=end){
	            if(arr[start]+arr[end]==arr[i]){
    	            count++;
    	            start++;
    	            end--;
    	        }
    	        else if(arr[start]+arr[end]<arr[i])
    	        {
    	            start++;
    	        }
    	        else if(arr[start]+arr[end]>arr[i]){
    	            end--;
    	        }
	        }
	    }
	    if(count==0){
	        cout<<"-1"<<endl;
	    }
	    else{
	        cout<<count<<endl;
	    }
	    cout<<endl;
	}
	return 0;
}