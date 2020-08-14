#include<iostream>
        #include<string>
        using namespace std;
        int getPos(string str,int st){						//Returns the length of string after 'st' and before 'ru'
            int i=0;
           if(str[st]=='r' and str[st+1]=='u') i+=2;
            for(i+=st;str[i];i++){
                if(str[i]=='r' and str[i+1]=='u')
                    return i-st;
            }
            return -1;
        }
         
        void internetAddress(string s) {
            int len=0,i,st;
            if(s[0]=='h' and s[1]=='t' and s[2]=='t' and s[3]=='p'){
                len=getPos(s,4);
                st=4;
                cout<<"http://";
            }
            else 
            {
                if(s[0]=='f' and s[1]=='t' and s[2]=='p'){
                    len=getPos(s,3);
                    st=3;
                    cout<<"ftp://";
                }
            }
            cout<<s.substr(st,len);
            cout<<".ru";
            if(st+len+2==s.size()) return;
            cout<<"/";
            cout<<s.substr(st+len+2,s.size()-(st+len+2));
            return;
        }
        int main(){
            string st;
            cin>>st;
            internetAddress(st);
            return 0;
        }
