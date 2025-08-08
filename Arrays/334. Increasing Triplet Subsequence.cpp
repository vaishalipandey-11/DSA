#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int n= nums.size();
        int first = INT_MAX;
        int second = INT_MAX;

        for(auto &num :nums){
            if(num<=first) first=num; // assign smallest to first 
            else if(num<=second) second=num; // then check next smallest for sec
            else return true;               //agr yaha tk aa gaye h mtlv ek or bada mil gaya h return true
        }

        return false; //vrna nhi mila f

        }
};