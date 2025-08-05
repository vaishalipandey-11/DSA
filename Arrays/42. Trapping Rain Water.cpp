#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>getleftmax(vector<int>& height, int n ){
        vector<int>leftmax(n);//filled with 0
        leftmax[0]=height[0]; //fill 1st one 
        for(int i =1; i<n ;i++){ // else by looking at height and leftmax 
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        return leftmax;
    }
    vector<int>getrightmax(vector<int>&height , int n){
        vector<int>rightmax(n);
        rightmax[n-1]=height[n-1];
        for(int i =n-2 ; i>=0 ; i-- ){
            rightmax[i] = max(rightmax[i+1], height[i]);
        }
        return rightmax;

    }
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==1 || n==0 )return 0;
        int water =0;
        vector<int>leftmax = getleftmax(height,n);
        vector<int>rightmax =getrightmax(height,n);
        for(int i =0 ; i<n ; i++){
            water +=min(leftmax[i],rightmax[i])-height[i];
        }
        return water;
    }
};