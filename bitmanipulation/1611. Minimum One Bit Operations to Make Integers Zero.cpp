
 #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;
    class Solution {
public:
// its an example of gray code 
    int minimumOneBitOperations(int n) {
      int count =0;
      while(n!=0){
        count = count^n; // xor up to 0
        n>>=1; // right shift ..
      }  
      return count;
    }
};