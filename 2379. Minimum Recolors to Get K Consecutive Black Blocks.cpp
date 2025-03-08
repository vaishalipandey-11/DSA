
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//o(n*k)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ops = k;
        int n = blocks.size();
        for(int i =0 ; i<=n-k ; i++ ){
            int w =0 ;
            for(int j =i ; j-i+1 <= k ; j++){
                if(blocks[j]=='W'){
                    w++;
                }
            }
            ops = min(ops,w);
        }
        return ops;
    }
};

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int W = 0, minOps;

        // Count initial 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') W++;
        }
        
        minOps = W; // Store the initial count

        // Slide the window across the string
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') W++;         // Add new character to window
            if (blocks[i - k] == 'W') W--;     // Remove leftmost character from window

            minOps = min(minOps, W); // Update the minimum recolor count
        }

        return minOps;
    }
};
