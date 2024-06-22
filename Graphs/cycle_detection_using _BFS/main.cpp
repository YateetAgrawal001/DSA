#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
unordered_set<int> vis;
vector<vector<int> >graph;
int v;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void display(){
    for(int i =0; i< graph.size(); i++){
        cout<<i<<"->";
        for(auto el:graph[i]){
            cout<<el<<" , ";
        }
        cout<<endl;
    }
}
bool bfs(int src){
    unordered_set<int> vis;
    queue<int> q;
    vector<int> par(v,-1);
    q.push(src);
    while(not q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbor : graph[curr]){
            if( vis.count(neighbor) and par[curr] != neighbor) return true;
            if(not vis.count(neighbor)){
                vis.insert(neighbor);
                q.push(neighbor);
                par[neighbor] = curr;
            }
        }
    }
    return false;
}

bool has_cycle(){
    unordered_set<int> visited;
    bool result = false;
    for(int i =0 ; i< v; i++){
        if(!visited.count(i)){
            result = bfs(i);
            if(result == true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin>>v;
    graph.resize(v,vector<int> ());
    int e;
    cin>>e;
    while(e--){
        int s ,d ;
        cin>>s>>d;
        add_edge(s,d);
        
    }
    display();
    bool b = has_cycle();
    cout<<(b)<<endl;
 
}
