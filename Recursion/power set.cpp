#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//Approach-1 (Without For Loop)
//T.C : O(n * 2^n) - For ever index, we have two possibilities so 2^n and for copying each string to result, it takes O(n)
//S.C : O(n) - Recursion tree depth will be at max  = n  (NOTE : I have ignored space taken for storing result)
class Solution{
	public:
	    void solve(string &curr , int  idx , string &s , vector<string> &result ){
	        // bc 
	        if(idx == s.length()){
	            if(curr != ""){
	                result.push_back(curr);
	               
	            }
	             return ;
	        }
	        
	        curr.push_back(s[idx]); // DO
	        solve(curr , idx+1 , s, result ); // explore 
	        curr.pop_back(); // undo becktrack
	        solve(curr , idx+1 , s, result ); // explore 
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string>result;
		    string curr = "";
		   
		    solve(curr , 0 , s , result);
		    sort(result.begin(), result.end());
		    
		    return result;
		    
		}
};
//Approach-2 (Using for loop)
//T.C : O(n * 2^n)
//S.C : O(n)
class Solution {
public:
    vector<string> result;

    // Recursive function to generate all possible strings
    void solve(string &curr, string &s, int idx) {
        // If the current string is not empty, add it to the result
        if (curr != "") {
            result.push_back(curr);
        }

        // Iterate through the remaining characters in the string
        for (int i = idx; i < s.length(); i++) {
            // Include the character at the current index and proceed
            curr.push_back(s[i]);
            solve(curr, s, i + 1);
            curr.pop_back();  // Backtrack by removing the last character
        }
    }

    // Main function to generate all possible strings
    vector<string> AllPossibleStrings(string s) {
        string curr = "";
        solve(curr, s, 0);  // Start the recursive function
        sort(begin(result), end(result));  // Sort the result lexicographically
        return result;
    }
};