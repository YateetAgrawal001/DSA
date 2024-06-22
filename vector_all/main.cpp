#include<iostream>
#include<vector>
using namespace std;
//void display(int a[]);

int main(){
    vector <int> v;
    vector <int> vec;
    vector <int> vex;
    
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
   // for (int i=0;i<=v.size()-2;i++){
      //  cout<<v[i]<<" ";
        
    //}
    cout<<endl;
   // v[0]=65;
    
    
    
    
    
   
  /*  for (int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
        
    }
    
    //for taking input from the user in vectors
   for (int i=0;i<6;i++){
        cin>>vec[i];
        
    }
   for (int i=0;i<4;i++){
        int x;
        cin>>x;
        vex.push_back(x);
        
    }
    
    //use of vector.at
    vec.at(2)=99;
    
    for (int i=0;i<vec.size();i++){
        cout<<vec.at(i)<<" ";
        
    }*/
    
//sortig the element in vector
    
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
        
    }
}

  
