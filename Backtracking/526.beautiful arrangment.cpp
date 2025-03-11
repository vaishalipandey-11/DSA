#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
class Solution {
public:
    void c_h(vector<int>&v  ,  int&n , int&ans , int currNum ){
        // bc 
        if(currNum == n+1){
            ans ++;
            return ;
        }


        // 1case m solve kru
        for(int i =1 ; i<=n ; i++){
            if(v[i]==0 && (currNum%i ==0 || i%currNum==0) ){
                v[i]= currNum ;
                c_h(v, n ,ans ,currNum+1);
                // back track
                v[i]= 0;
            
            }
        }
    }
 
    int countArrangement(int n) {
    vector<int>v(n+1);
    int ans =0;
    c_h(v,n ,ans , 1);
    return ans ;  
    }
};