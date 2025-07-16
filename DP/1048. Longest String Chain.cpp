#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//this is a rec code without memoization
//tc: O(2^n) , sc: O(n)
class Solution {
public:
    int k;
    bool predecessor(string& prev, string& curr) {
        int n = prev.length();
        int m = curr.length();
        if (n >= m || m - n != 1)
            return false;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
    int lis(vector<string>& words, int prev_idx, int curr_idx) {
        k = words.size();
        if (curr_idx == k)
            return 0;
        int taken = 0;
        int nottaken = 0;

        if (prev_idx == -1 || predecessor(words[prev_idx], words[curr_idx])) {
            taken = 1 + lis(words, curr_idx, curr_idx + 1);
        }
        nottaken = lis(words, prev_idx, curr_idx + 1);

        return max(taken, nottaken);
    }
    static bool myfunction(string& a, string& b) {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), myfunction);
        return lis(words, -1, 0);
    }
};

//this is a dp solution with memoization
//tc: O(n^2) , sc: O(n^2)
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int dp[1001][1001];
    int k;
    bool predecessor(string& prev, string& curr) {
        int n = prev.length();
        int m = curr.length();
        if (n >= m || m - n != 1)
            return false;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
    int lis(vector<string>& words, int prev_idx, int curr_idx) {
        k = words.size();
        if (curr_idx == k)
            return 0;

        if (prev_idx != -1 && dp[prev_idx][curr_idx] != -1)
            return dp[prev_idx][curr_idx];

        int taken = 0;
        int nottaken = 0;

        if (prev_idx == -1 || predecessor(words[prev_idx], words[curr_idx])) {
            taken = 1 + lis(words, curr_idx, curr_idx + 1);
        }
        nottaken = lis(words, prev_idx, curr_idx + 1);

        if (prev_idx != -1)
            dp[prev_idx][curr_idx] = max(taken, nottaken);

        return max(taken, nottaken);
    }
    static bool myfunction(string& a, string& b) {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), myfunction);
        memset(dp, -1, sizeof(dp));
        return lis(words, -1, 0);
    }
};