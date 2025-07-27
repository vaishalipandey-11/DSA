#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#include <limits.h>
class Solution {
public:
int n ;
    bool hascommon(string &str1 , string &str2){
        int arr[26]= {0};
        for(char &ch : str1) {
            if(arr[ch-'a']>0) return true;
            arr[ch-'a']++;
        }
        for(char &ch : str2){
            if(arr[ch-'a']>0) return true;
        }
        return false ;
    }
    int solve(int idx , vector<string>&arr , string temp ){
        if(idx==n) return temp.size();

        int include = INT_MIN ;
        int exclude = INT_MIN;

        if(hascommon(arr[idx], temp)){
           exclude = solve(idx+1 , arr, temp); 
        }else{
            exclude = solve(idx+1 , arr , temp);
            temp += arr[idx];
            include = solve(idx+1 , arr , temp);
        }
        return max(include , exclude);

    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        n = arr.size();
       return solve(0,arr,"");
    }
};