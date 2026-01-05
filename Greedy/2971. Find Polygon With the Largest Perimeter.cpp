#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long perimeter =0;
        long long remside = 0;

        for(int i = 0 ; i<n ; i++){
            if(nums[i]<remside){
                perimeter = remside+nums[i];
            }
            remside+=nums[i];
            
        }
        return perimeter>0 ? perimeter : -1;
        
    }
};