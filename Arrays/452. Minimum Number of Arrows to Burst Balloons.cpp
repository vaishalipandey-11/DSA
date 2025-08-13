
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n= points.size();
        sort(points.begin(), points.end());

       
        int prevstart = points[0][0];
        int prevend= points[0][1];

        int count =1;
        for(int i=1 ; i<n ; i++){
            int currstart = points[i][0];
            int currend = points[i][1];

            if(prevend < currstart ){// no overlap
              count++;
              prevstart =currstart;
              prevend =currend;
            }else{//overlapping 
             prevstart=max(prevstart,currstart);
             prevend=min(prevend,currend);

            }

        }
        return count ;
        
    }
};