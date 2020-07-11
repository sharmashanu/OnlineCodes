// You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
// Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that
//  sub array, then the whole array should get sorted.

#include <bits/stdc++.h> 
using namespace std; 

//method1 O(nlogn)
vector<int> subUnsort(vector<int> &A) {
    vector<int>arr=A;
    vector<int>ans;
    sort(arr.begin(),arr.end());
    int flag=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=A[i] && flag==0){
            ans.push_back(i);
            flag=1;
        }
    }
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]!=A[i] && flag==1){
            ans.push_back(i);
            break;
        }
    }
    if(ans.size()>0)return ans;
    return {-1};
}
//method2 Editorial
vector<int> subUnsort(vector<int> &A){
	vector<int> ans;
	int n = A.size();
	int i = 0, j = n-1;
	while(i< n - 1 and A[i] <= A[i + 1]){
		i++;
	}
	while(j > 0 and A[j] >= A[j - 1]){
		j--;
	}
	if(i == n - 1){ // if array is already sorted, output -1
		ans.push_back(-1);
		return ans;
	}
	int mn = A[i + 1], mx = A[i + 1];
	for(int k = i; k <= j; k++){
		mx = max(mx, A[k]);
		mn = min(mn, A[k]);
	}
	int l = 0, r = n - 1;
	while(A[l] <= mn and l <= i){
	   	l++;
	}
	while(A[r] >= mx and r >= j){
		r--;
	}
	ans.push_back(l);
	ans.push_back(r);
	return ans;
}

//method 3 Fastest
vector<int> subUnsort(vector<int> &arr) {
    int startIndex = -1;
    int endIndex = -1;
    vector<int> output;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i] > arr[i+1] ){
            startIndex = i;
            break;
        }
    }
    if(startIndex == -1){
        output.push_back(-1);
        return output;
    }
    for(int i=arr.size()-1;i>0;i--){
        if(arr[i-1] > arr[i]){
            endIndex = i;
            break;
        }
    }
    int minEle = INT_MAX, maxEle = INT_MIN;
    for(int i=startIndex;i<=endIndex;i++){
        minEle = min(minEle, arr[i]);
        maxEle = max(maxEle, arr[i]);
    }
    int minIndex = startIndex;
    int maxIndex = endIndex;
    for(int i = startIndex -1 ;i>=0;i--){
        if(arr[i] > minEle){
            minIndex = i;
        }
    }
    for(int i= endIndex+1;i<arr.size();i++){
        if(arr[i] < maxEle){
            maxIndex = i;
        }
    }
    output.push_back(minIndex);
    output.push_back(maxIndex);
    return output;
}

//method 4 Lightweight
vector<int> subUnsort(vector<int> &A) {
    int n=A.size();
    int count=0;
    vector<int> result;
    while(count<n-1){
        if(A[count]<=A[count+1]){
            count++;
        }
        else break;
    }
    if(count==n-1){
        result.push_back(-1);
        return result;
    } 
    int start=0;
    int end=n-1;
    int cstart=0;
    int cend=0;
    for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1]){
            start=i;
            break;
        }
    }
    cstart = A[start];
    for(int i=start+1;i<n;i++){
        if(A[i]>=cstart&&end==n-1){
            end=i-1;  
            cstart = A[i];
        } 
        else if(A[i]>cstart) cstart=A[i];
        else if(A[i]<cstart){
            end=n-1;
        }
    }
    start=0;
    cend = A[end];
    for(int i=end-1;i>=0;i--){
        if(A[i]<=cend&&start==0){
            start=i+1;
            cend = A[i];
        }
        else if(A[i]<cend) cend = A[i];
        else if(A[i]>cend){
            start=0;
        }
    }
    result.push_back(start);
    result.push_back(end);
    return result;
}
