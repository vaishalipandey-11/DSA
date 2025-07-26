#include <vector>
#include <utility>
#include <algorithm>
#include <limits.h>
using namespace std;
class Solution {
public:
     int m , n ;
     typedef long long ll ;
     int MOD = 1e9+7;
 
     pair<ll, ll> solve(int i , int j ,vector<vector<int>>&grid ){
        ll minval = LLONG_MAX;
        ll maxval = LLONG_MIN;// type compatible issue!

         if(i == m-1 && j==n-1 ) return {grid[i][j],grid[i][j]};

         if(i+1<m){ // for down min max val 
            auto [mindown , maxdown ] = solve(i+1 , j , grid);
            minval = min({minval , mindown*grid[i][j] , maxdown*grid[i][j]});// curr min
            maxval = max({maxval, mindown*grid[i][j], maxdown*grid[i][j]});//curr max in cell
         }

         if(j+1 <n){// for right movement 
            auto [minright , maxright] = solve(i, j+1, grid);
            minval = min({minval,  minright*grid[i][j], maxright*grid[i][j]});
            maxval = max({maxval, minright*grid[i][j], maxright*grid[i][j]});
         }
         return {minval , maxval};

     }
     
    int maxProductPath(vector<vector<int>>& grid) {
        m= grid.size(); 
        n = grid[0].size();
        auto [minprod , maxprod] = solve(0,0,grid);
        return maxprod<0 ? -1 : maxprod % MOD;

    }
};


class Solution {
public:
     int m , n ;
     typedef long long ll ;
     int MOD = 1e9+7;
     vector<vector<pair<ll,ll>>> dp;

 
     pair<ll, ll> solve(int i , int j ,vector<vector<int>>&grid ){
        ll minval = LLONG_MAX;
        ll maxval = LLONG_MIN;// type compatible issue!

         if(i == m-1 && j==n-1 ) return {grid[i][j],grid[i][j]};
         if(dp[i][j] != make_pair(LLONG_MAX, LLONG_MIN)) return dp[i][j];

         if(i+1<m){ // for down min max val 
            auto [mindown , maxdown ] = solve(i+1 , j , grid);
            minval = min({minval , mindown*grid[i][j] , maxdown*grid[i][j]});// curr min
            maxval = max({maxval, mindown*grid[i][j], maxdown*grid[i][j]});//curr max in cell
         }

         if(j+1 <n){// for right movement 
            auto [minright , maxright] = solve(i, j+1, grid);
            minval = min({minval,  minright*grid[i][j], maxright*grid[i][j]});
            maxval = max({maxval, minright*grid[i][j], maxright*grid[i][j]});
         }
         return dp[i][j]= {minval , maxval};

     }
     
    int maxProductPath(vector<vector<int>>& grid) {
        m= grid.size(); 
        n = grid[0].size();
        dp = vector<vector<pair<ll, ll>>>(m,vector<pair<ll,ll>>(n, {LLONG_MAX, LLONG_MIN}));
        auto [minprod , maxprod] = solve(0,0,grid);
        return maxprod<0 ? -1 : maxprod % MOD;

    }
};


class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<ll, ll>>> dp(m, vector<pair<ll, ll>>(n));
        dp[0][0] = {grid[0][0], grid[0][0]};

        // loop to fill right
        for (int j = 1; j < n; j++) {
            dp[0][j].first = dp[0][j - 1].first * grid[0][j];
            dp[0][j].second = dp[0][j - 1].second * grid[0][j];
        }
        //loop for left 
        for (int i = 1; i < m; i++) {
            dp[i][0].first = dp[i - 1][0].first * grid[i][0]; // makek sure to get pair value by .first and .second 
            dp[i][0].second = dp[i - 1][0].second * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                //get the values 
                ll upmax = dp[i - 1][j].first;  
                ll upmin = dp[i - 1][j].second;

                ll leftmax = dp[i][j - 1].first;
                ll leftmin = dp[i][j - 1].second;
                 
                 //uudate okay .. but be carefull 
                dp[i][j].first = max({upmax * grid[i][j], upmin*grid[i][j], leftmax*grid[i][j] , leftmin*grid[i][j]});
                dp[i][j].second = min({upmax * grid[i][j], upmin*grid[i][j], leftmax*grid[i][j] , leftmin*grid[i][j]});
            }
        }

        ll ans = dp[m-1][n-1].first; // dont forget to take the value by .first 
        return ans<0? -1 : ans%MOD ;  //use mod please 
    }
};