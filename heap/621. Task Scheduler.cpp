
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    typedef pair<int, char> p;
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        unordered_map<char, int> mp;

        // char , freq
        for (auto it : tasks) {
            mp[it]++;
        }

        // max_heap fill
        priority_queue<p> mh;

        for (auto it : mp) {
            mh.push({it.second, it.first});
        }

        int time = 0;
        while (!mh.empty()) {
            vector<pair<int, char>> temp;
            int cycle = n + 1;

            while (cycle > 0 && !mh.empty()) {
                auto [freq, ch] = mh.top();
                mh.pop();
                time++;

                if(freq > 1 ) temp.push_back({freq-1, ch});
                cycle--;
            }

            for(auto &it: temp ){
                mh.push(it);
            }

            if(!mh.empty() && cycle !=0 ) time += cycle ;
        }
        return time ;
    }
};