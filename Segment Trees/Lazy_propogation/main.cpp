#include<iostream>
#include<vector>
using namespace std;

vector<int> st;
vector<int> lazy;

void buildtree(int arr[],int i, int lo, int hi ){
    if(lo == hi) {
        st[i] = arr[lo];
        return;
    }
    int mid = (lo+(hi-lo)/2);
    buildtree(arr, 2*i+1, lo, mid); //left subtree
    buildtree(arr, 2*i+2, mid+1, hi); // right subtree
    st[i] = min(st[2*i+1],st[2*i+2]);
}
int getsum(int i, int lo, int hi, int l, int r){ //O(log(n))
    
    if(lazy[i] != 0){
        st[i] += (hi - lo + 1)*lazy[i];
        if(lo != hi){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(l > hi || r < lo) return 0;
    if(lo >= l && hi<=r) return st[i];
    int mid = (lo+(hi-lo)/2);
    int leftsum = getsum(2*i+1, lo, mid,l , r);
    int rightsum = getsum(2*i+2, mid+1, hi ,l , r);
    return leftsum + rightsum;
   
}
void updateRange (int i , int lo, int hi, int l , int r , int val){
    if(lazy[i] != 0){
        st[i] += (hi - lo + 1)*lazy[i];
        if(lo != hi){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(l > hi || r < lo) return;
    if(lo >= l && hi<=r) {
        st[i] += (hi - lo + 1)*val;
        if(lo != hi){
            lazy[2*i+1] += val;
            lazy[2*i+2] += val;
        }
        return;
    }
    int mid = (lo+(hi-lo)/2);
    updateRange(2*i+1,lo, mid, l , r, val);
    updateRange(2*i+2, mid+1, hi, l, r, val);
    st[i] = st[2*i+1] + st[2*i+2];
}
int main(){
    int arr[] = {1,4,2,8,6,4,9,3};
    int n = sizeof(arr)/4;
    st.resize(4*n);
    lazy.resize(4*n,0);
    buildtree(arr,0,0,n-1);
    cout<<getsum(0,0,n-1,1,3)<<endl;
    updateRange(0, 0, n-1, 2, 5, 10);
    cout<<getsum(0,0,n-1,1,3)<<endl;
    
}
