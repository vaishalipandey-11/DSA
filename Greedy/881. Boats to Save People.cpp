#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n =people.size();
        int i=0; int j =n-1;
        sort(people.begin(),  people.end());
        int boat =0;

        while(i<=j){
            if(people[i]+people[j]<= limit ){
                i++;
                j--;
            }else{
                j--;
            }
            boat++;
        }
        return boat ;
        
    }
};