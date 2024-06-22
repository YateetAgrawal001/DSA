#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int

bool cmp(int x,int y){
    return x>y;
}

ll mincostToBreakSquare(vector<ll> & x, vector<ll> &y){
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    
    int hz=1;
    int yz = 1;
    int h=0, v=0;
    ll ans=0;
    while(h<y.size() && v<x.size()){
        if(y[v]>x[h]){
            ans+=y[v]*yz;
            hz++;
            v++;
        }
        else {
            ans+= x[h]*hz;
            yz++;
            h++;
        }
    }
    while(h<x.size()){
        ans+= x[h]*hz;
        yz++;
        h++;
    }
    while(v<y.size()){
        ans+=y[v]*yz;
        hz++;
        v++;
    }
    return ans;
}

int main(){
    int n,m;
    cin>>m>>n;
    vector<ll> x,y;
    for(int i=0;i<m-1;i++){
        int l;
        cin>>l;
        x.push_back(l);
    }
    for(int i=0;i<n-1;i++){
        int l;
        cin>>l;
        y.push_back(l);
    }
    cout<<mincostToBreakSquare(x, y)<<endl;
}

