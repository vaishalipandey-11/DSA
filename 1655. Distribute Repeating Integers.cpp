#include <iostream>
using namespace std;
#include<vector>
class Solution {
public:
 bool helper(vector<int>&count , vector<int>& quantity , int ithcustomer ){
    // base case 
    if(ithcustomer == quantity.size()){
        return true;
    }
    // 1 case m solve krungi 

    for(int i =0 ; i<count.size() ; i++){
        if(count[i]>= quantity[ithcustomer]){
            count[i]-= quantity[ithcustomer];
        
       if( helper(count , quantity , ithcustomer+1)){
          return true ;
       }
        
       // backtrack
       count[i] += quantity[ithcustomer];
        }

    }
    return false ;
 }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int , int> countmap ;
        for(auto num : nums)
        countmap[num]++;
        vector<int>count;
        for(auto num :countmap)
            count.push_back(num.second);
        
        sort(quantity.rbegin(), quantity.rend());
         return  helper(count , quantity , 0);
         



    }
};