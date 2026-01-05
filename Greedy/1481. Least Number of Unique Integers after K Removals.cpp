#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;

        for (auto it : arr) {
            mp[it]++;
        }
        vector<int>freq;
        for(auto it : mp){
            freq.push_back(it.second);
        }

        sort(freq.begin(), freq.end());

        for(int i=0; i<n ; i++){
            k-=freq[i];
            if(k<0){
               return freq.size()-i;
            }

        }
        return 0;

    }
};