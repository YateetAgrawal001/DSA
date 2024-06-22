#include <iostream>
#include <stack>
using namespace std;

int main(){
    vector<int> arr={3,1,2,5,4,6,2,3};
    int n = arr.size();
    vector<int> ans(n);
    
    stack<int> st;
    //ans[n-1] = -1;
    for(int i = n-1; i>=0;i--){
        while(st.size()>0 && st.top()<= arr[i]) st.pop();
        if(st.size()==0) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
          
    }
    for(auto el : ans){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}

