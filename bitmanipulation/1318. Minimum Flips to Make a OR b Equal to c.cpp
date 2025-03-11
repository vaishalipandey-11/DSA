#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int minFlips(int &a, int &b, int &c) {
        int flips =0;
        
        while(a!=0 || b!=0 || c!=0){// bcz at the end sb 0 pe aayenge .. 

            int A = a&1;
            int B = b&1;
            int C = c&1;

            if(C==1){                        // last bit is 1 
                if((A==0) && (B==0)){
                    flips++;
                    } 
            }else{                                 // last bit is 0
                if(A==1) flips++;
                if(B==1) flips++;
            }
             
             // shift all the numbers by 1 bit
             a >>= 1;
             b >>= 1;
             c >>= 1;
         
        }
        return flips;
    }
};