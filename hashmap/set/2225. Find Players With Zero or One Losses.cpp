#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       unordered_map<int,int>lostmap;
       //map fill 
       for(int i =0 ; i<matches.size() ; i++){
         int lost = matches[i][1];
         lostmap[lost]++;
       } 

       vector<int>nolost , oncelost;
       //now check in map for win and lost cases
       for(int i =0 ; i<matches.size() ; i++){
            int win  = matches[i][0];
            int loose = matches[i][1];

            if(lostmap.find(win) == lostmap.end()){
                nolost.push_back(win);
                lostmap[win]=2; // dekho next time k liye count ko 2 kr do map pe ja  kr okay 
            }
            if(lostmap[loose]==1){
                oncelost.push_back(loose);
            }
       }
       // sort both of them as per the question 
        sort(nolost.begin(), nolost.end());  
        sort(oncelost.begin(), oncelost.end());

        return {nolost, oncelost};
    }
};