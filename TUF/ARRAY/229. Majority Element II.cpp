class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if(find(ans.begin(), ans.end(), nums[i]) != ans.end())
                continue;

            int count = 0;
            for (int j = 0; j < n; j++) 
                if (nums[i] == nums[j]) 
                    count++;
                

                if (count > n / 3) 
                    ans.push_back(nums[i]);
                
                if (ans.size() == 2)
                    break;
            
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        vector<int>ans;
        for(int i=0; i<n ; i++){
            mp[nums[i]]++;

            if(mp[nums[i]]== (n/3 +1)) ans.push_back(nums[i]);

            if(ans.size()==2) break;

        }
        return ans;
    }
};