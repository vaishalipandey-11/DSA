
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int  sumEven =0;
        for(int i=1 ; i<=n*2 ; i++){
            if(i%2==0) sumEven+=i;
            else{
                sumOdd+=i;
            }
        }
        int ans =0;
        
        for(int i=1 ; i<=min(sumOdd, sumEven) ; i++  ){
            if((sumOdd%i==0) && (sumEven%i==0)) {
                ans= i;
            }
        }

        return ans;
    }
};