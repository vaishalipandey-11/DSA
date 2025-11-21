#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> vec(n);

        for (int i = 0; i < n; i++) {
            vec[i] = {plantTime[i], growTime[i]};
        }

        auto lambda = [](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        };

        sort(vec.begin(), vec.end(), lambda);

        int prevday = 0;
        int maxbloom = 0;

        for (int i = 0; i < n; i++) {

            int currplanttime = vec[i].first;
            int currgrowtime = vec[i].second;

            prevday += currplanttime;

            int currbloomtime = prevday + currgrowtime;

            maxbloom = max(currbloomtime, maxbloom);
        }
        return maxbloom;
    }
};