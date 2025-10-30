#include <bits/stdc++.h>    
using namespace std;
class Solution {
public:
  bool ispossible(vector<int>& position,int m,int mid ){
    int count =1;
    int lastpo =position[0];

    for(int i=0;i<position.size() ; i++){

        if(position[i]-lastpo >= mid){
            count++;
            lastpo = position[i];
        }
    }
     return count >= m;


  }
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());
        int n= position.size();

        int l = 1; 
        int r= position[n-1]-position[0];
     
        int ans =0;
        while(l<=r){
            int mid = l+(r-l)/2;

            if(ispossible(position,m ,mid)){
                ans = mid;
                l=mid+1;// look for far now 
            }else{
                r=mid-1; // near please

            }
        }
        return ans;
        
    }
};