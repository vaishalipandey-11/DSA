#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int width = n-1 , i=0 , j=n-1 , maxarea = 0,area =0;
        
        while(i<j){
            if(height[i]<=height[j]){
                area = height[i]*width;
                i++;
                width--;
            }else{
                area = height[j]*width;
                j--;
                width--;
            }
            maxarea = max(area , maxarea);
        }
        return maxarea;
        
    }
};