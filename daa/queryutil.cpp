#include<iostream>
using namespace std;


struct Student {
    char name[20];
    char username[20];
    char password[20];
    char city[30];
    char pincode[6];
};

unsigned long long compute_hash(string const& s) {
    
    const int p = 31;
    const int m = 1e9 + 9;
    unsigned long long hash_value = 0;
    unsigned long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

unsigned long long hash8(string name,string username,string password,string city,string pin){
    const int m = 1e9 + 9;
    string abcd = name+username+password+city+pin;
    unsigned long long a = compute_hash(abcd)%m;
    return a;
}



int main() {
   
   Student st1;
   cin>>st1.name;
   cin>>st1.username;
   cin>>st1.password;
   cin>>st1.city;
   cin>>st1.pincode;
   int a = hash8(st1.name,st1.username,st1.password,st1.city,st1.pincode);
   cout<<a;
}