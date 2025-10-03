#include <bits/stdc++.h>
using namespace std;
class NumberContainers {
public:
    typedef priority_queue<int, vector<int>, greater<int>> pq;

    unordered_map<int, int> idx_no;
    unordered_map<int, pq> no_idxs;
    NumberContainers() {}

    void change(int index, int number) {
        
        no_idxs[number].push(index); // idxs for smallest

        idx_no[index] = number;
    }

    int find(int number) {
        if (no_idxs.find(number) == no_idxs.end())
            return -1;
        auto &ppq = no_idxs[number];
        while (!ppq.empty()) {
            int topp = ppq.top();
            if (number == idx_no[topp]) {
                return topp;
            } else {
                ppq.pop();
            }
        }
        return -1;
    }
};
