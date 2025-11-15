#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string sol ;
        sort(strs.begin(), strs.end());
        for(int i=0 ; i<strs[0].size() ; i++){
        char curr_ch = strs[0][i];
        

        for(int j = 1 ; j<strs.size() ; j++){
            if(i>=strs[j].size() || strs[j][i] != curr_ch){
                return sol;
            }
        }
        
       sol.push_back(curr_ch);
        }
        return sol;
        
    }
};

