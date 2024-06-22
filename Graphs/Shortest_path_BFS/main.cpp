#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
using namespace std;
unordered_set<int> visited;
vector<list<int> >graph;
vector<vector<int>> result;
int v;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

//void bfs(int src, int dest,vector<int> &dist){
void bfs(int src,vector<int> &dist){

    queue<int> q;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    q.push(src);
    while(not q.empty()){
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(auto neighbour : graph[curr]){
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr]+1;
            }
        }
    }
}

        
  

int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    while(e--){
        int s ,d ;
        cin>>s>>d;
        add_edge(s,d);
        
    }
//    int x,y;
    int x;
//    cin>>x>>y;
    cin>>x;
    vector<int> dist;
//    bfs(x,y,dist);
    bfs(x,dist);
    cout<<endl;
    for(int i =0; i<dist.size(); i++){
        cout<<dist[i]<<" ";
        
    }
    cout<<endl;
}

