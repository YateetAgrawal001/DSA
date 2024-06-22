#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#define pp pair<int,int>
#define ll long long int
using namespace std;


vector<list<pp>> gr;
void add_edge(int u, int v,int wt, bool bidir = true){
    gr[u].push_back({v,wt});
    if(bidir){
        gr[v].push_back({u,wt});
    }
}

unordered_map<int, int> dijkstra(int src,int n){
    priority_queue<pp, vector<pp>,greater<pp> > pq;
    unordered_set<int> vis;
    vector<int> par(n);
    unordered_map<int, int>mp;
    for(int i=0; i<=n; i++){    //O(v)
        mp[i] = INT_MAX;
    }
    pq.push({0,src});
    mp[src] = 0;
   
   
    while(!pq.empty()){                  // O{(v+e).logv}
        pp curr =pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        
        pq.pop();
        for(auto neighbor : gr[curr.second]){
            if(!vis.count(neighbor.first) and mp[neighbor.first] > mp[curr.second]+neighbor.second){
                pq.push({ mp[curr.second]+neighbor.second, neighbor.first});
                par[neighbor.first] = curr.second;
                mp[neighbor.first] =  mp[curr.second]+neighbor.second;
            }
        }
        
    }
    return mp ;
}



int main(){
    int n ,m;
    cin>>n>>m;
    gr.resize(n, list<pp>());
    while(m--){
        int u , v , wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int> sp = dijkstra(src,n);
    int dest;
    cin>>dest;
    cout<<sp[dest]<<endl;
    return 0;
}

//overall TC = O(vlogv + elogv)
