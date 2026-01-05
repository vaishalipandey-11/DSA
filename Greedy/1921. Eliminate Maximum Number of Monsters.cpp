#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int>vec(n);
        for(int i=0; i<n ;i++){
            vec[i]=ceil(float(dist[i])/speed[i]);
        }

        sort(vec.begin(), vec.end());

        int count =1;
        int timepassed =1;
        for(int i=1 ; i<n ; i++){
            if(vec[i]-timepassed <=0){
                return count;
            }
            count++;
            timepassed++;
        }
        return count;
    }
};