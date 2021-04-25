#include<bits/stdc++.h>
using namespace std;
int main(){
  srand( time(0));
    int n = 50 + (rand()%1000 );

	map<int,vector<int> > mx;
	map<int,vector<int> > my;

	int k=0;
	vector<pair<int,int> >v;
	for(int i=0;i<n;i++){
		int x=1+rand()%10000,y= 1+rand()%10000;
	 mx[x].push_back(y);
	 my[y].push_back(x);

		 		
	}
	int f=0;
	  for( const auto& pair : mx )
        {
            int s=0;
            int min =INT_MAX;
            int max= INT_MIN;
            for( double d : pair.second )
          {   if(d > max)
               max=d;
               if(d<min)
               min=d;
             s++;
          }if(s>=3)
            { f=1;

                std::cout <<pair.first<<"," <<min<<" " <<pair.first<<"," <<max<< "\n" ;}
                
         }
         if (f==0)
          cout<<"-1\n";
          
          cout<<"\n";

	f=0;
	

        for( const auto& pair : my )
        {int s=1;
            int min =INT_MAX;
            int max= INT_MIN;
            for( double d : pair.second ) 
            { 
                if(d > max)
               max=d;
               if(d<min)
               min=d;
             s++;
            }
            if(s>=3) {

                f=1;
          std::cout<<min <<","<<pair.first<<" " <<max<<"," <<pair.first<< "\n" ;}

        }
                 if(f==0)
                 cout<<"-1\n";

	
}