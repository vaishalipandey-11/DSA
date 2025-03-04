#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(int i=16 ; i>=0 ; i--){
            int power = pow(3,i);
            if(power <= n) n-=power ;
            if(n==0) return true;
        }
        return false;
    }
};