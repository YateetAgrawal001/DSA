#include<iostream>
#include<stack>
using namespace std;
void print (stack<int> st){
    stack<int> temp;
    while(st.size()>0){
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()>0){
        st.push(temp.top());
        st.pop();
    }
}

void pushAtidx(stack <int> &st,int i,int val){
    stack<int> temp;
    while(st.size()>i){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
       st.push(temp.top());
        temp.pop();
    }
}
//reverse using recursion
void display_rec(stack<int> st){
    if(st.size()==0) return;
    cout<<st.top()<<" ";
    int x = st.top();
    st.pop();
    display_rec(st);
    st.push(x);
}
void pushAtbottom(stack<int>& st,int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtbottom(st,val);
    st.push(x);
}

void reverse_rec(stack<int> &st){
    if(st.size()==0) return ;
    int x = st.top();
    st.pop();
    reverse_rec(st);
    pushAtbottom(st,x);
}


int main(){
    stack<int> st;
    stack<int> temp;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
//    print(st);
   // pushAtidx(st,2,100);
    //print(st);
    
    //pushAtbottom(st,200);
    reverse_rec(st);
    display_rec(st);
    return 0;
}

