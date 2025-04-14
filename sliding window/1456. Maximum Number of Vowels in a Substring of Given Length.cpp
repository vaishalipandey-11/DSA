#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
// check if vowel or not 
 // simple sliding window problem 
     bool isV(char &ch ){
        return ch =='a'|| ch =='e'|| ch == 'i' || ch == 'o' || ch == 'u';
     }
    int maxVowels(string s, int k) {
        int  n = s.length();
        int  i =0 ;
        int j =0;
        int count =0 ;
        int ans =0;
        while(j<n){
            if(isV(s[j])){
                count ++;
            }
            if(j-i+1 == k){
                ans = max(ans , count );
                if(isV(s[i])){
                    count --;
                }
                i++;
            }
            j++;
        }
        return ans ;
    }
};


class Solution {
public:
// check if vowel or not 
 // simple sliding window problem 
   
    int maxVowels(string s, int k) {
        // by using lambda function 
          auto isV= [&](char ch ){
        return ch =='a'|| ch =='e'|| ch == 'i' || ch == 'o' || ch == 'u';
     };
        int  n = s.length();
        int  i =0 ;
        int j =0;
        int count =0 ;
        int ans =0;
        while(j<n){

            if(isV(s[j])){
                count ++;
            }
            if(j-i+1 == k){
                ans = max(ans , count );
                if(isV(s[i])){
                    count --;
                }
                i++;
            }
            j++;
        }
        return ans ;
    }
};