#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string str="yateet is a coder";
    stringstream ss(str);
    
    string temp;
    
    while(ss>>temp){
        cout<<temp<<endl;
    }
}

