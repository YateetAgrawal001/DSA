#include<iostream>
#include<string>
using namespace std;

int main(){
    //    string s = "yateet";
    //
    //
    //    int value=0;
    //
    //    for(int i=0;i<s.length();i++){
    // int count=0;
    //        for(int j=1;j<s.length();j++){
    //            if(s[i]==s[j]) value++;
    //        }
    //        if(count<=value) count=value;
    //    }
    //    cout<<count;
    
    
    //precise way of doing this
    string s = "yateet";
    vector<int> a(26,0);
    
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        int ascii=(int)(ch);
        a[ascii-97]++;
    }
    int mx=0;
    for(int i=0;i<26;i++){
        if(a[i]>mx) mx=a[i];
    }
    for(int j=0;j<26;j++){
        if(a[j]==mx){
            int ascii=j+97;
            char ch= (char)ascii;
            cout<<ch<<" "<<mx<<endl;
        }
    }
    
}
