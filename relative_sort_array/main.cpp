#include<iostream>
#include <vector>
using namespace std;
void sortColors(vector<int>& nums) {
        int lo=0;
        int mid=0;
        int hi=nums.size()-1;


        while(mid<=hi){
            if(nums[mid==2]){
                int temp=nums[mid];
                nums[mid] = nums[hi];
                nums[hi]=temp;
                hi--;
                break;
            }
           else if(nums[mid==0]){
                int temp1 =nums[mid];
                nums[mid] = nums[lo];
                nums[lo] =temp1;
                lo++;
                mid++;
               break;
                }
            else mid++;

        }
    }
int main(){
    vector<int> v;
    
    
    v.push_back(2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
   
 
    								
    
    
    /*int a,b;
    cout<<"enter the size of array1 and array2 respectively:";
    cin>>a;
    cin>>b;
    cout<<"enter array1 elements:";
    for(int i=0;i<a;i++){
        int c;ex
        cin>>c;
        v.push_back(c);
    }
    cout<<"enter array2 elements:";
    for(int i=0;i<b;i++){
        int d;
        cin>>d;
        v.push_back(d);
    }*/
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    sortColors(v);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
