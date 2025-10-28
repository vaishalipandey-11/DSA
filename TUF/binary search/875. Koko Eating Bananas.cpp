#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool caneat(vector<int>& piles, int mid, int h) { 
        int curr = 0;
        for(auto &it : piles){
            curr += it /mid;
            if(it%mid != 0){
                curr++;
            }
        }

        return curr <= h;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (caneat(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};