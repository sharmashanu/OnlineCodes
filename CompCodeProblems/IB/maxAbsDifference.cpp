// You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.
#include<bits/stdc++.h>
using namespace std;
int maxArr(vector<int> &A) {
    int max1=INT_MIN;int min1=INT_MAX;
    int max2=INT_MIN;int min2=INT_MAX;
    for(int i=0;i<A.size();i++){
        max1=max(max1,A[i]+i);
        min1=min(min1,A[i]+i);
        max2=max(max2,A[i]-i);
        min2=min(min2,A[i]-i);
    }
    return max(max1-min1,max2-min2);
}
