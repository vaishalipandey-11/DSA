#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    bool solve(int i , int n, vector<int>&result, vector<bool>&used){
        // check for out of bound 
        if(i>=result.size()){//at the end so everything is right
            return true ;
            }  
        //check for num exist 
        if(result[i] != -1){ 
           return solve(i+1 , n , result , used);
        }
        // using greedy aproach here so from the last 
        for(int num = n ; num>=1 ; num--){
            //check in the flag 
            if(used[num]==true){
                continue;
                }
                //try
               used[num]=true;
               result[i]=num;


            //EXPLORE
            //if the 1
            if(num == 1){
                if(solve(i+1, n , result,used)==true){
                    return true;
                    }
            }else{
                // num is not 1 toh find diff 
                int d = result[i]+i;
                //chek out bound and empty
                if(d<result.size() && result[d]==-1){
                    result[d]=num;
                    if(solve(i+1,n,result,used)==true){
                        return true;
                        }
                     result[d]=-1;

                }
            }
            //backtrack
            used[num]=false;
            result[i]=-1;
        
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
       //a result vector 
       vector<int>result(2*n-1 , -1);
       // a flag vector used to track the used numbers
       vector<bool>used(n+1 , false);
       solve(0,n , result,used); 
        return result ;
    }
};