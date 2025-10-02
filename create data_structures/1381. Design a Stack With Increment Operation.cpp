#include <bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    int n;
    vector<int> vec;
    vector<int> lazy;
    CustomStack(int maxSize) {
        n = maxSize;
        vec.resize(n, 0);
        lazy.resize(n, 0);
    }
    int top = -1;
    int count = 0;

    void push(int x) {
        if (count < n) {
            top++;
            vec[top] = x;
            count++;
        }
    }

    int pop() {
        if(count ==0 ) return -1;
        int val = vec[top];
       
        top--;
        count--;
        return val;
    
    }

    void increment(int k, int val) {
        int total = min(k , count);
       for(int i=0  ; i< total ; i++){
        vec[i]  += val;
       }

    }
};
