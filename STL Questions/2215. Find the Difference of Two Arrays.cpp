#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());

        vector<int> v1, v2;

        // Correct order of arguments
        set_difference(st1.begin(), st1.end(), st2.begin(), st2.end(), back_inserter(v1));
        set_difference(st2.begin(), st2.end(), st1.begin(), st1.end(), back_inserter(v2));

        return {v1, v2};
    }
};
