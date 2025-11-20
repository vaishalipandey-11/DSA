#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n; i++) {

            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                int MINI = INT_MAX;
                int MAXI = INT_MIN;

                freq[s[j]]++;

                for (auto& it : freq) {
                    MINI = min(MINI, it.second);
                    MAXI = max(MAXI, it.second);
                }

                sum += MAXI - MINI;
            }
        }
        return sum;
    }
};