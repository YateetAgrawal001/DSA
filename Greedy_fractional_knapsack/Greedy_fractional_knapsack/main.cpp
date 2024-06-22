#include <iostream>
#include <vector>
using namespace std;

bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    double ratio1 = (p1.first*1.0)/ (p1.first*1.0);
    double ratio2 = (p2.first*1.0)/ (p2.first*1.0);
    return ratio1>ratio2;
    
}

double fractional_knapsack(vector<int> &profit, vector<int> &weight, int n, int w){      //TC = O(nlogn) and SC = sorting algorithm
    vector<pair<int,int>> arr;
    for(int i=0; i<n; i++){
        arr.push_back({profit[i],weight[i]});
    }
    sort(arr.begin(),arr.end(),cmp);
    
    double result =0;
    
    for(int i =0;i<n;i++){
        if(arr[i].second <=w){
            result+=arr[i].first;
            w-=arr[i].second;
        }
        else {
            result += ((arr[i].first*1.0)/(arr[i].second*1.0))*w;
            w=0;
            break;
        }
    }
    return result;
}
int main(){
    vector<int> profit = {60,100,120};
    vector<int> weight = {10,20,30};
    
    int w=50;
    int n = 3;
    cout<<fractional_knapsack(profit, weight, n, w);
}
