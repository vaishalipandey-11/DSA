#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> prefix(n+1, 0);
        vector<int> suffix(n+1, 0);

      
        for (int i = 1; i <= n; i++) {
           prefix[i]= prefix[i-1] + (customers[i-1]=='N');
        }

        for(int j =n-1 ; j>=0 ; j--){
            suffix[j]= suffix[j+1]+(customers[j]=='Y');
        }

        int ans =INT_MAX;
        int sol =0;
       
        for(int i=0; i<=n ; i++){
             int p=prefix[i]+suffix[i] ;
            if(p<ans){
                ans = p;
                sol = i;
            }
        }
        return sol;

    }
};