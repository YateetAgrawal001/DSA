#include<iostream> 
#include<stack>
using namespace std;
int prio(char ch)
{
    if(ch=='+' || ch=='-') return 1;
    else return 2;
}
int solve(int a, int b, char ch){
    if(ch == '+') return a+b;
    else if(ch == '-') return a-b;
    else if(ch == '*') return a*b;
    else if(ch == '/') return a/b;
}
int main(){
    string s = "(1+9)*4/8-3";
    stack<int> val;
    stack<int> op;

    for(int i =0; i<s.length();i++){
        if(s[i]>=48 && s[i]<=57)
            val.push(s[i]-48);
        
        else{
            if(op.size()==0) op.push(s[i]); 
            else if(s[i] =='(') op.push(s[i]);
            else if(op.top() =='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,val2,ch);
                    val.push(ans);
                }
                op.pop();
            }
            else if(prio(s[i])>prio(op.top())) op.push(s[i]);
            

            else{
                while(op.size()>0 && prio(s[i])<=prio(op.top())){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,val2,ch);
                    val.push(ans);

                }
                op.push(s[i]);
            }
        }
    }
    
    while(op.size()>0){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,val2,ch);
                    val.push(ans);
    }
    cout<<"your ans is:"<<val.top()<<endl;
   
}