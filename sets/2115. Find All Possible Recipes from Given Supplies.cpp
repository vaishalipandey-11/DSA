
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        int count = n;
        unordered_set<string> st(supplies.begin(), supplies.end());
        vector<string>result;
        vector<bool>cooked(n, false);

        while(count --){
            for(int i=0 ; i<n ; i++){
                // cooked or not 
                if(cooked[i]) continue ;
                
                bool possible = true ;
                for(int j =0 ; j<ingredients[i].size() ; j++){
                    if(!st.count(ingredients[i][j])){
                        possible = false;
                        break;
                    }
                }
                if(possible){
                    st.insert(recipes[i]);
                    result.push_back(recipes[i]);
                    cooked[i]=true;
                }
            }


        }
        return result;
    }
};