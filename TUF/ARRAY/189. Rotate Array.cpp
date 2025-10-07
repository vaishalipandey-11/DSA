class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %=n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+k , nums.end());
        
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int>vec(n,-1);
        for(int i=0 ; i<n ; i++){
            vec[(i+k)%n]=nums[i];

        }
        for(int i=0 ; i<n ; i++) nums[i]=vec[i];
        
    }
};