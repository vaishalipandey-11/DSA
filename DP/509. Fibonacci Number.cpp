#include <vector>
using namespace std;
// TLE solution
// Time complexity: O(2^n)
// Space complexity: O(n) for recursion stack
class Solution {
public:
    int fib(int n) { //tle solution 
        if(n==0) return 0;
        if(n==1) return 1;

        return fib(n-2) +fib(n-1);
    }
};

// Memoization solution
// Time complexity: O(n)
// Space complexity: O(n) for dp array and O(n) for recursion stack
// This solution avoids TLE by storing results of subproblems
// and reusing them, thus reducing the number of recursive calls.
// This is a top-down dynamic programming approach.
// The dp array is used to store the Fibonacci numbers for each index.
// The solve function is a helper function that performs the recursive calculation.
// The base cases are defined for n = 0 and n = 1.
class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
    int fib(int n) {
        // lets do memoization for repeating sub problems
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

// Tabulation solution
// Time complexity: O(n)
// Space complexity: O(n) for dp array
// This solution uses a bottom-up dynamic programming approach.
// It builds the solution iteratively from the base cases up to n.
// The dp array is used to store the Fibonacci numbers for each index.
// The base cases are defined for n = 0 and n = 1.
// The loop iterates from 2 to n, filling the dp array with Fibonacci numbers.
class Solution {
public:
    int fib(int n) {
        if(n==0 ) return 0;
        if(n==1) return 1;
        vector<int>dp(n+1 , -1);
        dp[0]=0;
        dp[1]=1;
        for(int i =2 ; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};