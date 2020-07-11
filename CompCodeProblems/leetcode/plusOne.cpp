#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& A) {
        int n = A.size();int c=0;
        vector<int>t;
        if(A[n-1]+1==10){
            int k=n-1;
            while(k>-1 && A[k]+1==10){
                A[k]=0;
                c++;
                k--;
            }
            if(k>-1 && A[k]+1!=10){
                A[k]+=1;
                return A;
            }
            else{
                t.push_back(1);
                for(int i=1;i<=c;i++){
                    t.push_back(0);
                }
                return t;
            }
        }
        else{
            A[n-1]+=1;
            int ind=0;
            for(int i=ind;i<A.size();i++){
                t.push_back(A[i]);
            }
            return t;
        }
        return {};
    }
};