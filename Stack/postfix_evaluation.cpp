#include<iostream> 
#include<stack>
using namespace std;
 
int solve (int a, int b, char ch){
    if(ch == '+') return a+b;
    else if(ch == '-') return a-b;
    else if(ch == '*') return a*b;
    else if(ch == '/') return a/b;
}

int main(){
    string s = "1+9*4/8-3";
    stack<int> val;
    //stack<char> op;

    for(int i =0; i<s.length();i++){
        if(s[i]>=48 && s[i]<=57)
            val.push(s[i]-48);

            else {
                int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();
                int ans = solve(val1,val2,s[i]);
                val.push(ans);
            }
    }
        

    cout<<"your ans is:"<<val.top()<<endl;
   
}