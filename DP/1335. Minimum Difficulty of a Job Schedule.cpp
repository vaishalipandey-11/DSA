#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#include <limits.h>
class Solution {
public:
    int n;
    int solve(int idx, vector<int>& job, int d) {

        if (d == 1) {
            int maxj = INT_MIN;
            for (int i = idx; i < n; i++) {
                maxj = max(maxj, job[i]);
            }
            return maxj;
        }
        int maxx = INT_MIN;
        int result = INT_MAX;

        for(int i = idx ; i<=n-d ; i++){// jo index pass kiya h wahi se start krna h 
            maxx= max(maxx,job[i]);
            result = min(result , maxx+ solve(i+1 , job, d-1));
        }
        return result ;

    }

    int minDifficulty(vector<int>& job, int d) {
        n = job.size();
        if (d > n)
            return -1;
        return solve(0,job, d);
    }
};


class Solution {
public:
    int n;
    int dp[1001][11];
    int solve(int idx, vector<int>& job, int d) {

        if (d == 1) {
            int maxj = INT_MIN;
            for (int i = idx; i < n; i++) {
                maxj = max(maxj, job[i]);
            }
            return maxj;
        }
        if(dp[idx][d] != -1 ) return dp[idx][d];
        int maxx = INT_MIN;
        int result = INT_MAX;

        for(int i = idx ; i<=n-d ; i++){// jo index pass kiya h wahi se start krna h 
            maxx= max(maxx,job[i]);
            result = min(result , maxx+ solve(i+1 , job, d-1));
            dp[idx][d] = result ;
        }
        return result ;

    }

    int minDifficulty(vector<int>& job, int d) {
        n = job.size();
        if (d > n)
            return -1;
        memset(dp , -1 , sizeof(dp));    
        return solve(0,job, d);
    }
};