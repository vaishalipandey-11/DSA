#include<iostream>

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int nextofend(vector<vector<int>>& arr, int s, int currendpoint) {
        int e = n - 1;
        int result = n + 1; // kuch bhi le skte ho
        while (s <= e) {
            int mid = s + (e-s) / 2;
            if (arr[mid][0] >= currendpoint) {
                result = mid;
                e = mid - 1;

            } else {
                s = mid + 1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& arr, int i) {
        if (i >= n)
            return 0;
        int maxprofite = INT_MIN;
        int next = nextofend(arr, i + 1, arr[i][1]);

        int taken = arr[i][2] + solve(arr, next);
        int nottaken = solve(arr, i + 1);

        return max(taken, nottaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        n = startTime.size();

        vector<vector<int>> arr(n, vector<int>(3,0));

        for (int i = 0; i < n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        sort(arr.begin(), arr.end());
        return solve(arr, 0);
    }
};

class Solution {
public:
    int n;
    int dp[50001];
    int nextofend(vector<vector<int>>& arr, int s, int currendpoint) {
        int e = n - 1;
        int result = n + 1; // kuch bhi le skte ho
        while (s <= e) {
            int mid = s + (e-s) / 2;
            if (arr[mid][0] >= currendpoint) {
                result = mid;
                e = mid - 1;

            } else {
                s = mid + 1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& arr, int i) {
        if (i >= n)
            return 0;
        int maxprofite = INT_MIN;
        if(dp[i] != -1 ) return dp[i];
        int next = nextofend(arr, i + 1, arr[i][1]);

        int taken = arr[i][2] + solve(arr, next);
        int nottaken = solve(arr, i + 1);

        return dp[i]= max(taken, nottaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        n = startTime.size();
        memset(dp, -1 , sizeof(dp));

        vector<vector<int>> arr(n, vector<int>(3,0));

        for (int i = 0; i < n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        sort(arr.begin(), arr.end());
        return solve(arr, 0);
    }
};