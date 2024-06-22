#include <iostream>
using namespace std;

int main(){
    vector <int> arr = {2,-3,4,5,-7,-1,4,-2,6};
    int n = arr.size();
    int k =2;
    vector <int> ans(  n-k+1 );
    
    
    int preidx = -1;
    for(int i =0;i<k;i++){
        if(arr[i]<0) preidx = i;
    }
    if(preidx==-1) ans[0]=1;
   else ans[0]= arr[preidx];
    
    int  i=1;
    int j =k;
    
    while(j<n){
        if(preidx>= i) ans[i]= arr[preidx];
        else{
            for(preidx=i;preidx<=j;preidx++){
                if(arr[preidx]<0) break;
            }
           if(preidx!=-1) ans[i]=arr[preidx];
           else ans[i] = 1;
        }
        i++;
        j++;
    }
    
    for(int a:ans){
        cout<<a<<" ";
    }
    
    return 0;
    
    
}
