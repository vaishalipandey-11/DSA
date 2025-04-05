
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
  
            int maximumCandies(vector<int>& candies, long long k) {
           int n = candies.size();

           // find tha max candies qki usse jada ni de skte 8
           int maxc = *max_element(candies.begin() , candies.end());

           /// start look from maxelement ki ky etna de skte h sbko y nhi
           for(int c =maxc ; c>= 1 ; c--){
              int count =0;
              // hr candie pe jao or check kro ki d skte h y nhi agr ha toh  count ko ++ y k ko -- kr do
             for(int i =0 ;i<n ; i++){
                count+=candies[i]/c;

                    }
                // ki agr count jada h mtlv sbko mil paa rahi h max qki maxele se  check kr rahe h if(count >= k){
                    // agr ha toh return that max please
                        return c;
                    }
            
                    return 0;
            }
        };
       

    // here we can use binary search in place of linear search okay
class Solution {
public:
    int n;
    typedef long long ll;
    bool ispossible(vector<int>& candies, long long k, int mid) {
        ll count = 0;
        for (int i = 0; i < n; i++) {
            count += candies[i] / mid;
        }
        return count >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {

        n = candies.size();
        ll total = 0;
        int maxc = 0;
        for (int i = 0; i < n; i++) {
            total += candies[i];
            maxc = max(maxc, candies[i]);
        }
        if (total < k)
            return 0;

        int l = 1;
        int r = maxc;
        int result = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (ispossible(candies, k, mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};