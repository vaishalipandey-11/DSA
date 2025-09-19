
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> max_heap;
       if(a>0) max_heap.push({a, 'a'});
        if(b>0)max_heap.push({b, 'b'});
        if(c>0)max_heap.push({c, 'c'});

        string result = "";
        while (!max_heap.empty()) {

            auto [cnt1, ch1] = max_heap.top();
            max_heap.pop();

            int n = result.size();

            if(n>=2 && result[result.size()-1] == ch1 && result[result.size()-2] == ch1 ){// last 2 char  check || size n>2
            // agr edhr heap is empty toh .. 
            if(max_heap.empty()) break;
            // next walo ko daal do na 
            auto [cnt2 , ch2] = max_heap.top(); max_heap.pop();
            result+=ch2;
            cnt2--;

            if(cnt2 >0){
                max_heap.push({cnt2, ch2});
            }

            max_heap.push({cnt1 , ch1});

            }else{
                result+= ch1;
                cnt1--;
                if(cnt1>0){
                    max_heap.push({cnt1 , ch1});
                }

            }
               
            }
        
        return result;
    }
};
