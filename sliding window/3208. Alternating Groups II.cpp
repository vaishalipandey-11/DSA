
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int N = n+(k-1);

        for(int i =0 ; i<k-1 ;i++){
            colors.push_back(colors[i]);
        }

        int i =0 , j=1 , sol =0;
        while(j<N){
            if(colors[j]==colors[j-1]){
                i=j;
                j++;
                continue ;
            }
            if(j-i+1 ==k){
                sol++;
                i++;
            }

            j++;
        }
        return sol;

        
    }
};