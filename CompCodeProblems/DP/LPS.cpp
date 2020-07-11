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
    return t[n][m];
}
int main()
 {
	int c;cin>>c;
	while(c--){
	    string str1,str2;cin>>str1;
	    int n = str1.size();
	    string temp = str1;
	    reverse(str1.begin(),str1.end());
	    str2=str1;
	    str1=temp;
	    cout<<LCS(str1,str2,n,n);
	    cout<<endl;
	}
	return 0;
}