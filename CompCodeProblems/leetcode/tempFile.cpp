#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter String : ";
    cin>>s;
    int c=0;
    set<char>st;
    vector<int>count;
    for(int i=0;i<s.length();i++){
        if(i<s.length()-1){
            if(s[i]!=s[i+1]){
                auto it = st.find(s[i]);
                if(it!=st.end()){
                    count.push_back(c);
                    st.clear();
                    c=0;
                }
                else{
                    st.insert(s[i]);
                    c++;
                }
            }
            else{
                i++;
                c++;
                count.push_back(c);
                st.clear();
                c=0;
            }
        }else{
            c++;
            count.push_back(c);
            c=0;
        }
        
    }
    
    cout<<*max_element(count.begin(),count.end());
    return 0;
}