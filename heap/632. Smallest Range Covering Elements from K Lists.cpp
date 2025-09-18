
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



class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> range = {-100000, 100000};

        int max_ele = INT_MIN;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], i, 0});
            max_ele = max(nums[i][0], max_ele);
        }

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            int min_ele = curr[0];
            int list_idx = curr[1];
            int idx_in_list = curr[2];
            pq.pop();

            if (max_ele- min_ele < range[1] - range[0]) {
                range[0] = min_ele;
                range[1] = max_ele;
            }

            if (idx_in_list + 1 < nums[list_idx].size()) {
                int next_ele = nums[list_idx][idx_in_list + 1];
                pq.push({next_ele, list_idx, idx_in_list + 1});
                max_ele = max(max_ele, next_ele);

            } else
                break;
        }
        return range;
    }
};