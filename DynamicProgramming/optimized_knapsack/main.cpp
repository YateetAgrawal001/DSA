#include<iostream>
#include<vector>
#include<climits>
#define ll long long int
using namespace std;

vector<vector<ll> > dp(105,vector<ll>(100005,-1));

ll f(vector<int> &wts,vector<int> &val, int i, int tv){
    if(tv==0) return 0;
    if(i==wts.size()) return INT_MAX;
    if(dp[i][tv] != -1) return dp[i][tv];
    ll ans = INT_MAX;
    
    ans = min(ans,f(wts,val,i+1,tv));
    
    if(val[i]<=tv){
        ans = min(ans,(wts[i] + f(wts,val,i+1,tv-val[i])));
    }
    return dp[i][tv] = ans;
    
}
int main(){
    int n,w;
    cin>>n>>w;
    vector<int> wts;
    vector<int>val;
    for(int i =0;i<n;i++){
        int w,v;
        cin>>w>>v;
        wts.push_back(w);
        val.push_back(v);
    }
    int result = -1;
    for(int i =0;i<=n*1000;i++){
        if(f(wts,val,0,i)<= w){
            result  = i;
        }
    }
    cout<<result<<endl;
    }
