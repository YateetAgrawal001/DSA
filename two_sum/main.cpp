#include<iostream>
#include<vector>

using namespace std;


int main(){
    vector <int> v;
    cout<<"enter the number of elements:";
    int n,target;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        v.push_back(m);
    }

    cout<<"enter the target number:";
    cin>>target;
    
    for(int i=0;i<=v.size()-2;i++){
        for(int j=i+1;j<=v.size()-1;j++){
            if((v.at(i)+v.at(j)==target))
                cout<<"("<<i<<" "<<j<<")"<<endl;
        }
    }
}
