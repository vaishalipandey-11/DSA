#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void getmax(int idx, vector<int>& nums, vector<int>& temp,
                vector<int>& result, int prev) {
        // base case if idx out of bound y phr
       if(idx >= nums.size()){
        if(temp.size() >result.size()){
            result = temp ;
        }
        return ;
       }

       if(prev ==-1 || nums[idx]%prev ==0){
        temp.push_back(nums[idx]);
        getmax(idx+1 , nums , temp , result , nums[idx]);
        temp.pop_back();
       }
       getmax(idx+1 , nums , temp , result , prev);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<int> result;
        getmax(0, nums, temp, result, -1);
        return result;
    }
};

//Approach-2 (Using Bottom Up same as LIS) - Just need to keep track of how to print LIS
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<int> t(n, 1);

        vector<int> prev_idx(n, -1);
        int last_chosen_index = 0;
        int maxL = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j] == 0) {
                    if(t[i] < t[j]+1) {
                        t[i] = t[j]+1;
                        prev_idx[i] = j;
                    }

                    if(t[i] > maxL) {
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }
            }
        }

        vector<int> result;
        while(last_chosen_index >= 0) {
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        return result;
    }
};