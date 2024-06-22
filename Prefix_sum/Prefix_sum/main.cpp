#include<iostream>
using namespace std;

int main(){
    int a[]={1,2,4,5,7,9};
    int n = sizeof(a)/sizeof(a[0]);
    
    for(int i =1;i<n;i++){
            a[i]= a[i-1]+a[i];
        }
    
    for(auto el:a){
        cout<<el<<" ";
    }
}
