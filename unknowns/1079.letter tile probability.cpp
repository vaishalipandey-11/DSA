#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//Approach-1 (Using simple backtracking )
//T.C : O(n!)
//S.C : O(n * n!), total possible sequences = n! and each having n length

class Solution {
public:
     void solve(string tiles, vector<bool>&used,unordered_set<string>&result, string curr){
          int n = tiles.length();
          // 1 case m solve karungi 
        result.insert(curr); // add sol to result 
        for(int i =0 ; i<n ;i++){ // iterate over each value
            if(used[i]) continue;  //check in flag for reuse
            curr.push_back(tiles[i]); //start adding 
            used[i]= true;
            // baki reccur samhal lega 
            solve(tiles , used , result , curr);
            // backtrack 
            used[i]= false;
            curr.pop_back();
        }
     }
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        vector<bool>used(n,false);//flag
        unordered_set<string>result ;//  sol
         string curr = "";   // answer building str
        solve(tiles,used,result,curr); // ftn call
   
        return result.size()-1; // return ans remove empty string first

    }
};
//Approach-2 (Using count of characters + backtracking)
//T.C : O(n!)
//S.C : O(n), total possible sequences = n! and each having n length
class Solution {
public:
       int ans =0;
        void  solve(vector<int>&count){
         ans ++;// empty string 
        for(int i =0 ; i<26 ; i++){
            if(count[i]==0) continue;
            count[i]--;
           
            solve(count);
            //backtrack
            count[i]++;


        }

    }
    int numTilePossibilities(string tiles) {
       
        vector<int>count(26 , 0); // storing the count of the letters 
        for(auto ch:tiles){
            count[ch-'A']++;
        }
        solve(count);
        return ans-1;// to remove the empty str 
    }
};