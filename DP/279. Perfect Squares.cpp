#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arr[10000];
    int solve(int n) {
        if (n == 0)
            return 0;

        int mincount = INT_MAX;

        if (arr[n] != -1)
            return arr[n];

        for (int i = 1; i * i <= n; i++) {
            int result = 1 + solve(n - (i * i));
            mincount = min(mincount, result);
        }

        return arr[n] = mincount;
    }
    int numSquares(int n) {
        memset(arr, -1, sizeof(arr));
        return solve(n);
    }
};


class Solution {
public:
    vector<int>dp;
    int solve(int n) {
        if (n == 0)
            return 0;

        int mincount = INT_MAX;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++) {

            mincount = min(mincount, 1 + solve(n - (i * i)));
        }

        return dp[n] = mincount;
    }
    int numSquares(int n) {
        dp = vector<int>(n+1 , -1);
       // memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};