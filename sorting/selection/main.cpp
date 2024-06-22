#include <iostream>
using namespace std;

int main(){
    int arr[5]={5,4,3,2,1};
    int n =5;
    
    for(int i=0;i<4;i++){
        int min= INT_MAX;
        int mindx=-1;
        for(int j=i;j<5;j++){
            if(arr[j]<min){
                min=arr[j];
                mindx=j;
            }
        }
        swap(arr[i],arr[mindx]);
    }
    for(auto x: arr){
        cout<<x<<" ";
    }
}

