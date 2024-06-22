#include <iostream>
using namespace std;

int main(){
    int arr[5]={5,4,3,2,1};
    for(int i=0;i<4;i++){
        bool flag = true;
        for(int j=0;j<4;j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag==true) break;
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}
