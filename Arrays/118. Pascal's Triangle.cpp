#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for(int i =0 ; i<numRows ; i++){
            ans[i] = vector<int>(i+1 , 1);
            for(int j =1 ; j<i ; j++){ // start from 1 to avoid the first and last element which are always 1
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }
        return ans;
    }
};