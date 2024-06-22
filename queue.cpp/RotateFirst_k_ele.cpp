#include<queue>
#include<stack>
#include<iostream>
using namespace std;

void display(queue<int>& q){
    int n = q.size();
    for(int i =0;i<n;i++){
    int x = q.front();
    cout<<x<<" ";
    q.pop();
    q.push(x);
    }
}
void reverse_k_ele(queue<int>&q , int k){
     stack<int> st;
     for(int i =0;i<k;i++){
        int x = q.front();
        q.pop();
        st.push(x);
     }
     
      for(int i =0;i<k;i++){
        int x = st.top();
        st.pop();
        q.push(x);
     }
      int n= q.size();
      for(int i=0;i<n-k;i++){
        int x = q.front();
        q.pop();
        q.push(x);

     }
}

int main(){
    queue<int> q;
   

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    display(q);
    reverse_k_ele(q,4);
    cout<<endl;
    display(q);
    
}
