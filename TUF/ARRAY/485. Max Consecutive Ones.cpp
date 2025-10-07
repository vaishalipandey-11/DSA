class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        int maxx = INT_MIN;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
          if(nums[i]==1){
            count ++;
          }else{
           
            count =0;
          }
           maxx = max(count , maxx);
          
        }
        return maxx ;
        
    }
};