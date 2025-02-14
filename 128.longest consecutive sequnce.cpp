class Solution {
public:
    // helper linear search function 
    bool linearsearch(vector<int>&nums, int x){
        int n = nums.size();
        if(n==0 ) return 0;
        for(int i =0 ; i<n ; i++){
            if(nums[i]==x) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
         int largest =0;
        // here we will take 2 var lag and count too track
        for(int i =0 ; i<n ; i++){
            //we need to while cons so
            int x = nums[i];
            int count =1;
           
            while(linearsearch(nums,x+1)==true){
                 x++;
                 count++;
               }
            largest = max(largest,count);
        }
        return largest;
    }
};