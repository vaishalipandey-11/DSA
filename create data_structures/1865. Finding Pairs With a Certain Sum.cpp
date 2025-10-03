#include <bits/stdc++.h>
using namespace std;
class FindSumPairs {
public:
    unordered_map<int, int> mp; // no  freq;
    vector<int> nums1;
    vector<int> nums2;

    FindSumPairs(vector<int>& n1, vector<int>& n2) {

        nums1 = n1;
        nums2 = n2;
        for (auto& it : nums2) {
            mp[it]++;
        }
    }

    void add(int index, int val) {
        mp[nums2[index]]--;
        if(mp[nums2[index]] ==0) mp.erase(nums2[index]);
        mp[nums2[index]+val]++;
        nums2[index]+= val;
    
    }

    int count(int tot) {
        int freq = 0;

        for (int i = 0; i < nums1.size(); i++) {
            if (mp.find(tot - nums1[i]) != mp.end()) {
                freq += mp[tot - nums1[i]];
            }
        }

        return freq;
    }
};
