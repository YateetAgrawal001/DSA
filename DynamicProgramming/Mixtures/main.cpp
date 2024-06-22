#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

vector<vector<ll>> dp;

ll g(vector<ll> color, int i , int j){
    ll result =0;
    for(int m=i;m<=j;m++){
        result = (result%100 + color[m]%100) %100;
    }
    return result;
    
}
// ....... Tabular Method......

ll fbu(vector<ll> &color){
    dp.clear();
    dp.resize(105,vector<ll>(105,0));
    int n = color.size();
    for(int len = 2; len<=n ; len++){
        for(int i = 0; i<=n-len; i++){
            int j = i+ len -1;
            ll result = INT_MAX;
            for(int k =i; k<=j-1; k++){
                result = min(result,dp[i][k]+ dp[k+1][j]+g(color,i,k) * g(color,k+1,j));
            }
             dp[i][j] = result;
        }
    }
    return dp[0][n-1];
}

//ll f(vector<ll> &color, int i, int j){
//    if(i==j) return dp[i][j] = 0;
//    if(dp[i][j]!= -1 ) return dp[i][j];
//    ll result = INT_MAX;
//    for(int k =i; k<=j-1; k++){
//        result = min(result,f(color,i,k)+f(color,k+1,j)+g(color,i,k)*g(color,k+1,j));
//    }
//    return dp[i][j] = result;
//}

int main(){
    int n;
    
    while(cin>>n){
        vector<ll> color;
        for(int i =0;i<n; i++){
            int x;
            cin>>x;
            color.push_back(x);
             
        }
        dp.clear();
        dp.resize(105,vector<ll>(105,-1));
        cout<<fbu(color)<<endl;
        
        color.clear();
    
    }
}


