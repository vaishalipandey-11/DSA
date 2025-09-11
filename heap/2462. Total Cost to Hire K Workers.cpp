class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> h1, h2;

        int i = 0;
        int j = n - 1;
        long long sum = 0;

        while (k--) {
            while (h1.size() < candidates && i <= j) {
                h1.push(costs[i]);
                i++;
            }
            while (h2.size() < candidates && i <= j) {
                h2.push(costs[j]);
                j--;
            }

            int h1_top = h1.size() == 0 ? INT_MAX : h1.top();
            int h2_top = h2.size() == 0 ? INT_MAX : h2.top();

            if (h1_top <= h2_top) {
                sum += h1_top;
                h1.pop();

            } else {
                sum += h2_top;
                h2.pop();
            }
        }
        return sum;
    }
};