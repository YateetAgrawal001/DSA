#include <iostream>
using namespace std;

//int fact(int a){
//    if(a==1 || a==0) return 1;
//    return a*fact(a-1);
//}
//
//
//int main(){
//    cout<<fact(5)<<endl;
//}
//void print(int x){
//    if(x==-1) return;
//    else{
//        cout<<x<<endl;
//        print(x-1);
//    }
//}
void print_arr(int a[],int n,int el=0){
    if(el==n) return;
    cout<<a[el]<<endl;
    print_arr(a,n,el+1);
}

int main(){
    //print(10);
    int a[5]={24,6,3,7,3};
    int n=sizeof(a)/sizeof(a[0]);
    print_arr(a,n);
}

