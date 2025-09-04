 #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;
    
class Solution {
public:
    bool makeStringsEqual(string s, string t) {
      bool a = s.find('1') != string::npos;
      bool b = t.find('1') != string :: npos;
       return a==b;  
    }
};