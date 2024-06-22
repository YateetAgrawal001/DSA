#include<iostream>
#include<queue>
using namespace std;

void display(queue <int>& q){
    int n = q.size();
    for(int i =0;i<n;i++){
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        q.push(x);
        
    }
}
int main(){
    queue <int> q;
    //push ,//pop, //front-->top, //size, //back
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
//    cout<<q.front()<<endl;
//    cout<<q.back()<<endl;
//    cout<<q.size()<<endl;
//    q.pop();
//    cout<<q.front()<<endl;
//    cout<<q.back()<<endl;
//    cout<<q.size()<<endl;
    display(q);
    

}


