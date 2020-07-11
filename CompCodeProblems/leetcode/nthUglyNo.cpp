#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0]=1;
        int l2=0,l3=0,l5=0;
        for(int i=1;i<n;i++){
            ugly[i]=min(2*ugly[l2],min(3*ugly[l3],5*ugly[l5]));
            if(ugly[i]==2*ugly[l2])l2++;
            if(ugly[i]==3*ugly[l3])l3++;
            if(ugly[i]==5*ugly[l5])l5++;
        }
        return ugly[n-1];
    }
};