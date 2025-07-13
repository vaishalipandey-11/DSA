 #include <vector>
using namespace std;

class Solution {
public: 
    int solve(int n , vector<int>&dp ){
        if(n==0 || n==1 || n==2 ) return n;
        if(dp[n] != -1) return dp[n];

        int one_step = solve(n-1 ,dp);
        int two_step = solve(n-2 ,dp);
         
         return dp[n] = one_step + two_step;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1 ,-1);
         return solve(n ,dp);

        
    }
};

class Solution {
public:
    // bottom up approach now 

    int climbStairs(int n) {
        if(n==0 || n==1) return n ;
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3 ; i<=n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


class Solution {
public:
 // its time for space optimization now by taking only 2 variables  okay
    int climbStairs(int n) {
        if( n==1  || n==2 || n==3) return n;
        int  a= 1;
        int b = 2;
        int c = 3;
        int temp_b;
         for(int i =3 ; i<=n ; i++){
            c = a+b;

            temp_b = b;
            b = c;
            a= temp_b;

         }
         return c;
        
    }
};