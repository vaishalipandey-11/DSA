#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        vector<int>lastseen(26,-1);
        int count =0;
        int charstart =0;

        for(int i=0; i<n ; i++){
            int ch = s[i];

            if(lastseen[ch-'a'] >= charstart){
                count ++;
                charstart =i;

            }
            lastseen[ch-'a'] =i;

        }
        return count+1;
        
    }
};