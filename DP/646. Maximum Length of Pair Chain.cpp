// this is a varied version of the Longest Increasing Subsequence problem , we are using same code 
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    int n;
    int dp[1001][1001];
    int ans =0;
    int solve(vector<vector<int>>& pairs, int curr_idx, int prev_idx) {
        if (curr_idx == n)
            return 0;
            

        if(prev_idx != -1 && dp[curr_idx][prev_idx] != -1)   return dp[curr_idx][prev_idx];

        int take =0;

        if(prev_idx ==-1 || pairs[prev_idx][1] <pairs[curr_idx][0]) {
            take = 1+ solve(pairs , curr_idx+1 , curr_idx);
        }
        int skip = solve(pairs , curr_idx+1 , prev_idx);

        if(prev_idx != -1){
           dp[curr_idx][prev_idx] = max(skip , take);

        } 
        return max(skip , take);

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(pairs.begin(), pairs.end());
        memset(dp, -1, sizeof(dp));
        return solve(pairs, 0, -1);
    }
};

// this is a dp solution with O(n^2) time complexity and O(n) space complexity
// we are using a 2D dp array to store the results of subproblems
// we sort the pairs based on the first element of each pair
// and then we iterate through the pairs to find the maximum length of the chain
// we use a nested loop to check if the current pair can be added to the chain

class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int>dp(n+1 , 1);
        int maxlen = 1 ;
        for(int i=0 ; i< n ; i++){
            for(int j = 0 ;j<i ; j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i] = max(dp[i], dp[j]+1);
                    maxlen = max(maxlen , dp[i]);
                }
            }
        }
        return maxlen;
    }
};