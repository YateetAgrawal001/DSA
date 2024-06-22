#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map <string, int>(m);
    pair <string, int>p1,p2,p3;
    p1.first = "Raghav";
    p2.first = "laxman";
    p3.first = "Xatrudhan";
    p1.second = 10;
    p2.second = 20;
    p3.second = 30;
    
    // inserting in maps
    
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    
    // printing
    
    for(auto p : m){    // will print randomly
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<m["Raghav"]; //gives the value of raghav
    
    //find is same as sets
    
    m.erase("Raghav"); //erase its freq along with its value(key
    
     
    
}
