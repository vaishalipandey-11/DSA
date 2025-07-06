#include <vector>
#include <map>
using namespace std;    
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count  =0;
        int n = grid.size();
        for(int row =0 ; row<n ; row++){
            for(int col =0 ; col<n ; col ++){
                bool match = true;
                for(int i =0 ; i<n ; i++){
                    if(grid[row][i] != grid[i][col]){
                        match = false;
                        break;
                    }
                }
                if(match) count ++;

            }
        }
        return count;
    }
};


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;// map for count of each row
        int count = 0;

        for (int row = 0; row < grid.size(); row++) {
            mp[grid[row]]++; // its manual no need to traverse for row 
        }
        //but for col yes we need to store eaach col in vector and check the count of it in map
        for (int row = 0; row < grid.size(); row++) {
            vector<int> tempcol;
            for (int col = 0; col < grid.size(); col++) {
                tempcol.push_back(grid[col][row]);
            }

            count += mp[tempcol];
        }

        return count ;
    }
};