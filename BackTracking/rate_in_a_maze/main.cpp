#include<iostream>
#include<vector>

using namespace std;

int ans;

bool canWeGo(vector<vector<int>>& grid, int n , int i, int j){
    return i>=0 and j>=0 and i<n and j<n and grid[i][j] == 0;
}

void f(vector<vector<int>>& grid, int n , int i=0, int j=0){
    if(i == n-1 and j== n-1) {
        ans++;
        return;
    }
    grid[i][j] = 2;
    
    if(canWeGo(grid, n, i, j-1)){
        f(grid, n, i, j-1);
    }
    if(canWeGo(grid, n, i-1, j)){
        f(grid, n, i-1, j);
    }
    if(canWeGo(grid, n, i, j+1)){
        f(grid, n, i, j+1);
    }
    if(canWeGo(grid, n, i+1, j)){
        f(grid, n, i+1, j);
    }
    grid[i][j] =0;
    
}

int main(){
    int n = 7;
    vector<vector<int>> grid = {
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0}
    };
    f(grid,7);
    cout<<ans<<endl;
    
    return 0;
}
