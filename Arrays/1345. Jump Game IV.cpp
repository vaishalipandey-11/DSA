
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<int>vis(n+1 , false);//to store idx
        queue<int>que; //for index
        que.push(0);
        vis[0] =true;

        int steps =0;
        while(!que.empty()){
            int size = que.size();
            while(size--){
                int i=que.front(); que.pop(); 
                if(i==n-1) return steps;
                // one idx left 
                if(i-1>=0 && !vis[i-1]){
                    que.push(i-1);
                    vis[i-1]=true;
                }
                //one idx right
                if(i+1 <=n-1 && !vis[i+1]){
                    que.push(i+1);
                    vis[i+1]=true;
                }
                //same value on the mp
                for(int &it :mp[arr[i]]){
                    if(!vis[it]){
                        que.push(it);
                        vis[it]=true;
                    }
                }
                mp[arr[i]].clear();
            }
            steps++;
        }
        return -1;
    }
};