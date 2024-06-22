#include<iostream>
#include<vector>
using namespace std;

vector<int> st;

void buildtree(int arr[],int i, int lo, int hi ){
    if(lo == hi) {
        st[i] = arr[lo];
        return;
    }
    int mid = (lo+(hi-lo)/2);
    buildtree(arr, 2*i+1, lo, mid); //left subtree
    buildtree(arr, 2*i+2, mid+1, hi); // right subtree
    st[i] = max(st[2*i+1],st[2*i+2]);
}

int getMax(int i, int lo, int hi, int& l , int& r){
    if(l > hi || r < lo) return INT_MIN;
    if(lo >= l && hi<=r) return st[i];
    int mid = (lo+(hi-lo)/2);
    int leftmax = getMax(2*i+1, lo, mid,l , r);
    int rightmax = getMax(2*i+2, mid+1, hi ,l , r);
    return max(leftmax, rightmax);
}
int main(){
    int arr[] = {1,4,2,8,6,4,9,3};
    int n = sizeof(arr)/4;
    st.resize(4*n);
    buildtree(arr,0,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cout<<"Enter the range"<<":";
        cin>>l>>r;
        cout<<getMax(0,0,n-1,l,r);
    }
    
}
