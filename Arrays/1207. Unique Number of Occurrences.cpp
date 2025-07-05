#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int,int>mp;
      // all ele freq in map
        for(int i =0 ; i<arr.size() ; i++){
            mp[arr[i]]++;
        }
        
        unordered_set<int>st;
        // all freq in set 
        for(auto it: mp){
            st.insert(it.second);
        }
     
        // if they are equal so no duplicate freq 
        return st.size() == mp.size();
    }
};


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>vec(2001 , 0);
        
        // fill new vec with same value and diff index +1000
        for(auto x : arr){
            vec[x+1000 ] ++;
        }

        // sort the vector bases of value  
        sort(vec.begin() , vec.end());
        
        //now check if consecutive values are equal or not 
        for(int i =1 ; i<2001 ; i++){
            if(vec[i]!=0  && vec[i]==vec[i-1]) return false ;

        }
        return true ;


    }
};