#include <iostream>
#include <vector>
using namespace std;

class Max_heap{
    vector<int>hp;
    int i;
    
public:
    void upheapify(int ci){
        while(ci>0){
            int pi = (ci-1)/2;
            if(hp[pi]<hp[ci]) {                //for min_heap use if(hp[pi]>hp[ci])
                swap(hp[pi],hp[ci]);
                ci = pi;
            }
            else break;
        }
    }
    int peak(){
        if(hp.size()==0) return INT_MIN;
        else return hp[0];
        
    }
    
    void push(int ele){
        hp.push_back(ele);
        upheapify(hp.size()-1);
    }
    bool empty(){
        if(hp.size()<=0 ) return true;
        return false;
    }
    void display(){
        cout<<"[";
        for(auto x : hp){
            cout<<x<<" ";
        }
        cout<<"]\n";
    }
    void down_heapify(int idx){
        while(idx<hp.size()){
            int lc = 2*idx+1;
            int rc = 2*idx+2;
            if(lc >= hp.size()) break;
            int maxele = idx;
            if(hp[lc]>hp[maxele]){
                maxele = lc;
                
            }
            else if(rc > hp.size() and hp[rc]>hp[maxele]){
                maxele = rc;
                
            }
            if(maxele != idx){
                swap(hp[idx],hp[maxele]);
                idx = maxele;
            }
            else break;
        }
    }
    void pop(int ele){
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();
        if(!empty())
        down_heapify(0);
    }
    Max_heap(vector<int>v){        // optimized TC: - O(n)
        hp = v;
        int n = hp.size();
        for(int i =n/2;i>=0;i--){
            down_heapify(i);
            }
    }
};

int main(){
    vector<int> v = {9,6,1,19,3,2,8,12,5};
    Max_heap hp(v);
//    hp.push(3);
//    hp.push(4);
//    hp.push(11);
//    hp.push(9);
//    hp.push(14);
//    hp.push(-1);
//    hp.push(30);
//    hp.push(44);
//    hp.push(50);
    hp.display();
    cout<<endl;
    
    cout<<endl;
}

