
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int>vec(n,0);
        vector<int>range = {-100000, 100000};
        
        while(true){
            int min_ele =INT_MAX; int maxele =INT_MIN; int min_wali_list = 0;
            for(int i=0; i<n ; i++){
                int val =  nums[i][vec[i]];
                if(val < min_ele){
                    min_ele = val;
                    min_wali_list = i;
                }
                maxele =max(maxele ,val );
            }

            // update the range if required 
            if((maxele - min_ele) < (range[1]-range[0])){
                range[0]=min_ele;
                range[1]=maxele;
            }

            vec[min_wali_list]++;
            if(vec[min_wali_list ]>= nums[min_wali_list].size()){
                break;
            }
            
        }
        return range ;
    }
};