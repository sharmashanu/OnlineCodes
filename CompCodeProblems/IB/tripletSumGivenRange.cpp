// Given an array of real numbers greater than zero in form of strings.
// Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
// Return 1 for true or 0 for false.

#include <bits/stdc++.h> 
using namespace std; 
int solve(vector<string> &A) {
    if(A.size()<3)return 0;
    double a=stod(A[0]);
    double b=stod(A[1]);
    double c=stod(A[2]);
    if(a+b+c>1.0 && a+b+c<2.0)return 1;
    for(int i=3;i<A.size();i++){
        if(stod(A[i])>2.0)continue;
        if(a+b+c>1.0 && a+b+c<2.0)return 1;
        else if(a+b+c>2.0){
            double temp = max(a,max(b,c));
            if(temp==a)a=stod(A[i]);
            else if(temp==b)b=stod(A[i]);
            else c=stod(A[i]);
        }
        else if(a+b+c<1.0){
            double temp = min(a,min(b,c));
            if(temp==a)a=stod(A[i]);
            else if(temp==b)b=stod(A[i]);
            else c=stod(A[i]);
            
        }
    }
    if(a+b+c>1.0 && a+b+c<2.0)return 1;
    return 0;
}
