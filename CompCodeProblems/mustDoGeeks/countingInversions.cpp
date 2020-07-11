#include <iostream>
using namespace std;

int merge(int arr[],int left,int mid,int right){
    int i=left,j=mid,k=left,mcount=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    while(i<mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            mcount +=(mid-i); 
        }
    }
    while(i<mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    for(i=left;i<=right;i++){
        arr[i]=temp[i];
    }
    return mcount;
}



int leftRightMergeCount(int arr[],int left,int right){
    int lrcount=0;
    if(right>left){
        int mid = (left+right)/2;
        
        lrcount = leftRightMergeCount(arr,left,mid);
        lrcount +=leftRightMergeCount(arr,mid+1,right);
        
        lrcount+= merge(arr,left,mid+1,right);
    }
    return lrcount;
}

int countingInversion(int arr[],int n){
    int count = leftRightMergeCount(arr,0,n-1); 
    return count;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<countingInversion(arr,n)<<endl;
	}
	return 0;
}