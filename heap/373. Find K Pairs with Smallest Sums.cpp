class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p , vector<p>, greater<p>> pq;
        int n = nums1.size();
        int m = nums2.size();
        for(int i =0 ;i<n ; i++){
            for(int j =0 ; j<m ; j++){
                pq.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
            }
        }
 
         vector<vector<int>>ans;
        while(k--){
           auto [i,j] = pq.top();
           ans.push_back({j.first , j.second});
           pq.pop();
        }
        return ans;
    }
};

class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        priority_queue<p> pq;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = nums1[i] + nums2[j];
                if (pq.size() < k) {
                    pq.push({sum, {nums1[i], nums2[j]}});

                }else if (pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else break;
            }
        }

        vector<vector<int>> ans;
        while (k--) {
            auto [i, j] = pq.top();
            ans.push_back({j.first, j.second});
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};