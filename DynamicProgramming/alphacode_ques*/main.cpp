#include<iostream>
#include<string>
#include<vector>
#define ll long long int
using namespace std;

vector<ll> dp;

ll fbu(string& str){
    dp.resize(5005,0);
    
    dp[0]=1;
    if(str.size()>1){
        if(str[1]!= '0') dp[1]+= dp[0];
        if((str[0]-'0')*10 + str[1]-'0' <= 26) dp[1]++;
    }
    
    for(int i=2;i<str.size();i++){
        ll ans =0;
        if(str[i]-'0' > 0){
            ans += dp[i-1];
        }
        if(str[i-1] - '0' > 0 and (str[i-1] - '0')*10 + (str[i]-'0')<=26){
            ans+= dp[i-2];
        }
        dp[i]= ans;
    }
    return dp[str.size()-1];
}
int main(){
    string s;
    cin>>s;
    
    while(s[0] != '0'){
        dp.clear();
        cout<<fbu(s)<<"\n";
        cin>>s;
    }
}
