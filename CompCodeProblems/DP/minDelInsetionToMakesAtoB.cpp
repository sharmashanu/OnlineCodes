#include<bits/stdc++.h>
using namespace std;

int LCS(string str1,string str2,int n,int m){
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0)t[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    int del =str1.size()-t[n][m];
    int ins = str2.size()-t[n][m];
    return (del+ins);
}
int main()
 {
	int c;cin>>c;
	while(c--){
	    int n,m;cin>>n>>m;
	    string str1,str2;cin>>str1>>str2;
	    cout<<LCS(str1,str2,n,m);
	    cout<<endl;
	}
	return 0;
}