#include <vector>
using namespace std;
class Solution {
  public:
    bool canPair(vector<int> &arr, int k) {
       int n = arr.size();
       
       if(n%2 !=0 ) return false;
       
       vector<bool>used(n,false);
       
       for(int i=0 ; i<n ;i++){
           if(used[i]) continue;
           
           bool foundpair = false;
           
           for(int j =i+1 ; j<n ; j++){
               
               if(!used[j] && (arr[i]+arr[j])%k ==0 ) {
                   
                   foundpair = true;
                   used[i]=used[j]=true;
                   break;
               }
           }
           if(!foundpair) return false;
       }
       
       return true;
    }
};


#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        int n = arr.size();
        if (n % 2 != 0) return false; // can't pair an odd-sized array

        unordered_multiset<int> remainder;

        for (int i = 0; i < n; i++) { // find remainder and complement
            int rem = ((arr[i] % k) + k) % k;
            int complement = (k - rem) % k;

            if (remainder.count(complement) > 0) {  // if complement exists
                remainder.erase(remainder.find(complement));
            } else {
                remainder.insert(rem);  // insert rem, not complement
            }
        }
        return remainder.empty(); 
    }
};