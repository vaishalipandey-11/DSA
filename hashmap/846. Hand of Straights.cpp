#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(); // edge case
        if( n % groupSize != 0) return false ;

        //count freq of each element
        map<int , int >mp;
        for(auto &x : hand){
            mp[x]++;
        }

        while(!mp.empty()){
            int curr  = mp.begin()->first; // first ele of map
            for(int i=0 ; i<groupSize ;i++){
                if(mp[curr+i]==0) return false;
                mp[curr +i ]--;
                if(mp[curr+i]<1) mp.erase(curr+i);
            }
        }
        return true ;
    }
};