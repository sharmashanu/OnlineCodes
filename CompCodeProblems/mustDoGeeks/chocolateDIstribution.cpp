#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;cin>>t;
	while(t--){
	    long long n;cin>>n;
	    vector<long>v;
	    for(int i=0;i<n;i++){
	        long long temp;cin>>temp;
	        v.push_back(temp);
	    }
	    int m;cin>>m;
	    sort(v.begin(),v.end());
	    int start=0,end=m-1;
	    long long min=INT_MAX;
	    while(end<n){
	        long long diff = abs(v[start]-v[end]);
	        if(diff<min){
	            min=diff;
	        }
	        start++;end++;
	    }
	    cout<<min;
	    cout<<endl;
	}
	return 0;
}