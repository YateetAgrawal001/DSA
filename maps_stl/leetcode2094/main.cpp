#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> 3digitka_num(vector<int>&arr){
    unordered_map<int,int> m;
    vecot<int> ans;
    for(int i = 0;i<arr.size();i++){
        m[arr[i]]++;
    }
    for(int i =100;i<=999;i+2){
        int x =i;
        int a = x%10;
        x/=10;
        int b = x%10;
        x/=10;
        int c = x;
        if(m.find(a)!=m.end()){
            m[a]--;
            if(m.find(b)!=m.end()){
                m[b]--;
                if(m.find(c)!=m.end()){
                    ans.push_back(i);
                }
                m[b]++;
            }
            m[a]++;
                
        }
    }
    return ans;
}


//letcode 1814

int rev(int &n){
    int r =0;
    while(n>0){
        r*=10
        r+=(n%10);
        n/=10;
    }
    return r;
    }
}

//main code;>

int n = nums.size();
int count=0;
unordered_map<int, int>m;
for(int i =0;i<n;i++){
    nums[i]= rev(nums[i]);
}
for(int i =0;i<n;i++){
    if(m.find(nums[i]!=m.end())) {
        count = count%1000000007;
        count+=m[nums[i]];
        m[nums[i]]++;
    }
    else m[nums[i]]++;
    
    }
return count=count%1000000007;

//leetcode
