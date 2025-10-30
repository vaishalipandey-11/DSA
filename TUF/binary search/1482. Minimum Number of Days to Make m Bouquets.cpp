#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bouquetCount(vector<int>& bloomDay, int k, int mid) {

        int n = bloomDay.size();
        int b = 0 ;
        int con_count = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                con_count++;
            } else {
                con_count = 0;
            }
            if (con_count == k) {
                b++;
                con_count =0;
            }
        }
        return b;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
       long long totalflower = 1LL*m*k;
       if(totalflower > n) return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (bouquetCount(bloomDay, k, mid) >= m) {
                
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};