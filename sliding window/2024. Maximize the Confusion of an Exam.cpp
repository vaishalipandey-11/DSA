#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
   int maxvalue(string answerKey, int k, char ch){
     int n = answerKey.length();
        int i =0 ;
        int j =0;
        int maxi =0;
        int count =0;
        while(j<n){
            count += (answerKey[j]== ch);

            while(count >k){
                count -= (answerKey[i]==ch);
                i++;
            }

            maxi = max(maxi, j-i+1);     
           j++;
        
    }
    return maxi;
    }
   
     
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxvalue(answerKey,k,'T'), maxvalue(answerKey,k,'F'));
    }
       
   
};