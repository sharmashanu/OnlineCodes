#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int val[],int w,int n){
    int t[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][w];
            }
        }
    }

    return t[n][w];
}

int main(){
    int n;
    cout<<"Enter total no. of items : ";cin>>n;
    int wt[n],val[n],w;
    cout<<"Enter wt[i] : val[i]"<<endl;
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    cout<<"Enter capacity of knapsack : ";cin>>w;
    int ans = knapsack(wt,val,w,n);
    cout<<"Maximum profit is : "<<ans<<endl;
    return 0;
}