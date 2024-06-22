#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    
    int count=0;
    int i=0;
    
    while(i<s.length()){
        if(s.length()==1) count =0;
        else if(s.length()==2) count=1;
        else if(s[i]!=s[i+1] && s[i]!=s[i-1]){
            count++;
        }
        
       
        i++;
    }
    cout<<count;
}
