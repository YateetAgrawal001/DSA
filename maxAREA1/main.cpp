#include<iostream>
#include<cmath>


int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int row=dimensions.size();
        int x=0;
        int y=1;
        double dia_len;
        int temp;
        vector<double> v;
        vector<int> area;
        int result=0;
            for(int j=0;j<row;j++){
                
                    temp=(dimensions[j][x]*dimensions[j][x]+dimensions[j][y]*dimensions[j][y]);
                
                area.push_back(temp);
                dia_len = sqrt(temp);
                v.push_back(dia_len);
                temp=0;
            }
        for(int i=0;i<v.size();i++){
            if(v[i]<v[i+1])  result=area[i+1];
            
            else if(v[i]==v[i+1]) result=area[i];
            
            else result=area[i];
        }
        return result;
    }
int main(){
    
}

