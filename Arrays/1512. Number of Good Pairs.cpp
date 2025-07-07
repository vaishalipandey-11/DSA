#include <vector>
using namespace std;
// This is a brute force solution to count the number of good pairs in an array.
// A good pair is defined as a pair of indices (i, j) such that nums[i] == nums[j] and i < j.
// Time complexity: O(n^2) where n is the size of the input array.

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count =0;
        for(int i =0 ; i<nums.size()-1; i++){
            for(int j=i+1 ; j<nums.size() ;j++ ){
                if(nums[i]==nums[j]) count++;
            }
        }
        return count;
    }
}; 