#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if ((i != j && i != k && j != k) &&
                        (nums[i] + nums[j] + nums[k] == 0)) {
                        // vector<int> temp;
                        // temp.push_back(nums[i]);
                        // temp.push_back(nums[j]);
                        // temp.push_back(nums[k]);
                         vector<int> temp={nums[i] , nums[j] , nums[k]};

                        sort(temp.begin(), temp.end());
                        if (find(result.begin(), result.end(), temp) ==
                            result.end()) {
                            result.push_back(temp);
                        }
                    }
                }
            }
        }
        return result;
    }
};

//here i am going to use an extra approach using 2 sum with 2 pointers
//where we will find n1 + n2 = -n3 
//and to avaoid duplicates we will sort the array first
//and then use two pointers to find the pairs
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;

                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return result;
    }
};