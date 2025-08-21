#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int count =1 ;
        int top =0, down =n-1 , left =0 , right =n-1;
        int id =0;

        while(left<=right && top<=down){
            if(id==0){
               for(int i=left ; i<=right ; i++){
                ans[top][i]= count ;
                count ++;
               }
               top++;
            }

            if(id==1){
                for(int i=top ; i<=down ; i++){
                    ans[i][right] = count;
                    count++;   
                }
                right--;
            }
            if(id==2){
                for(int i=right ; i>=left ; i--){
                    ans[down][i]=count ;
                    count ++;
                }
                down--;
            }
            
            if(id==3){
                for(int i=down ; i>=top ; i--){
                    ans[i][left]=count;
                    count ++;
                }
                left++;
            }

            id =(id+1)%4;

        }
        return ans ;
        
    }
};