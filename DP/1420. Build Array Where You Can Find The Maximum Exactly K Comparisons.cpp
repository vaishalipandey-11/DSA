#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//only recursive solution
//tc: O(2^n) , sc: O(n)
class Solution {
public:
    int MOD = 1e9 + 7;
    int N, M, K;
    int solve(int idx, int searchcost, int maxsofar) {

        if (idx== N) {
            if (searchcost == K)
                return 1;
            return 0;
        }
        int result = 0;

        for (int i = 1; i <= M; i++) {
            if (i > maxsofar) {
                result = (result + solve(idx + 1, searchcost + 1, i)) % MOD;
            } else {
                result = (result + solve(idx + 1, searchcost, maxsofar)) % MOD;
            }
        }
        return result%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        return solve(0,0,-1);
    }
};

//tc: O(n * m * k) , sc: O(n * m * k)
#include <cstring>
#include <vector>
class Solution {
public:
    int dp[51][51][101];
    int MOD = 1e9 + 7;
    int N, M, K;
    int solve(int idx, int searchcost, int maxsofar) {

        if (idx == N) {
            if (searchcost == K)
                return 1;
            return 0;
        }
        if (dp[idx][searchcost][maxsofar] != -1)
            return dp[idx][searchcost][maxsofar];
        int result = 0;

        for (int i = 1; i <= M; i++) {
            if (i > maxsofar) {
                result = (result + solve(idx + 1, searchcost + 1, i)) % MOD;
            } else {
                result = (result + solve(idx + 1, searchcost, maxsofar)) % MOD;
            }
        }
        return dp[idx][searchcost][maxsofar] = result % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};