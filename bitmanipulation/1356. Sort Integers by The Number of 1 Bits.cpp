
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int &a , int &b ){
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);

            if(count_a == count_b){
                return a < b;
            }

            return count_a  < count_b ;

        };
        sort(arr.begin(), arr.end(), lambda);
        return arr;
    }
};

class Solution {
public:
        int countones(int num){
            int count =0;
           while(num){
            count += num&1;
            num >>= 1;
           }
           return count ;
           
        }
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int &a , int &b ){
            int count_a = countones(a);
            int count_b = countones(b);

            if(count_a == count_b){
                return a < b;
            }

            return count_a  < count_b ;

        };
        sort(arr.begin(), arr.end(), lambda);
        return arr;
    }
};