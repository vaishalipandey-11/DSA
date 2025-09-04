
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int one = abs(z-x);
        int sec = abs(z-y);
        if(one == sec ) return 0;

        return one>sec ? 2 : 1 ;
        
        
    }
};