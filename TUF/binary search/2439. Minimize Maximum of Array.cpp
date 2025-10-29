#include <vector>
#include <cmath>
using namespace std;    
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long prefix = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int avg = ceil((double)prefix / (i + 1)); // ceil(prefix / (i+1))
            res = max(res, avg);
        }

        return res;
    }
};
