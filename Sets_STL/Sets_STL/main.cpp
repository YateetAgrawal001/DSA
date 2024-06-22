#include<iostream>
#include<stdio.h>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
   s.insert(5);
   s.insert(6);
   for(auto x: s){
        cout<<x<<" ";
    }
    int target = 9;
    //s.find ----> 1)- it searches in the set and if it is not found
    //then it returns its last element
    if(s.find(target)!= s.end()){   // target exists
        cout<<"exists"<<endl;
    }
    else cout<<"not exist"<<endl;

    
}
