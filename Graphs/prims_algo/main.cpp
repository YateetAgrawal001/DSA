#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#define pp pair<int,int>
#define ll long long int
using namespace std;

// ALGO :-  DS --- Visited set, priority Queue (min), unordered map
/*
 - insert pair of <--1, src int the queue
 - one by one remove the root element of the pq
 - if the root element is already visited , then we will just continue
 - we store the wt of the pair in the ans
 - update the mapping
 - go to every neighbor of the curr element, and only add those which are non visited and have a better wt proposition
 */
vector<list<pp>> gr;
void add_edge(int u, int v,int wt, bool bidir = true){
    gr[u].push_back({v,wt});
    if(bidir){
        gr[v].push_back({u,wt});
    }
}

ll prims(int src,int n){
    priority_queue<pp, vector<pp>,greater<pp> > pq;
    unordered_set<int> vis;
    vector<int> par(n+1);
    unordered_map<int, int>mp;
    for(int i=1; i<=n; i++){
        mp[i] = INT_MAX;
    }
    pq.push({0,src});
    mp[src] = 0;
    int total_count = 0;
    int result =0;
    while(total_count<n and !pq.empty()){
        pp curr =pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        total_count++;
        result += curr.first;
        pq.pop();
        for(auto neighbor : gr[curr.second]){
            if(!vis.count(neighbor.first) and mp[neighbor.first] > neighbor.second){
                pq.push({neighbor.second, neighbor.first});
                par[neighbor.first] = curr.second;
                mp[neighbor.first] = neighbor.second;
            }
        }
        
    }
    return result;
}



int main(){
    int n ,m;
    cin>>n>>m;
    gr.resize(n+1, list<pp>());
    while(m--){
        int u , v , wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    cout<<prims(src,n)<<endl;
    return 0;
}

// TC = O(vlogv)

