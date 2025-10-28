#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool ispossible(vector<int>& time,long long actual, int totalTrips){
        long long curr = 0;
        for(auto &it:time){
            curr += actual/it;
        }
        return curr >= totalTrips;
        
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l =1;
        long long  r = (long long)*min_element(time.begin(), time.end())*totalTrips;

        while(l<r){
            long long mid = l+(r-l)/2;
            if(ispossible(time , mid , totalTrips)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};