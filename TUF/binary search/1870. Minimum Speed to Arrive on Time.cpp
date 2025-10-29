//variation of koko eating bananas
//binary search on answer
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    double ispossible(vector<int>& dist, int mid){
        double time = 0.0;
        int n = dist.size();
        for(int i =0 ;i<n-1 ; i++){
             double t = (double)dist[i]/(double)mid;
             time += ceil(t);

        }
        time += (double)dist[n-1]/(double)mid;

        return time ;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 10e7;
        int min_speed = -1;
      
        while(l<=r){
          int   mid = l+(r-l)/2;
            if(ispossible(dist , mid)<= hour){
                 min_speed = mid;
                r = mid -1;
                
            }else{
                l=mid+1;
            }
        }
        return min_speed ;

        
    }
};