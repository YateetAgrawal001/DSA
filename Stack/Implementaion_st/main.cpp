#include<iostream>
using namespace std;
class Stack{
public:
    vector<int> arr(5);
    int idx ;
    Stack(){
        idx = -1;
    }
    void push(int val){
        if(idx==5){cout<<"stack is full";}
        idx++;
        arr[idx] = val;
    }
    void pop(){
        if(idx ==-1) cout<<"Stack is empty";
        idx--;
    }
    int top(){
        return arr[idx];
    }
    int size(){
        return idx+1;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(230);
    st.pop();
    cout<<st.size();
    cout<<endl;
    cout<<st.top()<<endl;
    
}
