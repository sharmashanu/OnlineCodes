int getRest(string str,int i)
{
	for(int j=i+1;j<str.size()-1;j++)
	{
		if(str[j]=='r'&&str[j+1]=='u')
		return j-1-i;
	}
 return -1;
}
void internetAddress(string s) {
    string ptr =s;
    int starter ,pos;
    if(s[0]=='h'&&s[1]=='t'&&s[2]=='t'&&s[3]=='p')
    {
    	cout<<"http://";
    	starter =3;
    	pos = getRest(ptr,3);
	}
	else
	{
		cout<<"ftp://";
		starter=2;
		pos =getRest(ptr,2);
	}
	cout<<(ptr.substr(starter+1,pos));
	cout<<".ru";
	pos=starter+pos+2;
	cout<<"/";
	cout<<ptr.substr(pos+1);
}
