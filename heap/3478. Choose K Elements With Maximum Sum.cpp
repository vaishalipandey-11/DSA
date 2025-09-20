class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long >v(n , 0);
        for(int i=0 ; i<n ; i++){
             priority_queue<long long >pq;
            for(int j=0 ; j<n ; j++){

                if(i==j) continue;
                else {
                    if(nums1[i]> nums1[j]){
                        pq.push(nums2[j]);
                    }                    
                }
            }
            int K=k;
            int sum =0;
            while(K!=0 && !pq.empty()){
                sum += pq.top();
                pq.pop();
                K--;
            }

            v[i]=sum;
        }
        return v;
    }
};