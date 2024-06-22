#include<iostream>
#include<string>
#include<sstream>
using namespace std;


int main(){
    vector<string> s;
    s.push_back("flower");
    s.push_back("flow");
    s.push_back("flight");
//    s.push_back("yateet");
//    s.push_back("jatin");
    
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<endl;
    }
    
    cout<<endl;
    
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<endl;
    }
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<endl;\
    }
}
