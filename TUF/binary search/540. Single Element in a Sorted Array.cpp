 #include <vector>
using namespace std;
// using xor operator
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans =0;
        for(int i =0; i<nums.size() ; i++){
           ans ^= nums[i];

        }
        return ans;
    }
};

// using binary search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int h = n - 2;

        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // we are in the left side 
            bool ispairalligned =( (mid %2 ==0 && nums[mid]== nums[mid+1]) || 
            (mid %2 ==1 && nums[mid]== nums[mid-1]));

            if (ispairalligned) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return -1;
    }
};