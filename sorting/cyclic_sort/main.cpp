#include <iostream>
using namespace std;

int main(){
    int arr[]={4,3,5,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(auto el: arr){
        cout<<el<<" ";
    }
    cout<<endl;
    
    //cycle sort
    
    int i=0;
    while (i<n){
        int correct_idx = arr[i]-1;
        if(i==correct_idx) i++;
         else swap(arr[i],arr[correct_idx]);
    }
    for(auto el: arr){
        cout<<el<<" ";
    }
}
