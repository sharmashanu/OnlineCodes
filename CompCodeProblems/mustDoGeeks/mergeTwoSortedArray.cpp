#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        int x=0,y=0;
        for(int i=0;i<n+m;i++){
            if(x==n){
                cout<<b[y]<<" ";y++;
            }
            else if(y==m){
                cout<<a[x]<<" ";x++;
            }
            else if(a[x]<=b[y]){
                cout<<a[x]<<" ";
                x++;
            }
            else{
                cout<<b[y]<<" ";
                y++;
            }
        }
        cout<<endl;
    }
	return 0;
}