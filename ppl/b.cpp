#include <bits/stdc++.h>
using namespace std;

char* delimit;
char* delimitter;
int count1,count2;
 string liner;
class line : public string {};

std::istream &operator>>(std::istream &is, line &l)
{
    std::getline(is, l);
    return is;
}

int main()
{
	//output file/table
	ofstream MyFile("filename.txt");
	
	//creating inner table
    std::ifstream inputFile("inner.txt");
    
    istream_iterator<line> begin(inputFile);
    istream_iterator<line> end;
  //  std::ifstream out("outer.txt");
    //istream_iterator<line> beginner(out);
    //istream_iterator<line> end;
        
	//istream_iterator<line> countone;
//	ifstream file("main.cpp");
    /*while (getline(inputFile, liner))
        count1++;
    
    while (getline(out, liner))
        count2++;
        */
        
   // istream_iterator<line> counttwo;
    //for(counttwo = beginner; counttwo != end; counttwo++)
    //{
    //	count2++;
    //}

    	
    istream_iterator<line> it;
    istream_iterator<line> itr;
    for(itr = begin; itr != end; itr++)
    {
    	std::ifstream outfile("outer.txt");
   	    istream_iterator<line> beginning(outfile);
		for( it = beginning; it != end; it++)
		{

		    int n = (*it).length();

    char char_array[n + 1];

    strcpy(char_array, (*it).c_str());

    delimit=char_array;
    memcpy(delimit,char_array,sizeof(char_array));   
    char *token = strtok(delimit, "\t");
   // printf("--------------%s---------------\n", token);
    std::string answer;
    answer.assign(token);
  
    int p = (*itr).length();

    char in_array[p + 1];

    strcpy(in_array, (*itr).c_str());
 
        
    delimitter=in_array;
    memcpy(delimitter,in_array,sizeof(in_array));   
    char *tokener = strtok(delimitter, "\t");
    tokener = strtok(NULL, "\t");
    //printf("--------------%s---------------\n", tokener);
    std::string ans;
    ans.assign(tokener);
    
    if(ans.compare(answer)==0)

    {
     cout << *itr<< *it <<endl;
	 MyFile << *itr <<"\t"<< *it <<endl;	
	}
		

    	}

	}


}