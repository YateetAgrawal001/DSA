#include <iostream>
#include<vector>

using namespace std;

void reversepart(int i,int j, vector<int> &v){
    for(int k=i;k<=j;k++){
        int temp;
       temp= v.at(i);
        v.at(i)=v.at(j);
        v.at(j)=temp;
        i++;
        j--;
    }
   
}

int main(){
    vector<int> v;
    cout<<"enter the number of elements:";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        v.push_back(m);
    }
    int key1,key2;
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    cout<<"enter the index from which you want to reverse:";
    cin>>key1;
    cout<<"enter the index to which you want to reverse:";
    cin>>key2;
    
    reversepart(key1,key2,v);
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
}
