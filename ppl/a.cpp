#include<bits/stdc++.h>
using namespace std;

//sorting based and hashing program - division operation
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//Taking the input databases
	vector<vector<string> >db1;
	// Division is an operation typically required when you want to find all distinct entities 
	// which are interacting with all entities of a different set of entities. 

	// Explanation of Division operation:
	//R1(x,z) division R2(z) means to give all the distinct values of x from R1
	// that are associated with all the values 
	cout<<"Enter No. of Attributes for Database: "<<endl;
	// Assuming that the first entry you enter is the primary key
	int n; cin>>n; vector<string>v1;
	cout<<"Enter name of Attributes for Database: "<<endl;
	for(int i = 0;i<n;i++)
	{
		string s; cin>>s;
		v1.push_back(s);
	}

	while(1)
	{
		cout<<"Do you want to enter a set of values?(y/n)"<<endl;
		char c; cin>>c;
		if(c == 'n')
			break;					
		else						
		{							
			vector<string>v;
			for(int i = 0;i<n;i++)
			{
				string s; cin>>s;
				v.push_back(s);
			}
			db1.push_back(v);
		}
	}

	// The database which has all the entries you want to get from the base database
	cout<<"Enter No. of Attributes you want the Division to work for: "<<endl;
	int m;  cin>>m;     vector<string>v2;
	cout<<"Enter Attributes you want to scrutinize for: "<<endl;
	for(int i = 0;i<m;i++)
	{
		string s; cin>>s;
		v2.push_back(s);
	}

	// A set of all the values you need the final result to have!
	set<string>wanted[m];
	for(int i=0;i<m;i++)
	{
		while(1)
		{
			cout<<"Do you want to add more values?(y/n)"<<endl;
			char c; cin>>c;
			if(c == 'n')
				break;
			else
			{
				string s; cin>>s;
				wanted[i].insert(s);
			}
		}
	}

	//Step -1: Sorting all the primary key values in the databse
	// finding indexes of attributes in database 1 and pushing it's  indices for easy availability
	int count =0;
	vector<int>index;
	for(int i = 0;i<n;i++)
	{
		if(count == m)
			break;
		else
		{
			if(v2[count] == v1[i])
			{
				index.push_back(i);
			}
		}
	}

	int flag = db1.size();
	// Set created for the deduction of repeated values 
	set<string>tk;
	for(int i = 0;i<flag; i++)
	{
		tk.insert(db1[i][0]);
	}
	
	//Map -1 created for getting index from primary key
	int users = tk.size();
	map<string,int>track; int y =0;
	for(auto itr = tk.begin(); itr!= tk.end(); itr++)
	{
		track[(*itr)] = y;
		y++;
	}
	
	//Map -2 created for getting primary key from index
	map<int,string>track1; y =0;
	for(auto itr = tk.begin(); itr!= tk.end(); itr++)
	{
		track1[y] = (*itr);
		y++;
	}
	
	// Sorting into a double array in case of multiple attributes required
	set<string>getting[users][m];
	auto it = tk.begin();
	for(int g = 0;g<m;g++)
	{
		int r = index[g];
		for(int i = 0;i<flag;i++)
		{
			(getting[(track[(db1[i][0])])][g]).insert(db1[i][index[g]]);
		}
	}


	int f[users] = {0};
	// Step -2: Code for hashing in multiple wanted attributes from the base table
	for(int i= 0 ; i<users; i++)
	{
		for(int j =0;j<m;j++)
		{
			if(getting[i][j] == wanted[j])
			{
				f[i]++;			
			}
		}
	}
	
	for(int i =0;i<users;i++)
	{
		if(f[i] == m)
			cout<<track1[i]<<" ";
	}
}