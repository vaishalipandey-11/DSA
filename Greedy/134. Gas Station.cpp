#include <vector>
using namespace std;    
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = cost.size();

        for(int i=0; i<n ; i++){
            if(gas[i]<cost[i]) continue;

            int currgas = gas[i];

            int j = (i+1)%n;
            currgas = currgas - cost[i]+gas[j];

            while( j!= i){
                if(currgas < cost[j]) break;

                int costofmove = cost[j];
                j= (j+1)%n;
                int costofnext = gas[j];

                currgas = currgas - costofmove + costofnext;
            }
            if(j==i) return i;

        }
        return -1; 
    }
};

// better approach
#include <numeric>
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = cost.size();

        int sumgas = accumulate(begin(gas), end(gas),0);
        int sumcost = accumulate(begin(cost),end(cost),0);
        if(sumgas < sumcost) return -1;

        int result =0;
        int total =0;
        for(int i=0; i<n ; i++){
            total += gas[i]-cost[i];
            if(total <0){
                total =0;
                result =i+1;
            }
        }
        return result;
        
    }
};