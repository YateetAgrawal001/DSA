#include<iostream>
#include<vector>
#include<list>
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
bool dfs(int src, int parent ,unordered_set<int>& vis ){
    vis.insert(src);
    for(auto neighbor : graph[src]){
        if(vis.count(neighbor) and neighbor != parent){
            //cycle detected
            return true;
        }
        if(!vis.count(neighbor)){
           bool res =  dfs(neighbor,src,vis);
            if(res == true ) return true;
        }
    }
    return false;
}

bool has_cycle(){
    unordered_set<int> visited;
    bool result = false;
    for(int i =0 ; i< v; i++){
        if(!visited.count(i)){
            result = dfs(i,-1,visited);
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
