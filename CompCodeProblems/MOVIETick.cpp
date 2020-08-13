#include <bits/stdc++.h>
using namespace std;
bool already = true;

class Screen
{
	int row, col;
	vector<vector < char>> seat;

	public:
		Screen(vector<string> vect)
		{
			row = stoi(vect[2]);
			col = stoi(vect[3]);
			if (row < 0 or col < 0)
			{
				cout << "failure\n";	//If either row or NO_of_Seats per row are invalid.
				already = false;
			}
			else
			{
				for (int i = 0; i < row; i++)
				{
					vector<char> temp;
					for (int j = 0; j < col; j++)
					{
						temp.push_back('E');	//Initializing each seat as empty.
					}
					seat.push_back(temp);
				}
				if (!isValid(vect, 4))
				{
					cout << "failure\n";
					already = false;
				}
				else
				{
					for (int i = 0; i < row; i++)
					{
						for (int j = 4; j < vect.size(); j++)
						{
							seat[i][stoi(vect[j]) - 1] = 'A';	//Marking Aisle Seats.
						}
					}
					cout << "success" << endl;
				}
			}
		}

	bool isValid(vector<string> v, int a)
	{
		for (int i = a; i < v.size(); i++)
		{
			if ((stoi(v[i]) - 1) >= col or(stoi(v[i]) - 1) < 0) return false;
		}
		return true;
	}

	void ReserveSeat(vector<string> vec)
	{
		//For Booking Seats
		int row = stoi(vec[2]) - 1;
		if (row < 0 or this->row <= row)
		{
			cout << "failure\n";
			return;
		}
		if (!isValid(vec, 3))
		{
			cout << "failure\n";
			return;
		}
		for (int i = 3; i < vec.size(); i++)
		{
			if (seat[row][stoi(vec[i]) - 1] == 'B')
			{
				//If the seat is already booked,return Failure.
				cout << "failure\n";
				return;
			}
		}
		for (int i = 3; i < vec.size(); i++)
			seat[row][stoi(vec[i]) - 1] = 'B';	//If none of the seats required are pre-booked,return Success.
		cout << "success\n";
		return;
	}

	void GetUnreservedSeats(vector<string> vec)
	{
		//For printing Unreserved Seats
		int row = stoi(vec[2]) - 1;
		if (row < 0 or this->row <= row)
		{
			cout << "failure\n";
			return;
		}
		for (int i = 0; i < col; i++)
		{
			if (seat[row][i] != 'B') cout << i + 1 << " ";	//If the seat is not booked print it else skip it.
		}
		cout << endl;
	}

	bool isValidContiguous(vector<string> vec)
	{
		if (stoi(vec[2]) <= 0 or stoi(vec[2]) > col) return false;
		if (stoi(vec[3]) - 1 < 0 or stoi(vec[3]) - 1 >= row) return false;
		if (stoi(vec[4]) - 1 < 0 or stoi(vec[4]) - 1 >= col) return false;
		return true;
	}

	void SuggestContiguous(vector<string> vec)
	{
		//For printing continuous seats in either direction.
		int no_of_seats = stoi(vec[2]);
		int row_no = stoi(vec[3]) - 1;
		int seat_no = stoi(vec[4]) - 1;
		bool ans = false;
		int count = 0, aisle = 0;	//Count variable for counting valid empty seats.
		vector<int> v;
		if (!isValidContiguous(vec))
		{
			cout << "none\n";
			return;
		}
		if (seat[row_no][seat_no] == 'B')
		{
			//If the seat to be included is already booked,return failure.
			cout << "none";
			return;
		}
		if (seat[row_no][seat_no] == 'A')
		{
			//If the Seat that is to be included is aisle seat.
			if (seat[row_no][seat_no - 1] == 'A')
			{
				//If it is at the starting of section.
				for (int i = seat_no; i < col; i++)
				{
					if (seat[row_no][i] == 'E')
					{
						count++;
						v.push_back(i + 1);
					}
					else if (seat[row_no][i] == 'B') ans = true;
					else
					{
						aisle++;
						count++;
						v.push_back(i + 1);
					}
					if (count == no_of_seats)
					{
						for (int i: v) cout << i << " ";
						cout << endl;
						break;
					}
					if (ans or aisle > 1)
					{
						cout << "none\n";
						v.clear();
						return;	//If a booked seat found while searching continuous 
						//seats or more than one aisle seat,return failure.
					}
				}
			}
			else if (seat[row_no][seat_no + 1] == 'A')
			{
				for (int i = seat_no; i >= 0; i--)
				{
					//If it is at the ending of section.
					if (seat[row_no][i] == 'E')
					{
						count++;
						v.push_back(i + 1);
					}
					else if (seat[row_no][i] == 'B') ans = true;
					else
					{
						aisle++;
						count++;
						v.push_back(i + 1);
					}
					if (count == no_of_seats)
					{
						for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
						cout << endl;
						break;	//Printing vector backwards..
					}
					if (ans or aisle > 1)
					{
						cout << "none\n";
						v.clear();
						return;
					}
				}
			}
		}
		else	//If the seat is normal one i.e., not an aisle seat
		{
			bool found = false;
			for (int i = seat_no; i >= 0; i--)
			{
				//First search backwards
				if (seat[row_no][i] == 'E')
				{
					count++;
					v.push_back(i + 1);
				}
				else if (seat[row_no][i] == 'B')
				{
					ans = true;
				}
				else
				{
					aisle++;
					count++;
					v.push_back(i + 1);
				}
				if (count == no_of_seats && aisle <= 1)
				{
					//If count==required no of seats and atmost one aisle seat is included.
					for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
					found = true;
					cout << endl;
					break;
				}
				if (ans or aisle > 1)
				{
					v.clear();
					break;
				}
			}
			count = 0;
			aisle = 0;	//Making count and aisle equal to zero since continuous seats were not found in
			//backwards direction;
			if (!found)
			{
				for (int i = seat_no; i < col; i++)
				{
					//If not found search in forward direction. 
					if (seat[row_no][i] == 'E')
					{
						count++;
						v.push_back(i + 1);
					}
					else if (seat[row_no][i] == 'B') ans = true;
					else
					{
						aisle++;
						count++;
						v.push_back(i + 1);
					}
					if (count == no_of_seats && aisle <= 1)
					{
						for (int i: v) cout << i << " ";
						cout << endl;
						break;
					}
					if (ans or aisle > 1)
					{
						cout << "none\n";
						v.clear();
						break;
					}
				}
			}
		}
	}
};
vector<string> words(string str)
{
	//Breaking input string into vector of strings.
	string word = "";
	vector<string> st;
	for (auto x: str)
	{
		if (x == ' ')
		{
			st.push_back(word);
			word = "";
		}
		else
			word = word + x;
	}
	st.push_back(word);
	return st;
}
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	map<string, Screen*> mp;	//Map of string as key and reference of Screen Object as value.
	vector<string> line;
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);	//Fetching input string.
		line = words(str);	//Spliting input string
		//isvalid=true;line
		bool isvalidDigit = true;
		for (int k = 2; k < line.size(); k++)
		{
			if (line[k] == " ")
			{
				isvalidDigit = false;
			}
			string t = line[k];
			bool flag = false;
			for (int j = 0; j < t.size(); j++)
			{
				if (!isdigit(t[j]))
				{
					isvalidDigit = false;
					flag = true;
					break;
				}
			}
			if (flag) break;
		}

		if (isvalidDigit)
		{
			if (line[0] == "add-screen")
				if (mp.find(line[1]) != mp.end())
				{
					cout << "failure\n";
				}	//If the screen to be added already exists,return failure.
			else
			{
				mp[line[1]] = new Screen(line);
				if (!already)
				{
					mp.erase(line[1]);
					cout << line[1] << " not created\n";
					already = true;
				}
			}
			else if (line[0] == "reserve-seat")
			{
				if (mp.find(line[1]) == mp.end())
				{
					cout << "failure\n";
				}
				else
					mp[line[1]]->ReserveSeat(line);
			}
			else if (line[0] == "get-unreserved-seats")
			{
				if (mp.find(line[1]) == mp.end())
				{
					cout << "failure\n";
				}
				else
					mp[line[1]]->GetUnreservedSeats(line);
			}
			else if (line[0] == "suggest-contiguous-seats")
			{
				if (mp.find(line[1]) == mp.end())
				{
					cout << "failure\n";
				}
				else
					mp[line[1]]->SuggestContiguous(line);
			}
		}
		else
		{
			cout << "failure\n";
		}
	}
	return 0;
}
