#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
const int MOD = 1e9 + 7;
    int ans =0 ;
    int rev(int num){
        int reverse =0;
        while(num>0){
         int digit = num%10;
         reverse = reverse*10+digit;
         num /= 10;
        }
        return reverse;
        
    }
    int countNicePairs(vector<int>& nums) {
        int result ;
        int n = nums.size();
        for(int i =0 ; i<n ;i++){
            //always change the equation to avoid overflow
            //nums[i] - rev(nums[i]) can be negative so we need to take care
            //of that by using long long or by taking modulo
            //here we are calculating the difference between the number and its reverse
            //and storing it in the nums array
            //this will help us to count the nice pairs later
            //we can also use a map to store the frequency of each difference
            //but here we are directly modifying the nums array to store the difference
           result =nums[i]-rev(nums[i]);
           nums[i]= result;
        }

        unordered_map<int , long long>mp;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++;
        }


        for(auto &it : mp){
            ans = (ans%MOD) +((it.second*(it.second-1)/2)%MOD);
            // we are using the formula nC2 = n*(n-1)/2 to count the number of pairs
        }
        return ans%MOD ;
    }
};
// tc is O(n) for iterating through the nums array and O(n) for iterating through the map, so overall O(n)
// sc is O(n) for the map
// the code is counting the number of nice pairs in the array by first calculating the difference between each number and its reverse, then counting the frequency of each difference using a map, and finally calculating