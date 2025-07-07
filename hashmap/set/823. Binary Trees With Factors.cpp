#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        unordered_map<int, long long> mp;
        
        // Initialize each number with 1 possible tree (the node itself)
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = 1;
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < x; y++) {
                if (arr[x] % arr[y] == 0) {
                    int right = arr[x] / arr[y];
                    if (mp.find(right) != mp.end()) {
                        mp[arr[x]] = (mp[arr[x]] + (mp[arr[y]] * mp[right]) % MOD) % MOD;
                    }
                }
            }
        }

        int result = 0;
        for (auto& it : mp) {
            result = (result + it.second) % MOD;
        }
        return result;
    }
};

//o(n2)