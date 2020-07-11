#include<bits/stdc++.h>
using namespace std;
//There can't be a O(n) solution maintaining the lexicographical order.O(n)
vector<int> waveArray(vector<int >&arr){
    for(int i=0;i<arr.size();i++){
        if(i>0 && arr[i-1]>arr[i])swap(arr[i],arr[i-1]);
        if(i<arr.size()-1 && arr[i+1]>arr[i])swap(arr[i],arr[i+1]);
    }
    return arr;
}
//O(n log n)
vector<int> wave(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i=0;i<A.size()-1;i++){
        swap(A[i],A[i+1]);
        i++;
    }
    return A;
}
