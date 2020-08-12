#include <bits/stdc++.h>
using namespace std;
class Screen {
    int row, col;
    vector<vector<char> > seat;
    
    public:
        Screen (vector<string> vect) {
            row = stoi(vect[2]);
            col = stoi(vect[3]);
            for (int i = 0; i < row; i++) {
                vector<char> temp; 
                for(int j=0;j<col;j++){
                    temp.push_back('E');
                }
                seat.push_back(temp);
            }
            for(int i = 0; i < row; i++){
            for (int j = 4; j < vect.size(); j++) {
                seat[i][stoi(vect[j])-1] = 'A';
                //cout<<stoi(vect[i])-1<<" ";
                }
         }
            cout<<"Screen added."<<endl;
        }

    
        void ReserveSeat(vector<string> vec){            
            int row=stoi(vec[2])-1;
            for(int i=3;i<vec.size();i++){     
                if(seat[row][stoi(vec[i])-1]=='B'){
                    cout<<"failure\n";
                    return;
                }
                else {
                     seat[row][stoi(vec[i])-1]='B'; }
            }
            cout<<"success\n";
            return;
        }

        void GetUnreservedSeats(vector<string> vec){
            int row=stoi(vec[2]);
            for(int i=0;i<col;i++){
                if(seat[row][i]=='E') cout<<i+1<<" ";
            }
            cout<<endl;
        }

        void SuggestContiguous(vector<string> vec){
            int no_of_seats=stoi(vec[2]);
            int row_no=stoi(vec[3])-1;
            int seat_no=stoi(vec[4])-1;
           // cout<<seat[row_no][seat_no]<<" ";
           // cout<<vec[2]<<"->"<<vec[3]<<"->"<<vec[4]<<endl;
            bool ans=false; 
            int count=0,aisle=0;
            vector<int> v;
            if(seat[row_no][seat_no]=='B') {
                cout<<"none";
                return;
            }
            if(seat[row_no][seat_no]=='A'){    //4                     //If the Seat that is to be included is aisle seat.
                if(seat[row_no][seat_no-1]=='A'){   //3
                   // cout<<"NEXT AISLE\n";                //If it is at the starting of section.
                    for(int i=seat_no;i<col;i++){
                        if(seat[row_no][i]=='E') {count++; v.push_back(i+1);}
                        else if(seat[row_no][i]=='B') { ans=true;}
                        else { 
                            aisle++; count++; 
                                v.push_back(i+1);        
                        }
                        if(count==no_of_seats){
                            for(int i:v) cout<<i<<" ";
                            cout<<endl;break;
                        }
                        if(ans or aisle>1) {cout<<"none\n"; v.clear();return;
                                                    }
                        }
                }
                else if (seat[row_no][seat_no+1]=='A'){  
                    //cout<<"AISLE NEXT\n";           //If it is at the ending of section.
                    for(int i=seat_no;i>=0;i--){
                        if(seat[row_no][i]=='E') {count++;v.push_back(i+1);}
                        else if(seat[row_no][i]=='B') { ans=true;}
                        else {aisle++; count++; 
                                v.push_back(i+1); 
                                //cout<<"i+1";
                            }
                        if(count==no_of_seats){
                            for(int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";    cout<<endl;break;
                                  }
                        if(ans or aisle>1) {cout<<"none\n"; v.clear();return;}
                    }
                }
             }
             else                                                           //If the seat is normal one i.e., not an aisle seat
             {
                 bool found=false;
                // cout<<"NEXT \n";
                    for(int i=seat_no;i>=0;i--){                             //First search backwards
                        if(seat[row_no][i]=='E') {count++; v.push_back(i+1);}
                        else if(seat[row_no][i]=='B') { ans=true;}
                        else {aisle++; count++; 
                                v.push_back(i+1);
                            }
                        if(count==no_of_seats&&aisle<=1){
                             for(int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";  found=true;   cout<<endl;break;
                                  }
                        if(ans or aisle>1) {v.clear();break;       }
                        }
                        count=0;aisle=0;
                        if(!found){       
                            //cout<<"shanu\n";                                  //If not found search forward.
                    for(int i=seat_no;i<col;i++){
                        if(seat[row_no][i]=='E') {count++; v.push_back(i+1);}
                        else if(seat[row_no][i]=='B') { ans=true;}
                        else { aisle++; count++;
                                v.push_back(i+1);
                            } 
                        if(count==no_of_seats&&aisle<=1){
                            for(int i:v) cout<<i<<" ";
                            cout<<endl; break;
                        }
                        if(ans or aisle>1) {cout<<"none\n"; v.clear();break;
                                                    }
                    }
                }
             }
        }
};
vector<string> words(string str) { 
    string word = "";
    vector<string> st;
    for (auto x : str) { 
        if (x == ' ') { 
            st.push_back(word);
            word = ""; 
        } 
        else
           word = word + x; 
    }
    st.push_back(word);
    return st;
}
int main() {
	int n;cin>>n;
    cin.ignore();
	map<string, Screen*> mp;
	vector<string> line;
	string str;
	for (int i=0; i<n; i++) {
	    getline (cin, str);
	    line = words(str);
	    
            if (line[0] == "add-screen")
        if(mp.find(line[1])!=mp.end()) {cout<<"failure\n"; } 
        else
	        mp[line[1]] = new Screen(line);
            else if (line[0] == "reserve-seat") {
                mp[line[1]]->ReserveSeat(line);
            }
            else if (line[0] == "get-unreserved-seats") {
                mp[line[1]]->GetUnreservedSeats(line);
            }
            else if(line[0]=="suggest-contiguous-seats"){
                mp[line[1]]->SuggestContiguous(line);
            }
        
	}
	return 0;
} 