#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double area(int x1, int y1, int x2, int y2, int x3, int y3) {
        return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = i + 2; k < n; k++) {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    ans = max(ans, area(x1, y1, x2, y2, x3, y3));
                }
            }
        }
        return ans;
    }
};