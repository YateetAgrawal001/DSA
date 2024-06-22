#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    stack<int> temp;
    cout<<st.size()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    
    //printing values in stack
    while(st.size()>0){
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    //cout<<st.top(); // stack is empty here because we are poping and not storing popped elements
    cout<<temp.size();
    //here we used another stack
    //putting elements from temp to st
    while(temp.size()>0){
        st.push(temp.top());
        st.pop();
    }

}
