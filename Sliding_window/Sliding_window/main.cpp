#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<int> v = {2,4,7,3,9,5,3};
    int n = v.size();
    
    cout<<"Enter the number for subarray:";
    int k;
    cin>>k;
    
    int i =1;
    int j=k;
    int currsum=0;
    
    for(int i =0; i<k;i++){      //it will store current sum till 0-->k
        currsum+=v[i];
    }
    
    int mindx=0;
    int sum = currsum;;
    while(j<n){
        
        sum+=v[j]-v[i-1];                 //[2,4,7,3,9,5,3]  k=3  currsum=14  mindx =1
                                        //[13,14]
        if(sum>currsum){
            currsum = sum;
            mindx = i;
            
        }
        i++;
        j++;
        
    }
    
    cout<<" largest sum is:"<<currsum<<endl;
    cout<<"index from which the subarray start is:"<<mindx<<endl;
    
    return 0;
}
