#include<iostream>
using namespace std;

struct Student {
    char name[20];
    char username[20];
    char password[20];
    char city[30];
    int pincode;
};

int main() {
   
   Student st1;
   cin>>st1.name;
   cin>>st1.username;
   cin>>st1.password;
   cin>>st1.city;
   cin>>st1.pincode;
   cout<<st1.name<<'\n'<<st1.username<<'\n'<<st1.city<<'\n'<<st1.pincode;
}