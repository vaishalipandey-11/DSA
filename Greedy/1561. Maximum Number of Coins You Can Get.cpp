#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();

        sort(piles.begin(), piles.end());

        int b = 0;
        int m = n - 2;
        int a = n - 1;
        int result = 0;

        while (b < m) {
            result+=piles[m];
            b++;
            m-=2;
        }
        return result ;
    }
};


class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int result = 0;

        sort(piles.begin(), piles.end());

        for (int i = n/3; i < n; i += 2) {
            result += piles[i];
        }
        return result;
    }
};