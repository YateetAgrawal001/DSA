#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

int find(vector<int>& parent, int x){
    if(parent[x] == x ) return x;
    
    return parent[x] = find(parent,parent[x]);
 }

void Union(vector<int>& parent,vector<int>& rank, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(a==b) return;
    if(rank[a] <= rank[b]){
        parent[a] = b;
        rank[b]++;
    } else{
        parent[b] = a;
        rank[a]++;
    }
    return ;
}

struct Edge{
    int src;
    int wt;
    int des;
};

bool cmp(Edge e1, Edge e2){
    return e1.wt < e2.wt;
}

ll krushkal(vector<Edge> &input, int n , int e){
    sort(input.begin(),input.end(),cmp);
    vector<int> parent(n+1);
    vector<int> rank(n+1,1);
    
    for(int i =0; i<=n ; i++){
        parent[i] = i;
    }
    int edgecount =0;
    int i=0;
    ll ans =0;
    
    while(edgecount<n-1 and i < input.size()){
        Edge curr = input[i];
        int srcPar = find(parent, curr.src);
        int desPar = find(parent, curr.des);
        if(srcPar != desPar){
            Union(parent,rank, srcPar, desPar);
            ans += curr.wt;
            edgecount++;
        }
        i++;
    }
    return ans;
}

int main(){
    
    int n,e;
    cin>>n>>e;
    
    vector<Edge> v(e);
    
    for(int i =0; i< e; i++){
       
        cin>>v[i].src>>v[i].des>>v[i].wt;
    }
    
    cout<<krushkal(v, n, e);
    
   
    return 0;
}
