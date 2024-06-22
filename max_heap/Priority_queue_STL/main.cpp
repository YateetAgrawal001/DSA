#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>(maxhp);//max heeap
    
    //c++ internally defaultly uses MAXHEAP
    vector<int> v = {2,4,3,6,7,57,6,0};
    priority_queue<int,vector<int>,greater<int> > hp(v.begin(),v.end()); //this is how you create MIN_HEAP
//        hp.push(3);
//        hp.push(4);
//        hp.push(11);
//        hp.push(9);
//        hp.push(14);
//        hp.push(-1);
//        hp.push(30);
//        hp.push(1114);
//        hp.push(50);
        cout<<hp.top()<<"\n";
   
     
   
}
