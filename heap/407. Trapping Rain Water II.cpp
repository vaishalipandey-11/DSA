
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
typedef pair<int, pair<int, int>> pp;
   vector<vector<int>> dir = {{1,0}, {0,1}, {0 , -1} ,{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<pp, vector<pp> , greater<pp>> boundarycells;
        vector<vector<bool>> visited(n , vector<bool>(m , false));

        for(int r=0 ;r< n ; r++){
            for(auto c : {0 , m-1}){
                boundarycells.push({heightMap[r][c] , {r,c}});
                visited[r][c]= true;
            }
        }
        for(int c=0 ;c< m ; c++){
            for(auto r : {0 , n-1}){
                boundarycells.push({heightMap[r][c] , {r,c}});
                visited[r][c]= true;
            }
        }

         int  trappedwater =0;
        while(!boundarycells.empty()){
            auto [height , idx ] = boundarycells.top() ; boundarycells.pop();
            int  i = idx.first;
            int j = idx.second;

            for(auto &it : dir){
                int i_ = i + it[0];
                int j_ = j + it[1];

                if( i_>= 0 && i_ <n && j_ <m && j_ >=0 && visited[i_][j_] != true ){
                   trappedwater += max(0 , height - heightMap[i_][j_]);
                   boundarycells.push({max(height , heightMap[i_][j_]), {i_,j_}}) ;
                   visited[i_][j_]= true;
                }

            }
        }
        return trappedwater;
    }
};